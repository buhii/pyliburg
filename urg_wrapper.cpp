/* urg_wrapper.cpp */
#include "urg_ctrl.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "urg_wrapper.hpp"

using namespace std;

urg_wrapper::urg_wrapper(void)
{
}

urg_wrapper::urg_wrapper(const char * serial, int begin_index, int end_index)
{

}

urg_wrapper::~urg_wrapper(void)
{
}

long urg_wrapper::min_distance(void)
{

}

long urg_wrapper::max_distance(void)
{

}

double urg_wrapper::index2rad(const int index)
{
}

int urg_wrapper::rad2index(const double radian)
{
}

long * urg_wrapper::capture(void)
{
  /*
  int i;
  for (i = 0; i < 8; i++) {
    result[i] = 0;
  }
  detector->detect(input_image);

  if (detector->pattern_is_detected) {
    result[0] = detector->detected_u_corner[0];
    result[1] = detector->detected_v_corner[0];
    result[2] = detector->detected_u_corner[1];
    result[3] = detector->detected_v_corner[1];
    result[4] = detector->detected_u_corner[2];
    result[5] = detector->detected_v_corner[2];
    result[6] = detector->detected_u_corner[3];
    result[7] = detector->detected_v_corner[3];
    cout << "[wrapper] pt1: " << result[0] << "," << result[1] << endl;
    cout << "[wrapper] pt2: " << result[2] << "," << result[3] << endl;
    cout << "[wrapper] pt3: " << result[4] << "," << result[5] << endl;
    cout << "[wrapper] pt4: " << result[6] << "," << result[7] << endl;
  }
  return result;
  */
}
