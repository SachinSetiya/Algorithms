#include <stdio.h>
#include "../include/random_generator.h"
int main()
{
  random_array *r_arr= get_random_no_array(25, 176, 1);
  r_arr->print();
  r_arr->free_data();
}