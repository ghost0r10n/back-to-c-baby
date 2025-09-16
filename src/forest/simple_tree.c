#include "simple_tree.h"
#include <stdio.h>

void init_node(Node *node, Node *parent, char id){
  node->id = id;
  node->parent = parent;
  node->current_capacity = 4;
  node->children = malloc(node->current_capacity * sizeof(Node));
  node->size = 0;
}

void push_node(Node *parent, Node node_to_push){
  if(parent->size >= parent->current_capacity){
    size_t newCapacity = parent->current_capacity+4;
    Node *newPtr = realloc(parent->children, newCapacity * sizeof(Node));
    if(newPtr!=NULL){
      parent->children = newPtr;
      parent->current_capacity = newCapacity;
    }
  }
  parent->children[parent->size] = node_to_push;
  parent->size++;
}


void init_tree(SimpleTree *tree, char id){
  init_node(&tree->node, NULL, id);
  tree->size = 1;
}
void print_node_preorder(Node *node, int current_depth){
  printf("Node Id: %c, Children: %zu\n", node->id, node->size);
  for(size_t i=0; i<node->size; i++){
    for (int i = 0; i<=current_depth; i++){
      printf("---");
    }
    print_node_preorder(&node->children[i], current_depth+1);
  }
}
void print_node_postorder(Node *node, int current_depth){
  for(size_t i=0; i<node->size; i++){
    for (int i = 0; i<=current_depth; i++){
      printf("---");
    }
    print_node_postorder(&node->children[i], current_depth+1);
  }
  printf("Node Id: %c, Children: %zu\n", node->id, node->size);
}

void print_tree(SimpleTree *tree, int order){
  if (order == 0){
  print_node_preorder(&(tree->node), 0);
  }else if (order == 1){
  print_node_postorder(&(tree->node), 0);
  }

}
