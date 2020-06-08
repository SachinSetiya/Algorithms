#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

#include "base.h"
#include "random_generator.h"

/*
  Doubly Link List
*/

struct ll_node
{
  ulong value;
  ll_node *next;
  ll_node *prev;
};

class ll_list
{
public:
  ll_node *head, *tail;
  size_t elements;
  const int EMPTY_LIST= 1;
  ll_list()
  {
    head= tail = nullptr;
  }
  ll_node *create_ll_node(ulong value)
  {
    ll_node *tmp= static_cast<ll_node *>(malloc(sizeof(ll_node)));
    tmp->next= tmp->prev= nullptr;
    tmp->value= value;
    return tmp;
  }
  void insert_tail(ulong value)
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
  ulong delete_head(int *is_error= nullptr)
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
    ll_node *old_head= head;
    ulong value= old_head->value;
    head= head->next;
    free(old_head);
    elements--;
    return value;  
  }
  ulong delete_tail(int *is_error= nullptr)
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
    ll_node *old_tail= tail;
    ulong value= old_tail->value;
    tail= tail->prev;
    free(old_tail);
    elements--;
    return value;  
  }
  void print()
  {
    ll_node *tmp= head;
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