#ifndef SIMPLE_TREE_H
#define SIMPLE_TREE_H
#include <stdlib.h>

typedef struct Node{
  char id;
  struct Node *parent;
  struct Node *children;
  size_t size;
  size_t current_capacity;
} Node;

typedef struct{
  Node node;
  size_t size;
} SimpleTree;

void push_node(Node *parent, Node node_to_push);
void init_node(Node *node, Node *parent, char id);
void init_tree(SimpleTree *tree, char id);
void print_tree(SimpleTree *tree, int order);

#endif SIMPLE_TREE_H
