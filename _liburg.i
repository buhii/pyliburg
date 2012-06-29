/*

*/

%module pyliburg
%include exception.i

%{
  #include <Python.h>
%}

%typemap(out) int *
{
  $result = PyTuple_New(DETECTOR_TUPLE_LENGTH);
  for (int i = 0; i < DETECTOR_TUPLE_LENGTH; i++) {
    PyObject *o = PyInt_FromLong( $1[i] );
    PyTuple_SetItem($result, i, o);
  }
}


%{
  #include "urg_wrapper.hpp"
%}

%include "urg_wrapper.hpp"
