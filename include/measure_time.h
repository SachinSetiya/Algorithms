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
    time_t diff_milisec= ((clock() - start_time)*1000)/CLOCKS_PER_SEC;
    printf("Elasped time(in Mili Seconds) = %lu, in Seconds = %f", diff_milisec, (double)diff_milisec/1000);
  }
};

#endif // __MEASURE_TIME_H__