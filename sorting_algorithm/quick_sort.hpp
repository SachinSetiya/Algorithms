
#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__
#include "../include/base.h"
#include "../include/random_generator.h"

namespace quick_sort
{
  void quick_sort(ulong *array, ulong low, ulong high);
  ulong partition(ulong *array, ulong low, ulong high);
  void sort(random_array *arr)
  {
     quick_sort(arr->array, 0, arr->count - 1);
  }

  void quick_sort(ulong *array, ulong low, ulong high)
  {
    if (low  < high)
    {
      ulong pi= partition(array, low, high);
      quick_sort(array, low, pi);
      quick_sort(array, pi+1, high);
    }
  }
  ulong partition(ulong array[], ulong low, ulong high)
  {
    ulong part= array[high];
    ulong left= low, right= high -1;
    while(left < right)
    {
      while (left < right && array[left] < part)
        left++;
      while (right > left && array[right] > part)
        right--;
      if (left < right)
      {
        swap(array+left, array+right);
        left++;
        right--;
      }
    }
    swap(array + right, array + high);
    return right;
  }
  
    
} // namespace quick_sort


#endif // __QUICK_SORT_H__