#include "search_cmn.h"
#include "search_utils.h"
#include "search_ops.h"


enum {
    LINEAR_SERACH               = 1,
    RECURSIVE_BINARY_SEARCH     = 2,
    ITERATIVE_BINARY_SEARCH     = 3,
    DEL_ARRAY                   = 98,
    DONE_EXIT                   = 99
} SEARCH;


int main(int argc, char **argv)
{
    int op, key;
    int n, pos;
    bool found;
    int *arr = NULL;

    while (true) {
        printf("\n");
        printf("1.LINEAR SEARCH, 2.RECURSIVE_BINARY_SEARCH, 3.ITERATIVE_BINARY_SEARCH, 98.DEL_ARRAY, 99.DONE_EXIT\n");
        printf("Enter op: ");
        scanf("%d", &op);

        switch (op)
        {
            case LINEAR_SERACH:
                printf("\n-------- LINEAR SEARCH ---------------\n");
                n = get_random_n();
                arr = create_array(n);
                print_array(arr, n, "INITIAL_ARRAY");
                printf("Enter the key to search: ");
                scanf("%d", &key);

                found = do_linear_search(arr, n, key, &pos);
                if (found == true) {
                    LOG_DBG("key %d found! @ pos %d", key, pos);
                } else {
                    LOG_ERR("key %d NOT found !", key);
                }

                if (arr) {
                    //LOG_DBG("free()ing arr %p...", arr);
                    free(arr);
                    arr = NULL;
                }
                break;

            case RECURSIVE_BINARY_SEARCH:
                printf("\n-------- RECURSIVE BINARY SEARCH ---------------\n");
                n = get_random_n();
                arr = create_array(n);
                print_array(arr, n, "INITIAL_ARRAY");
                printf("Enter the key to search: ");
                scanf("%d", &key);

                found = do_recursive_binary_search(arr, n, key, &pos);
                if (found == true) {
                    LOG_DBG("key %d found! @ pos %d", key, pos);
                } else {
                    LOG_ERR("key %d NOT found !", key);
                }

                if (arr) {
                    //LOG_DBG("free()ing arr %p...", arr);
                    free(arr);
                    arr = NULL;
                }
                break;

            case ITERATIVE_BINARY_SEARCH:
                printf("\n-------- ITERATIVE BINARY SEARCH ---------------\n");
                n = get_random_n();
                arr = create_array(n);
                print_array(arr, n, "INITIAL_ARRAY");
                printf("Enter the key to search: ");
                scanf("%d", &key);

                found = do_iterative_binary_search(arr, n, key, &pos);
                if (found == true) {
                    LOG_DBG("key %d found! @ pos %d", key, pos);
                } else {
                    LOG_ERR("key %d NOT found !", key);
                }

                if (arr) {
                    //LOG_DBG("free()ing arr %p...", arr);
                    free(arr);
                    arr = NULL;
                }
                break;
            case DEL_ARRAY:
                if (arr) {
                    LOG_DBG("free()ing arr %p...", arr);
                    free(arr);
                    arr = NULL;
                }
                break;

            case DONE_EXIT:
                goto clean_up;

            default:
                printf("Default case... op %d", op);
                break;
        } // switch

    } // while

clean_up:
    if (arr) {
        LOG_DBG("free()ing arr %p...", arr);
        free(arr);
        arr = NULL;
    }
    return 0;
}