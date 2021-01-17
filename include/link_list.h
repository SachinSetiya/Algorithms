#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

#include "base.h"
#include "random_generator.h"

/*
  Doubly Link List
*/

template <typename T>
class ll_node
{
  T *data;
  ll_node *next;
  ll_node *prev;
};

template <typename T>
class ll_list
{
public:
  ll_node<T> *head, *tail;
  size_t elements;
  const int EMPTY_LIST= 1;
  ll_list()
  {
    head= tail = nullptr;
  }
  ll_node<T> *create_ll_node(T* value)
  {
    ll_node<T> *tmp= static_cast<ll_node<T> *>(malloc(sizeof(ll_node<T>)));
    tmp->next= tmp->prev= nullptr;
    tmp->value= value;
    return tmp;
  }
  void insert_tail(T* value)
  {
    if (!head)
      head= tail= create_ll_node(value);
    else
    {
      tail->next= create_ll_node(value);
      tail->next->prev= tail;
      tail= tail->next;
    }
    elements++;
  }
  void insert_head(ulong value)
  {
    if (!head)
      head= tail= create_ll_node(value);
    else
    {
      head->prev= create_ll_node(value);
      head->prev->next= head;
      head= head->prev;
    }
    elements++;
  }
  T delete_head(int *is_error= nullptr)
  {
    if (!elements)
    {
      if (is_error)
      {
        *is_error= EMPTY_LIST;
      }
      return 0;
    }
    if (head == tail)
      tail= nullptr;
    ll_node<T> *old_head= head;
    T value= old_head->value;
    head= head->next;
    free(old_head);
    elements--;
    return value;
  }
  T delete_tail(int *is_error= nullptr)
  {
    if (!elements)
    {
      if (is_error)
      {
        *is_error= EMPTY_LIST;
      }
      return 0;
    }
    if (tail == head)
      head= nullptr;
    ll_node<T> *old_tail= tail;
    T value= old_tail->value;
    tail= tail->prev;
    free(old_tail);
    elements--;
    return value;
  }
  void print()
  {
    ll_node<T> *tmp= head;
    while(tmp)
    {
      printf("%lu \n", tmp->value);
      tmp= tmp->next;
    }
  }
  void bulk_insert(random_array *r_arr)
  {
    for (size_t i = 0; i < r_arr->count; i++)
    {
      insert_tail(r_arr->array[i]);
    }
  }
};


#endif // __LINK_LIST_H__
