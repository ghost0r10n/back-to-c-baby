#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <stdlib.h>

typedef int(Rule)(int parent_id, int child_id);

typedef struct BinaryNode{
  int id;
  struct BinaryNode *parent;
  struct BinaryNode *right;
  struct BinaryNode *left;
  int height;
  int balance_factor;
} BinaryNode;

typedef struct{
  BinaryNode node;
} BinaryTree;

void binary_push_node(BinaryNode *parent, BinaryNode *node_to_push, Rule rule);
void binary_init_node(BinaryNode *node, int id);
void binary_init_tree(BinaryTree *tree, int id);
void binary_print_tree(BinaryTree *tree, int order);

//BST functions
BinaryNode* find_node(BinaryNode *node, int value);
BinaryNode* min(BinaryNode *node);
BinaryNode* max(BinaryNode *node);
void delete_node(BinaryNode *node, int value);

#endif BINARY_TREE_H
