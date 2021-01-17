#include "../include/base.h"
#include "../include/random_generator.h"
#include "insertion_sort.hpp"
#include "bubble_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"
#include "../include/measure_time.h"
/*
*  Time taken by different algorithm to sort
*/
int main(int argc, const char** argv)
{
  time_measure clck;
  random_array *arr1;
  /*
  *   Insertion Sort of 50000 numbers (1 million is taking too much time)
  *   with sort check
  */
  arr1= new random_array(50000, 100000000, 99);
  clck.start();
//  insertion_sort::sort(arr1);
  arr1->is_sorted_print();
  clck.done();
//  delete arr1;
  //////////////////////////////////////////////

  /*
  *  Bubble Sort
  * 
  */
  arr1= new random_array(50000, 100000000, 99);
  clck.start();
//  bubble_sort::sort(arr1);
  arr1->is_sorted_print();
  clck.done();
//  delete arr1;
  ///////////////////////////////////////////////

  /*
  *  Merge Sort
  * 
  */
  arr1= new random_array(50000, 100000000, 99);
  clck.start();
//  merge_sort::sort(arr1);
  arr1->is_sorted_print();
  clck.done();
//  delete arr1;
  ///////////////////////////////////////////////


  /*
  *  Quick Sort
  * 
  */
  arr1= new random_array(5,10);
  clck.start();
  arr1->print();
  quick_sort::sort(arr1);
  arr1->print();
  arr1->is_sorted_print();
  clck.done();
//  delete arr1;
  ///////////////////////////////////////////////
}