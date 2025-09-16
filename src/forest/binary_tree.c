#include "binary_tree.h"
#include <stdio.h>

void binary_init_node(BinaryNode *node, int id){
  node->id = id;
  node->parent = NULL;
  node->left = NULL;
  node->right = NULL;
  node->height = 0;
  node->balance_factor = 0;
}

void avl_hb_management(BinaryNode *parent){
  int right, left = 0;
  int b_right, b_left  = -1;
  if(parent->right!= NULL) {
    right = parent->right->height;
    b_right = right;
  }
  if(parent->left!= NULL) {
    left = parent->left->height;
    b_left = left;
  }

  if(left>right){
    parent->height = left+1;
  }else{
    parent->height = right+1;
  }
  parent->balance_factor = b_right - b_left;
}

void _right_right_rotation(BinaryNode **parent){
  BinaryNode *temp_parent = *parent;
  *parent=temp_parent->right;
  (*parent)->parent = temp_parent->parent;
  temp_parent->parent = *parent;
  (*parent)->left = temp_parent;
}

void _left_left_rotation(BinaryNode **parent){
  BinaryNode *temp_parent = *parent;
  *parent=temp_parent->left;
  (*parent)->parent = temp_parent->parent;
  temp_parent->parent = *parent;
  (*parent)->right= temp_parent;
}

void _left_right_rotation(BinaryNode **parent){
  _right_right_rotation(&((*parent)->left));
  _left_left_rotation(parent);
}
void _right_left_rotation(BinaryNode **parent){
  _right_right_rotation(&((*parent)->left));
  _left_left_rotation(parent);
}

//TODO: Implement the which rotation to use and we should be balancing stuff

void binary_push_node(BinaryNode *parent, BinaryNode *node_to_push, Rule rule){
  // check if rule applies
  if(rule(parent->id, node_to_push->id)==0){
    // left is populated recurse to left
    if (parent->left != NULL){
      binary_push_node(parent->left, node_to_push, rule);
      avl_hb_management(parent);
      return;
    }
    node_to_push->parent = parent;
    parent->left = node_to_push;
    return;
    }

  // right is populated recurse to right
  if (parent->right!= NULL){
    binary_push_node(parent->right, node_to_push, rule);
    avl_hb_management(parent);
    return;
  }

  node_to_push->parent = parent;
  parent->right= node_to_push;
  return;
}


void binary_init_tree(BinaryTree *tree, int id){
  binary_init_node(&tree->node, id);
}

void _print_binary_node_metadata(BinaryNode *node){
  if(node->parent==NULL){
    printf("Node id->%d Parent id->NULL Height->%d Balance Factor->%d\n", node->id, node->height,node->balance_factor);
  }else{
    printf("Node id->%d Parent id->%d Height->%d Balance Factor->%d\n", node->id, node->parent->id, node->height, node->balance_factor);
  }
}

void binary_print_node_preorder(BinaryNode *node, int current_depth){
  if(node==NULL) return;

  _print_binary_node_metadata(node);
  binary_print_node_preorder(node->left, current_depth+1);
  binary_print_node_preorder(node->right, current_depth+1);
  
}
void binary_print_node_postorder(BinaryNode *node, int current_depth){
  if(node==NULL) return;
  binary_print_node_postorder(node->left, current_depth+1);
  binary_print_node_postorder(node->right, current_depth+1);

  _print_binary_node_metadata(node);
}
void binary_print_node_inorder(BinaryNode *node, int current_depth){
  if(node==NULL) return;
  binary_print_node_inorder(node->left, current_depth+1);

  _print_binary_node_metadata(node);

  binary_print_node_inorder(node->right, current_depth+1);
}

void binary_print_tree(BinaryTree *tree, int order){
  if (order == 0){
  binary_print_node_preorder(&(tree->node), 0);
  }else if (order == 1){
    binary_print_node_postorder(&(tree->node), 0);
  }else if (order == 2){
    binary_print_node_inorder(&(tree->node), 0);
  }

}


BinaryNode* find_node(BinaryNode *node, int value){
  if(node==NULL) return NULL;
  if(node->id == value){
    printf("Found node %d\n", value);
    return node;
  }else if(node->id<value){
    return find_node(node->right,value);
  }else if(node->id>value){
    return find_node(node->left,value);
  }

}
BinaryNode* min(BinaryNode *node){
  if (node==NULL) return NULL;
  if(node->left == NULL){
    printf("Minimum node is %d\n", node->id);
    return node;
  }
  return min(node->left);
}
BinaryNode* max(BinaryNode *node){
  if (node==NULL) return NULL;
  if(node->right == NULL){
    printf("Maximum node is %d\n", node->id);
    return node;
  }
  return max(node->right);
}


void sub_parent_child_with_node(BinaryNode *node, BinaryNode *newNode){
  if(node->parent->right == node){
      node->parent->right = newNode;
    }else if(node->parent->left == node){
      node->parent->left= newNode;
    }

}

void delete_node(BinaryNode *root_node,int value){
  BinaryNode *node = find_node(root_node,value);
  if(node->left==NULL&&node->right==NULL){
    sub_parent_child_with_node(node,NULL);
  }else if(node->left!=NULL&&node->right==NULL){
    sub_parent_child_with_node(node,node->left);
  }else if(node->left==NULL&&node->right!=NULL){
    sub_parent_child_with_node(node,node->right);
  }else{
    BinaryNode *successor = max(node->right);
    int temp = successor->id;
    delete_node(root_node, temp);
    node->id = temp;
  }
  printf("Deleted node %d\n", value);
}
