#ifndef __STACK_H__
#define __STACK_H__

#include "base.h"
#include "link_list.h"

template <typename T>
class stack
{
public:
  stack<T>()
  {

  };
  ll_list<T> list;
  void push(T* value)
  {
    list.insert_tail(value);
  }
  T* pop()
  {
    return list.delete_tail();
  }
  T* peek()
  {
    return list.tail->value;
  }
  size_t elements()
  {
    return list.elements;
  }
};

#endif // __STACK_H__
