/*

*/

%module pyliburg
%include exception.i

%{
  #include <Python.h>
  #include "urg_wrapper.hpp"
%}

%typemap(out) long *
{
  $result = PyTuple_New(MEASURE_DATA_LENGTH);
  for (int i = 0; i < MEASURE_DATA_LENGTH; i++) {
    PyObject *o = PyInt_FromLong( $1[i] );
    PyTuple_SetItem($result, i, o);
  }
}

%include "urg_wrapper.hpp"
