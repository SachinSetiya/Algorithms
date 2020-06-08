#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__

#include "../include/base.h"
#include "../include/random_generator.h"

namespace merge_sort
{
  void merge(ulong *array, ulong *result, ulong start, ulong mid_point, ulong end);
  void partition(ulong *array, ulong *result, ulong start, ulong end);
  random_array * sort(random_array *arr)
  {
    random_array *dup_array= arr->make_empty_copy();
    partition(arr->array, dup_array->array, 0, arr->count);
  }
  void partition(ulong *array, ulong *tmp, ulong start, ulong end)
  {
    if(start <  end)
    {
      ulong mid_point= ( start + end )/2;
      partition(array, tmp, start, mid_point);
      partition(array, tmp, mid_point + 1, end);
      merge(array, tmp, start, mid_point, end);
    }
  }
  void merge(ulong *array, ulong *tmp, ulong start, ulong mid_point, ulong end)
  {
    ulong i= start, j= mid_point + 1, k= start;
    memcpy(tmp+start, array+start, (end - start)*sizeof(ulong));
    while (i <= mid_point && j <= end)
    {
      if (tmp[i] < tmp[j])
      {
        array[k]= tmp[i];
        i++;
      }
      else
      {
        array[k]= tmp[j];
        j++;
      }
      k++;
    }
    while(i <= mid_point)
    {
      array[k]= tmp[i];
      k++;
      i++;
    }
    while(j <= end)
    {
      array[k]= tmp[j];
      k++;
      j++;
    }
  }
}

#endif // __MERGE_SORT_H__