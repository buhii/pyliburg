/* _liburg.c */
#include "Python.h"

#include "urg_ctrl.h"
#include "detect_os.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


static void urg_exit(urg_t *urg, const char *message)
{
  printf("%s: %s\n", message, urg_error(urg));
  urg_disconnect(urg);
}


static void printData(urg_t *urg, urg_parameter_t *parameter, long data[])
{
  /* Display front distance data along with timestamp */
  /* If data cannot be acquired with in some constant period of time,
     then timestamp is diplayed as -1 */
  long timestamp = urg_recentTimestamp(urg);

  /* Invalid value is displayed if distance data is less than
     urg_minDistance() */
  printf("%d: %ld [mm], %ld [msec]\n",
         parameter->area_front_, data[parameter->area_front_], timestamp);
}


/* main */
static PyObject *
test_urg(PyObject *self, PyObject *args)
{
  enum {
    CaptureTimes = 10,
  };

  const char device[] = "/dev/tty.usbmodemfd111";   /* test */

  int data_max;
  long* data;
  urg_parameter_t parameter;
  int ret;
  int n;
  int i;

  /* Connection */
  urg_t urg;
  urg_initialize(&urg);
  ret = urg_connect(&urg, device, 115200);
  if (ret < 0) {
    urg_exit(&urg, "urg_connect()");
  }

  /* Request for Data using GD */
  data_max = urg_dataMax(&urg);
  data = (long*)malloc(sizeof(long) * data_max);
  if (data == NULL) {
    perror("data buffer");
  }
  urg_parameters(&urg, &parameter);

  /* Request for Data using GD */
  printf("GD capture\n");
  for (i = 0; i < CaptureTimes; ++i) {
    /* Request for data */
    ret = urg_requestData(&urg, URG_GD, URG_FIRST, URG_LAST);
    if (ret < 0) {
      urg_exit(&urg, "urg_requestData()");
    }

    /* Reception */
    n = urg_receiveData(&urg, data, data_max);
    if (n < 0) {
      urg_exit(&urg, "urg_receiveData()");
    }

    /* Display */
    printData(&urg, &parameter, data);
  }
  printf("\n");


  /* Request for Data using MD */
  printf("MD capture\n");

  /* set data acquisition frequency equal to infinity, to get the data more
     than 100 times */
  /* urg_setCaptureTimes(&urg, UrgInfinityTimes); */
  assert(CaptureTimes < 100);
  urg_setCaptureTimes(&urg, CaptureTimes);

  /* Request for data */
  ret = urg_requestData(&urg, URG_MD, URG_FIRST, URG_LAST);
  if (ret < 0) {
    urg_exit(&urg, "urg_requestData()");
  }

  for (i = 0; i < CaptureTimes; ++i) {
    /* Reception */
    n = urg_receiveData(&urg, data, data_max);
    if (n < 0) {
      urg_exit(&urg, "urg_receiveData()");
    }

    /* Display */
    printData(&urg, &parameter, data);
  }

  urg_disconnect(&urg);
  free(data);

  Py_INCREF(Py_None);
  return Py_None;
}


static PyMethodDef UrgMethods[] = {
  {"test_urg", test_urg, METH_VARARGS,
   "test urg sensor"},
  {NULL, NULL, 0, NULL}
};


PyMODINIT_FUNC
init_liburg(void)
{
  (void) Py_InitModule("_liburg", UrgMethods);
}
