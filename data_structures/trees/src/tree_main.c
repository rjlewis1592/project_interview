#include "tree_cmn.h"
#include "tree_ops.h"
#include "tree_defs.h"
#include "tree_utils.h"

#define INSERT_NODE			1U
#define DELETE_NODE			2U
#define SEARCH_KEY			3U
#define TREE_DISPLAY		4U
#define TREE_MIN_REC		5U
#define TREE_MIN_ITR		6U
#define TREE_MAX_REC		7U
#define TREE_MAX_ITR		8U
#define TREE_TRAVERSAL		9U
#define TREE_MIN_LT_SUBTREE	10U
#define TREE_MAX_LT_SUBTREE	11U
#define TREE_MIN_RT_SUBTREE	12U
#define TREE_MAX_RT_SUBTREE	13U
#define TREE_DELETE			14U
#define TREE_HEIGHT			15U
#define TREE_EXIT			99U

int main()
{
	int op, value, key, retval;
	bst_node_t *root =  NULL;
	bst_node_t *min_node = NULL;
	bst_node_t *max_node = NULL;

#if 0
	int i, n;
    int lower = 1;
    int upper = 100;
	char ch;

	int node_array[15] = {100, 50, 200, 25, 75, 150, 300, 250, 400, 225, 275, 350, 450, 279, 290};
#endif

	printf("\n");

	while (true) {
		printf("\n===========================\n");
		printf("Supported TREE OPERATIONS:\n");
		printf(	"1. INSERT_NODE, 2. DELETE_NODE, 3. SEARCH_KEYm, 4. TREE_DISPLAY, 5. TREE_MIN_REC, 6. TREE_MIN_ITR, 7. TREE_MAX_REC\n");
		printf("8. TREE_MAX_ITR, 9. TREE_TRAVERSAL, 10. TREE_MIN_LT_SUBTREE, 11. TREE_MAX_LT_SUBTREE, 12. TREE_MIN_RT_SUBTREE 13. TREE_MAX_RT_SUBTREE\n");
		printf("14. TREE_DELETE, 15. TREE_HEIGHT, 99. TREE_EXIT\n");

		printf("\nEnter the operation: ");
		scanf("%d", &op);

		switch (op) {
				case INSERT_NODE:
#if 1
				printf("Enter the value to insert: ");
				scanf("%d", &value);
				root = insert_node(root, value);
				print_ascii_tree(root);
				break;
#else
			case INSERT_NODE:
				printf("Insert manually? press 'y' for yes: ");
				scanf(" %c", &ch);
				if (ch == 'y') {
					printf("BST_INSERT: Enter the value to insert: ");
					scanf("%d", &value);
					root = insert_node(root, value);
				} else {
					printf("BST_INSERT: Enter the number of elements to insert: ");
					scanf("%d", &n);
					printf("BST_INSERT: inserting %d elements automatically in BST...", n);
					fflush(stdout);
					for (i = 0; i < n; i++) {
						srand(time(NULL));
						sleep(1);
						value = rand() % (upper + 1 - lower) + lower;
						printf("(%d, %d) ", i, value);
						fflush(stdout);
						root = insert_node(root, value);
					}
				}
				print_ascii_tree(root);
				break;
#endif
			case DELETE_NODE:
				print_ascii_tree(root);
				printf("Enter key: ");
				scanf("%d", &key);
				root = delete_node(root, key);
				print_ascii_tree(root);
				break;
			case SEARCH_KEY:
				printf("Enter the key to search: ");
				scanf("%d", &key);
				printf("KEY %d %s FOUND\n", key,
						search_node(root, key) ? "" : "NOT");
				break;
			case TREE_DISPLAY:
				print_ascii_tree(root);
				break;
			case TREE_MIN_REC:
				if ((retval = find_min_recursive(root)) != 0xDEADBEEF) {
					printf("MIN (recursive) %d\n", retval);
				}
				break;
			case TREE_MIN_ITR:
				if ((retval = find_min_iterative(root)) != 0xDEADBEEF) {
					printf("MIN (iterative) %d\n", retval);
				}
				break;
			case TREE_MAX_REC:
				if ((retval = find_max_recursive(root)) != INT_MIN) {
					printf("MAX (recursive) %d\n", retval);
				}
				break;
			case TREE_MAX_ITR:
				if ((retval = find_max_iterative(root)) != INT_MIN) {
					printf("MAX (iterative) %d\n", retval);
				}
				break;
			case TREE_TRAVERSAL:
				printf("PREORDER : ");
				tree_preorder_traversal(root);
				printf("\n");
				printf("INORDER  : ");
				tree_inorder_traversal(root);
				printf("\n");
				printf("POSTORDER: ");
				tree_postorder_traversal(root);
				printf("\n");
				break;
			case TREE_MIN_LT_SUBTREE:
				min_node = tree_find_min(root->left);
				if (min_node != NULL) {
					printf("minimum of root's left subtree (%d) is %d\n",
							root->left->data, min_node->data);
				}
				break;
			case TREE_MAX_LT_SUBTREE:
				max_node = tree_find_max(root->left);
				if (max_node != NULL) {
					printf("maximum of root's left subtree (%d) is %d\n",
							root->left->data, max_node->data);
				}
				break;
			case TREE_MIN_RT_SUBTREE:
				min_node = tree_find_min(root->right);
				if (min_node != NULL) {
					printf("minimum of root's right subtree (%d) is %d\n",
							root->right->data, min_node->data);
				}
				break;
			case TREE_MAX_RT_SUBTREE:
				max_node = tree_find_max(root->right);
				if (max_node != NULL) {
					printf("maximum of root's right subtree (%d) is %d\n",
							root->right->data, max_node->data);
				}
				break;
			case TREE_DELETE:
				root = delete_tree(root);
				print_ascii_tree(root);
				break;
			case TREE_HEIGHT:
				value = tree_height(root);
				printf("tree hegith %d\n", value);
				break;
			case TREE_EXIT:
				goto tree_exit;
				break;
			default:
				printf("default case\n");
				break;
		}
	}
tree_exit:
	if (root) {
		printf("%s: root %p, root->right %p, root->left %p\n",
			__func__, root, root->right, root->left);
		root = delete_tree(root);
		printf("root %p\n", root);
	}

	print_ascii_tree(root);
	return 0;
}
