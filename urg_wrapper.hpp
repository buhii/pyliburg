/* urg_wrapper.hpp */
#include "urg_ctrl.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#ifndef URG_WRAPPER_HPP
#define URG_WRAPPER_HPP

#define MEASURE_DATA_LENGTH 512

// --------------------------------------------------------------------------
// Thin wrapper to learn and detect
// --------------------------------------------------------------------------
class urg_wrapper
{
 public:
  urg_wrapper(void);
  urg_wrapper(const char * device);
  ~urg_wrapper(void);

  long minDistance(void);
  long maxDistance(void);
  int scanMsec(void);

  double index2deg(const int index);
  int deg2index(const int deg);

  long * capture(void);

  urg_t urg;
  urg_parameter_t parameter;
  long distances[MEASURE_DATA_LENGTH];
  int first_index;
  int last_index;
};

#endif // URG_WRAPPER_HPP
