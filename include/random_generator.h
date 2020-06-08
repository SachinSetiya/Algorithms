#ifndef __RANDOM_GENERATOR_H__
#define __RANDOM_GENERATOR_H__
#include "base.h"
#include <string.h>

struct random_array
{
  ulong *array, upper_bound, lower_bound;
  size_t count;
  enum sorted_order
  {
    INCRESING,
    DECRESING
  };
  void print()
  {
    printf("\nPrinting Random Array Size= %lu Upper bound= %lu Lower Bound= %lu\n",
                         count, upper_bound,lower_bound);
    for (size_t i = 0; i < count; i++)
      printf("%lu \n", array[i]);
  }
  random_array(){}
  random_array (size_t size, ulong upper_bound, long lower_bound, uint seed=0)
  {
    this->array= static_cast<ulong *>(malloc(sizeof(ulong) * size));
    this->upper_bound= upper_bound;
    this->lower_bound= lower_bound;
    if (!seed)
      srand(seed);
    else
    {
      srand(time(nullptr));
    }
   
    this->count= size;
    for (size_t i = 0; i < size; i++)
      array[i]= lower_bound + ((ulong)rand() * (upper_bound - lower_bound))/RAND_MAX;
  }
  random_array (size_t size)
  {
    this->array= static_cast<ulong *>(malloc(sizeof(ulong) * size));
    this->count= size;
  }
  ~random_array()
  {
    free(array);
  }
  void operator delete(void* data)
  {
    random_array *tmp= static_cast<random_array *>(data);
    free(tmp->array);
    free(tmp);
  }
  void free_data()
  {
    free(array);
    free(this); //NOt Sure About this
  }
  bool is_sorted(sorted_order order= INCRESING)
  {
    if (order == INCRESING)
    {
      for (size_t i = 1; i < count; i++)
      {
        if (array[i - 1] > array[i])
          return false;
      }
    }
    else
    {
      for (size_t i = 1; i < count; i++)
      {
        if (array[i - 1] < array[i])
          return false;
      }
    }
    return true;
  }
  bool is_sorted_print(sorted_order order= INCRESING)
  {
    bool sorted= is_sorted(order);
    if (sorted)
    {
      printf("\nArray is Sorted\n");
    }
    else
    {
      printf("Array is NOT Sorted");
    }
    
    
  }
  random_array *make_copy()
  {
    random_array *tmp= new random_array();
    tmp->array= static_cast<ulong *>(malloc(sizeof(ulong) * this->count));
    tmp->count= this->count;
    tmp->upper_bound= upper_bound;
    tmp->lower_bound= lower_bound;
    memcpy(tmp->array, this->array, sizeof(ulong) * this->count );
    return tmp;
  }
  random_array *make_empty_copy()
  {
    random_array *tmp= new random_array();
    tmp->array= static_cast<ulong *>(malloc(sizeof(ulong) * this->count));
    tmp->count= this->count;
    return tmp;
  }
};


#endif // __RANDOM_GENERATOR_H__