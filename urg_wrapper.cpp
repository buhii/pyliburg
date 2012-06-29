/* urg_wrapper.cpp */
#include "urg_ctrl.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "urg_wrapper.hpp"
#include <iostream>

using namespace std;

urg_wrapper::urg_wrapper(void)
{
  urg_initialize(&urg);
}

urg_wrapper::urg_wrapper(const char * device)
{
  int ret;
  urg_initialize(&urg);
  ret = urg_connect(&urg, device, 115200);
  if (ret < 0) {
    cout << "can't connect '" << device << "'!\n";
  } else {
    urg_parameters(&urg, &parameter);
    first_index = parameter.area_front_ - MEASURE_DATA_LENGTH / 2;
    last_index = first_index + MEASURE_DATA_LENGTH - 1;
  }
}

urg_wrapper::~urg_wrapper(void)
{
  urg_disconnect(&urg);
}

long urg_wrapper::minDistance(void)
{
  return urg_minDistance(&urg);
}

long urg_wrapper::maxDistance(void)
{
  return urg_maxDistance(&urg);
}

int urg_wrapper::scanMsec(void)
{
  return urg_scanMsec(&urg);
}

double urg_wrapper::index2deg(const int index)
{
  return urg_index2deg(&urg, index);
}

int urg_wrapper::deg2index(const int deg)
{
  return urg_deg2index(&urg, deg);
}

long * urg_wrapper::capture(void)
{
  /* Get only front data */
  int ret, n;
  ret = urg_requestData(&urg, URG_GD, first_index, last_index);
  if (ret < 0) {
    cout << "can't request data!\n";
  }

  /* Reception */
  n = urg_receivePartialData(&urg, distances, MEASURE_DATA_LENGTH, first_index, last_index);
  if (n < 0) {
    cout << "can't receive partial data!\n";
  }
  return distances;
}
