#ifndef __STACK_H__
#define __STACK_H__

#include "base.h"
#include "link_list.h"

class stack
{
public:
  ll_list list;
  void push(ulong value)
  {
    list.insert_tail(value);
  }
  ulong pop()
  {
    list.delete_tail();
  }
  ulong peek()
  {
    return list.tail->value;
  }
  size_t elements()
  {
    return list.elements;
  }
};

#endif // __STACK_H__