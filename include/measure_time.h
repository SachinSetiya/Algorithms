#ifndef __MEASURE_TIME_H__
#define __MEASURE_TIME_H__
#include "base.h"
#include <stdio.h>
class time_measure
{
public:
  time_t start_time;
  time_measure()
  {
    start_time= 0;
  }
  void start()
  {
    start_time= clock();
  }
  void done()
  {
    time_t diff_milisec= (clock() - start_time)/(CLOCKS_PER_SEC/3600);
    printf("Elasped time(in Mili Seconds) = %lu", diff_milisec);
  }
};

#endif // __MEASURE_TIME_H__