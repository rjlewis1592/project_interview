#ifndef TREE_OPS_H_
#define TREE_OPS_H_

#include "tree_cmn.h"

bst_node_t *insert_node(bst_node_t *root, int value);
bst_node_t *delete_node(bst_node_t *root, int key);
bool search_node(bst_node_t *root, int key);
bst_node_t *delete_tree(bst_node_t *root);
int find_max_recursive(bst_node_t *root);
int find_max_iterative(bst_node_t *root);
int find_min_recursive(bst_node_t *root);
int find_min_iterative(bst_node_t *root);
void tree_preorder_traversal(const bst_node_t *root);
void tree_inorder_traversal(const bst_node_t *root);
void tree_postorder_traversal(const bst_node_t *root);
bst_node_t *tree_find_min(bst_node_t *root);
bst_node_t *tree_find_max(bst_node_t *root);
int tree_height(const bst_node_t *root);

#endif // TREE_OPS_H_