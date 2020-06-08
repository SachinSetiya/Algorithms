#ifndef __BASE_H__
#define __BASE_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define uint unsigned int
#define ulong unsigned long 
inline void swap(ulong *a, ulong *b)
{
  ulong temp;
  temp= *a;
  *a= *b;
  *b= temp;
}


#endif // __BASE_H__
