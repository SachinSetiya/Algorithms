#ifndef __RANDOM_GENERATOR_H__
#define __RANDOM_GENERATOR_H__
#include "base.h"

struct random_array
{
  ulong *array;
  size_t count;
  void free_data()
  {
    free(array);
    free(this); //NOt Sure About this
  }
  void print()
  {
    for (size_t i = 0; i < count; i++)
      printf("%lu \n", array[i]);
  }
  random_array(){}
  random_array (size_t size, ulong upper_bound, long lower_bound, uint seed=0)
  {
    ulong *t_array= static_cast<ulong *>(malloc(sizeof(ulong) * size));
    if (!seed)
      srand(seed);
    else
    {
      srand(time(nullptr));
    }
   
    this->array= t_array;
    this->count= size;
    for (size_t i = 0; i < size; i++)
      array[i]= lower_bound + ((ulong)rand() * (upper_bound - lower_bound))/RAND_MAX;
  }
  ~random_array()
  {
    free(array);
  }
};


#endif // __RANDOM_GENERATOR_H__