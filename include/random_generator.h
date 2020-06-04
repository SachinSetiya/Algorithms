#ifndef _RANDOM_GENERATOR_H
#define _RANDOM_GENERATOR_H
#include <stdio.h>
#include <stdlib.h>

#define uint unsigned int
#define ulong unsigned long 


struct random_array
{
  ulong *array;
  uint size;
  void free_data()
  {
    free(array);
    free(this); //NOt Sure About this
  }
  void print()
  {
    for (size_t i = 0; i < size; i++)
      printf("%lu \n", array[i]);
  }
};

random_array *get_random_no_array(size_t size, ulong upper_bound, long lower_bound, uint seed=0)
{
  random_array *r_array= (random_array *)malloc(sizeof(random_array));
  ulong *array= (ulong *) malloc(sizeof(ulong) * size);
  if (!seed)
    srand(seed);
  r_array->array= array;
  r_array->size= size;
  for (size_t i = 0; i < size; i++)
    array[i]= lower_bound + (rand() * (upper_bound - lower_bound))/RAND_MAX;
  return r_array;
}
#endif //_RANDOM_GENERATOR_H