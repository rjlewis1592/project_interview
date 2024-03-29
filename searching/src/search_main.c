#include "search_cmn.h"
#include "search_utils.h"
#include "search_ops.h"


enum {
    LINEAR_SERACH               = 1,
    RECURSIVE_BINARY_SEARCH     = 2,
    ITERATIVE_BINARY_SEARCH     = 3,
    FIND_LARGEST                = 4,
    FIND_SECOND_LARGEST         = 5,
    FIND_SMALLEST               = 6,
    FIND_SECOND_SMALLEST        = 7,
    DEL_ARRAY                   = 98,
    DONE_EXIT                   = 99
} SEARCH;


int main(int argc, char **argv)
{
    char ch;
    bool found;
    int i, n, op, key, pos;
    int largest, second_largest, smallest, second_smallest;
    int ret = 0;
    int *arr = NULL;

    printf("Create array manually? press 'y' for yes: ");
    scanf(" %c", &ch);
    if (ch == 'y') {
        printf("Enter n (> 0): ");
        scanf("%d", &n);
        assert(n > 0);

        arr = (int *)malloc(sizeof(int) * n);
        if (arr == NULL) {
            LOG_ERR("malloc(): %s (%d)", strerror(errno), errno);
            exit(EXIT_FAILURE);
        }

        printf("Enter %d array elements: ", n);
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
    } else {
        printf("creating array automatically...\n");
        arr = create_array(&n);
        LOG_DBG("n %d", n);
    }

    print_array(arr, n, "INITIAL_ARRAY");

    while (true) {
        printf("\n");
        printf("1.LINEAR SEARCH, 2.RECURSIVE_BINARY_SEARCH, 3.ITERATIVE_BINARY_SEARCH\n");
        printf("4.FIND_LARGEST, 5.FIND_SECOND_LARGEST, 6.FIND_SMALLEST, 7.FIND_SECOND_SMALLEST\n");
        printf("98.DEL_ARRAY, 99.DONE_EXIT\n");
        printf("Enter op: ");
        scanf("%d", &op);

        switch (op)
        {
            case LINEAR_SERACH:
                printf("\n-------- LINEAR SEARCH ---------------\n");
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

            case FIND_LARGEST:
                printf("\n-------- FIND LARGEST ---------------\n");
                print_array(arr, n, "INITIAL_ARRAY");

                largest = find_largest(arr, n);
                printf("Largest element %d", largest);

                if (arr) {
                    //LOG_DBG("free()ing arr %p...", arr);
                    free(arr);
                    arr = NULL;
                }
                break;

            case FIND_SECOND_LARGEST:
                printf("\n-------- FIND SECOND LARGEST ---------------\n");

                ret = 0;
                ret = find_second_largest(arr, n, &second_largest);
                if (ret == SEARCH_OPS_SUCCESS) {
                    printf("Second largest element %d\n", second_largest);
                } else {
                    LOG_ERR("Error finding second largest");
                }

                if (arr) {
                    //LOG_DBG("free()ing arr %p...", arr);
                    free(arr);
                    arr = NULL;
                }
                break;

            case FIND_SMALLEST:
                printf("\n-------- FIND SMALLEST ---------------\n");

                smallest = find_smallest(arr, n);
                printf("Smallest element %d", smallest);

                if (arr) {
                    //LOG_DBG("free()ing arr %p...", arr);
                    free(arr);
                    arr = NULL;
                }
                break;

            case FIND_SECOND_SMALLEST:
                printf("\n-------- FIND SECOND SMALLEST ---------------\n");
    
                ret = 0;
                ret = find_second_smallest(arr, n, &second_smallest);
                if (ret == SEARCH_OPS_SUCCESS) {
                    printf("Second smallest element %d\n", second_smallest);
                } else {
                    LOG_ERR("Could not find second smallest element !");
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