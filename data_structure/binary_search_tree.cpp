#include <stdio.h>
#include "../include/random_generator.h"
#include "../include/measure_time.h"


class binary_tree
{
public:
enum operation_type{
  RECURSIVE,
  ITERATIVE
};
  struct node
  {
   struct node * left_child;
   struct node * right_child;
   ulong value;
  };
  binary_tree()
  {
    root= nullptr;
  }
  node *root;
  
  node *create(ulong value)
  {
    node *tmp= static_cast<node *> (malloc(sizeof(node))); 
    tmp->value= value;
    tmp->left_child= tmp->right_child= nullptr;
    return tmp;
  }

  node *insert_internal_recursive(node *root , ulong value)
  {
    if (!root)
      return create(value);
    if (root->value < value)
      root->right_child= insert_internal_recursive(root->right_child, value);
    else
      root->left_child= insert_internal_recursive(root->left_child, value);
    return root;
  }

  void insert(ulong num)
  {
    if (!root)
      root= insert_internal_recursive(root, num);
    else
      insert_internal_recursive(root, num);
  }

  void preorder_transversal(node *node)
  {
    if (!node)
      return;
    printf("%lu\n", node->value);
    preorder_transversal(node->left_child);
    preorder_transversal(node->right_child);
  }
  void inorder_transversal(node *node)
  {
    if (!node)
      return;
    inorder_transversal(node->left_child);
    printf("%lu\n", node->value);
    inorder_transversal(node->right_child);
  }
  void postorder_transversal(node *node)
  {
    if (!node)
      return;
    postorder_transversal(node->left_child);
    postorder_transversal(node->right_child);
    printf("%lu\n", node->value);
  }
  void print()
  {

  }
  int _max_height(node *node)
  {
    if(!node)
      return 0;
    int left_height, right_height;
    left_height= 1 + _max_height(node->left_child);
    right_height= 1 +_max_height(node->right_child);
    if (left_height > right_height)
    {
      return left_height;
    }
    else
    {
      return right_height;
    }
    
  }
  int max_height()
  {
    int max_height= _max_height(root);
    printf("Height %d\n", max_height);
    return max_height;
  }
  void bulk_insert(random_array *arr)
  {
    for (size_t i=0; i < arr->count; i++)
      insert(arr->array[i]);
  }
  void free_tree()
  {
   _free_tree(root); 
  }
  void _free_tree(node *node)
  {
    if (!node)
      return;
    _free_tree(node->left_child);
    node->left_child= nullptr;
    _free_tree(node->right_child);
    node->right_child= nullptr;
    free(node);
    node= nullptr;
  }
};
int main()
{
  binary_tree btree;
  time_measure clk;
  clk.start();
  btree.bulk_insert(new random_array(2000000, 109909, 1));
  /*
  printf("PreOrder\n");
  btree.preorder_transversal(btree.root);
  printf("PostOrder\n");
  btree.postorder_transversal(btree.root);
  printf("InOrder\n");
  btree.inorder_transversal(btree.root);
  btree.max_height();
//  btree.free_tree();
  btree.max_height();
  */
  clk.done();
}
