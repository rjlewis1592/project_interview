
#include "tree_defs.h"
#include "tree_ops.h"
#include "tree_cmn.h"

static bool is_leaf_node(bst_node_t *root);

void print_ascii_tree(bst_node_t *root);

static bst_node_t *create_new_node(int value)
{
	bst_node_t *temp = (bst_node_t *)malloc(sizeof(bst_node_t));
	if (temp == NULL) {
		LOG_ERR("malloc(): %s (%d)", strerror(errno), errno);
		return NULL;
	}

	temp->data = value;
	temp->right = NULL;
	temp->left = NULL;

	return temp;
}

bst_node_t *insert_node(bst_node_t *root, int value)
{
	if (root == NULL) {
		bst_node_t *new_node = create_new_node(value);
		if (new_node == NULL) {
			LOG_DBG("could not create new node %d", value);
			return root;
		}
		return new_node;
	}

	if (value < root->data) {
		root->left = insert_node(root->left, value);
	} else if (value > root->data) {
		root->right = insert_node(root->right, value);
	} else {
		LOG_DBG("duplicate value (%d) - ignore insertion", root->data);
	}

	return root;
}

bool search_node(bst_node_t *root, int key)
{
	if (root == NULL) {
		LOG_DBG("key %d NOT found", key);
		return false;
	}

	if (root->data == key) {
		LOG_DBG("key %d found", key);
		return true;
	}

	return search_node(((key < root->data) ? root->left : root->right), key);
}

static bst_node_t *find_min_node(bst_node_t *root)
{
	if (root == NULL) {
		return root;
	}

	if (root->left == NULL) {
		return root;
	}

	return find_min_node(root->left);
}

bst_node_t *delete_node(bst_node_t *root, int key)
{
	if (root == NULL) {
		return root;
	}

	if (key < root->data) {
		root->left = delete_node(root->left, key);
	} else if (key > root->data) {
		root->right = delete_node(root->right, key);
	} else {  // key found
		LOG_DBG("key %d found - delete it", key);
		// case 0: leaf node - delete it and return;
		if (is_leaf_node(root) == true) {
			LOG_DBG("free()ing %d", root->data);
			free(root);
			root = NULL;
		} 
		// case 1: one child
		else if (root->left == NULL)  {
			bst_node_t *temp = root;
			root = root->right;
			LOG_DBG("free()ing %d", temp->data);
			free(temp);
			temp = NULL;
		} else if (root->right == NULL) {
			bst_node_t *temp = root;
			root = root->left;
			LOG_DBG("free()ing %d", temp->data);
			free(temp);
			temp = NULL;
		} 
		// case 2: two children
		else {
			bst_node_t *temp = find_min_node(root->right);
			if (temp != NULL) {
				root->data = temp->data;
			}
			root->right = delete_node(root->right, temp->data);
		}
	} 
	return root;
}

bst_node_t *tree_find_max(bst_node_t *root)
{
	if (root == NULL) {
		return NULL;
	}

	if (root->right == NULL) {
		return root;
	}

	return tree_find_max(root->right);
}

bst_node_t *tree_find_min(bst_node_t *root)
{
	if (root == NULL) {
		return NULL;
	}

	if (root->left == NULL) {
		return root;
	}

	return tree_find_min(root->left);
}

int find_max_recursive(bst_node_t *root)
{
	if (root == NULL) {
		LOG_DBG("empty tree");
		return INT_MIN;
	}

	if (root->right == NULL) {
		LOG_DBG("tree max %d", root->data);
		return (root->data);
	}

	return find_max_recursive(root->right); 
}

int find_max_iterative(bst_node_t *root)
{
	if (root == NULL) {
		LOG_DBG("empty tree");
		return INT_MIN;
	}

	while (root->right != NULL) {
		root = root->right;
	}

	LOG_DBG("tree max %d", root->data);

	return (root->data);
}

int find_min_recursive(bst_node_t *root)
{
	if (root == NULL) {
		LOG_DBG("empty tree");
		return INT_MIN;
	}

	if (root->left == NULL) { // found minimum node
		LOG_DBG("tree min %d", root->data);
		return (root->data);

	}
	return find_min_recursive(root->left);
}

int find_min_iterative(bst_node_t *root)
{
	if (root == NULL) {
		LOG_DBG("empty tree");
		return INT_MIN;
	}

	while (root->left != NULL) {
		root = root->left;
	}

	LOG_DBG("tree min %d", root->data);

	return (root->data);	
}

static bool is_leaf_node(bst_node_t *root)
{
	assert(root != NULL) ;

	if ((root->left == NULL) && (root->right == NULL)) { // leaf node
		return true;
	}

	return false;
}

bst_node_t *delete_tree(bst_node_t *root)
{
	if (root == NULL) {
		return NULL;
	}

	// small optimization
	if (is_leaf_node(root) == true) { // leaf node
		LOG_DBG("leaf node %d! - free()ing it", root->data);
		free(root);
		root = NULL;
		return root;	
	}

	root->left = delete_tree(root->left);
	root->right = delete_tree(root->right);

	LOG_DBG("free()ing %d", root->data);
	free(root);
	root=NULL;
	return root;
}

void tree_preorder_traversal(const bst_node_t *root)
{
	if (root == NULL) {
		return;
	}

	printf("%d, ", root->data);
	tree_preorder_traversal(root->left);
	tree_preorder_traversal(root->right);

	return;
}

void tree_inorder_traversal(const bst_node_t *root)
{
	if (root == NULL) {
		return;
	}

	tree_inorder_traversal(root->left);
	printf("%d, ", root->data);
	tree_inorder_traversal(root->right);

	return;
}

void tree_postorder_traversal(const bst_node_t *root)
{
	if (root == NULL) {
		return;
	}

	tree_postorder_traversal(root->left);
	tree_postorder_traversal(root->right);
	printf("%d, ", root->data);

	return;
}

int tree_height(const bst_node_t *root)
{
#if 0
	int max = 0;
	int lh = 0;
	int rh = 0;
#endif

	if (root == NULL) {
		return -1;
	}
#if 0
	lh = tree_height(root->left);
	rh = tree_height(root->right);
	max = TREE_MAX(lh, rh);
	return (max + 1);
#endif
	return (TREE_MAX((tree_height(root->left)), (tree_height(root->right))) + 1); 
}