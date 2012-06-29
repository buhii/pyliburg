/* urg_wrapper.hpp */
#include "urg_ctrl.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#ifndef URG_WRAPPER_HPP
#define URG_WRAPPER_HPP

#define MEASURE_DATA_LENGTH 1024

// --------------------------------------------------------------------------
// Thin wrapper to learn and detect
// --------------------------------------------------------------------------
class urg_wrapper
{
 public:
  urg_wrapper(void);
  urg_wrapper(const char * serial, int begin_index, int end_index);
  ~urg_wrapper(void);

  long min_distance(void);
  long max_distance(void);

  double index2rad(const int index);
  int rad2index(const double radian);

  long * capture(void);

  urg_t urg;
  long distances[MEASURE_DATA_LENGTH];
};

#endif // URG_WRAPPER_HPP
