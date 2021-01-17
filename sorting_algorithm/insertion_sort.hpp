#include "../include/base.h"
#include "../include/random_generator.h"
/*
  Sort using insertion sort
*/
namespace insertion_sort
{
  void sort(random_array *arr)
  {
    long j, k, temp, element;
    for (size_t i = 1; i < arr->count; i++)
    {
      element= arr->array[i];
      j= i-1;
      temp= arr->array[j];
      while (temp > element && j >= 0)
      {
        arr->array[j+1]= arr->array[j];
        j--;
        temp= arr->array[j];
      }
      arr->array[j+1]= element;
    }
  }
}