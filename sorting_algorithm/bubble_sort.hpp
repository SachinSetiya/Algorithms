#ifndef __BUBBLE_SORT_H__
#define __BUBBLE_SORT_H__
#include "../include/base.h"
#include "../include/random_generator.h"

namespace bubble_sort
{
  void sort(random_array *arr)
  {
    ulong *array= arr->array;
    ulong length= arr->count;
    for (size_t i = 0; i < length; i++)
    {
      for (size_t j = 1; j < length - i; j++)
      {
        if (array[j] < array[j-1])
          swap(array+j, array+j-1);
      }
      
    }
    
  }
  
} // namespace bubble_sort


#endif // __BUBBLE_SORT_H__