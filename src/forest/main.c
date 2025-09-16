#include <stdio.h>
#include "binary_tree.h"

int bst_rule(int parent_id, int child_id){
  if(child_id < parent_id) return 0;
  return 1;
}

void test_basic_insertion() {
    printf("=== TEST: Basic BST Insertion ===\n");
    BinaryTree tree;
    binary_init_tree(&tree, 5);
    BinaryNode node1, node2, node3, node4;
    binary_init_node(&node1, 3);
    binary_init_node(&node2, 7);
    binary_init_node(&node3, 1);
    binary_init_node(&node4, 9);
    
    binary_push_node(&tree.node, &node1, bst_rule);
    binary_push_node(&tree.node, &node2, bst_rule);
    binary_push_node(&tree.node, &node3, bst_rule);
    binary_push_node(&tree.node, &node4, bst_rule);
    
    printf("Inorder (should be sorted):\n");
    binary_print_tree(&tree, 2);
    printf("\n");
}

void test_height_and_balance() {
    printf("=== TEST: Height and Balance Factor Tracking ===\n");
    BinaryTree tree;
    binary_init_tree(&tree, 10);
    BinaryNode node1, node2, node3;
    binary_init_node(&node1, 5);
    binary_init_node(&node2, 15);
    binary_init_node(&node3, 3);
    
    binary_push_node(&tree.node, &node1, bst_rule);
    binary_push_node(&tree.node, &node2, bst_rule);
    binary_push_node(&tree.node, &node3, bst_rule);
    
    printf("Tree with heights and balance factors:\n");
    binary_print_tree(&tree, 0);
    printf("\n");
}

void test_search_operations() {
    printf("=== TEST: Search Operations ===\n");
    BinaryTree tree;
    binary_init_tree(&tree, 20);
    BinaryNode node1, node2, node3, node4;
    binary_init_node(&node1, 10);
    binary_init_node(&node2, 30);
    binary_init_node(&node3, 5);
    binary_init_node(&node4, 25);
    
    binary_push_node(&tree.node, &node1, bst_rule);
    binary_push_node(&tree.node, &node2, bst_rule);
    binary_push_node(&tree.node, &node3, bst_rule);
    binary_push_node(&tree.node, &node4, bst_rule);
    
    printf("Searching for existing node (10):\n");
    find_node(&tree.node, 10);
    
    printf("Searching for non-existing node (99):\n");
    BinaryNode* result = find_node(&tree.node, 99);
    if (result == NULL) printf("Node 99 not found (correct)\n");
    
    printf("Finding min and max:\n");
    min(&tree.node);
    max(&tree.node);
    printf("\n");
}

void test_unbalanced_insertion() {
    printf("=== TEST: Unbalanced Tree (Sequential Insertion) ===\n");
    printf("Inserting 1,2,3,4,5 to see balance factors:\n");
    BinaryTree tree;
    binary_init_tree(&tree, 1);
    BinaryNode node2, node3, node4, node5;
    binary_init_node(&node2, 2);
    binary_init_node(&node3, 3);
    binary_init_node(&node4, 4);
    binary_init_node(&node5, 5);
    
    binary_push_node(&tree.node, &node2, bst_rule);
    binary_push_node(&tree.node, &node3, bst_rule);
    binary_push_node(&tree.node, &node4, bst_rule);
    binary_push_node(&tree.node, &node5, bst_rule);
    
    printf("Tree structure (should show high balance factors):\n");
    binary_print_tree(&tree, 0);
    printf("\n");
}

void test_delete_operations() {
    printf("=== TEST: Delete Operations ===\n");
    BinaryTree tree;
    binary_init_tree(&tree, 50);
    BinaryNode node1, node2, node3, node4, node5;
    binary_init_node(&node1, 30);
    binary_init_node(&node2, 70);
    binary_init_node(&node3, 20);
    binary_init_node(&node4, 40);
    binary_init_node(&node5, 80);
    
    binary_push_node(&tree.node, &node1, bst_rule);
    binary_push_node(&tree.node, &node2, bst_rule);
    binary_push_node(&tree.node, &node3, bst_rule);
    binary_push_node(&tree.node, &node4, bst_rule);
    binary_push_node(&tree.node, &node5, bst_rule);
    
    printf("Before deletion:\n");
    binary_print_tree(&tree, 2);
    
    printf("Deleting node with two children (30):\n");
    delete_node(&tree.node, 30);
    binary_print_tree(&tree, 2);
    printf("\n");
}

int main(){
    printf("🌳 BINARY SEARCH TREE TEST SUITE 🌳\n");
    printf("=====================================\n\n");
    
    test_basic_insertion();
    test_height_and_balance();
    test_search_operations();
    test_unbalanced_insertion();
    test_delete_operations();
    
    printf("✅ All tests completed!\n");
    printf("Check the balance factors in the unbalanced test - they should show ±2 values.\n");
    
    return 0;
}
