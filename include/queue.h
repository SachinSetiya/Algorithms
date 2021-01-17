#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "base.h"
#include "link_list.h"

template <typename T>
class queue
{
public:
  ll_list<T> list;
  void push(T value)
  {
    list.insert_tail(value);
  }
  T pop()
  {
    return list.delete_head();
  }
  T peek()
  {
    return list.head->value;
  }
  size_t elements()
  {
    return list.elements;
  }
};

#endif // __QUEUE_H__
