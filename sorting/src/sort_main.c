#include "sort_cmn.h"
#include "sort_utils.h"
#include "sort_ops.h"

enum {
    BUBBLE_SORT     = 0,
    BUBBLE_SORT_OPTIMIZED     = 1,
    SELECTION_SORT  = 2,
    INSERTION_SORT  = 3,
    MERGE_SORT      = 4,
    MERGE_SORT_2    = 5,
    MERGE_SORT_GFG  = 6,
    QUICK_SORT      = 7,
    SHELL_SORT      = 8,
    DEL_ARRAY       = 99
} SORT;

int get_random_n()
{
    int random_n;
    int lower = 5;
    int upper = 10;

    srand(time(NULL));
    sleep(1);
    random_n = rand() % (upper + 1 - lower) + lower;

    return random_n;
}

int *create_array(int n)
{
    int i, value;
    int *arr = NULL;
    int lower = 10;
    int upper = 100;

    arr = (int *)malloc(sizeof(int) * n);
    if (arr == NULL) {
        LOG_ERR("malloc(): %s (%d)", strerror(errno), errno);
        exit (EXIT_FAILURE);
    }

    for (i = 0; i < n; i++) {
        srand(time(NULL));
        sleep(1);
        value = rand() % (upper + 1 - lower) + lower;
        arr[i] = value;
    }

    return arr;
}

void do_full_run()
{
    int n;
    int *p = NULL;

    printf("-------- BUBBLE_SORT ---------------\n");
    n = get_random_n();
    p = create_array(n);
    print_array(p, n, "INITIAL_ARRAY");
    do_bubble_sort(p, n);
    print_array(p, n, "SORTED ARRAY ");
    free(p);
    p = NULL;
    printf("\n");

    printf("-------- SELECTION SORT --------------\n");
    sleep(n);
    n = get_random_n();
    p = create_array(n);
    print_array(p, n, "INITIAL_ARRAY");
    do_selection_sort(p, n);
    print_array(p, n, "SORTED ARRAY ");
    free(p);
    p = NULL;
    n = 0;
    printf("\n");

    printf("-------- INSERTION SORT --------------\n");
    sleep(n);
    n = get_random_n();
    p = create_array(n);
    print_array(p, n, "INITIAL_ARRAY");
    do_insertion_sort(p, n);
    print_array(p, n, "SORTED ARRAY ");
    free(p);
    p = NULL;
    n = 0;
    printf("\n");

    printf("-------- MERGE SORT ---------------\n");
    sleep(n);
    n = get_random_n();
    p = create_array(n);
    print_array(p, n, "INITIAL_ARRAY");
    do_merge_sort(p, n);
    print_array(p, n, "SORTED ARRAY ");
    free(p);
    p = NULL;
    n = 0;
    printf("\n");

    printf("-------- QUICK SORT ---------------\n");
    sleep(n);
    n = get_random_n();
    p = create_array(n);
    print_array(p, n, "INITIAL_ARRAY");
    do_quick_sort(p, n);
    print_array(p, n, "SORTED ARRAY ");
    free(p);
    p = NULL;
    n = 0;
    printf("\n");

    printf("-------- SHELL SORT ---------------\n");
    sleep(n);
    n = get_random_n();
    p = create_array(n);
    print_array(p, n, "INITIAL_ARRAY");
    do_shell_sort(p, n);
    print_array(p, n, "SORTED ARRAY ");
    free(p);
    p = NULL;
    n = 0;
    printf("\n");

    printf("-------- MERGE SORT_2 ------------\n");
    sleep(n);
    n = get_random_n();
    p = create_array(n);
    print_array(p, n, "INITIAL_ARRAY");
    do_merge_sort_2(p, n);
    print_array(p, n, "SORTED ARRAY ");
    free(p);
    p = NULL;
    n = 0;
    printf("\n");
}

void do_selective_run()
{
    int op, n, n_iterations, tmp_n;
    int *p = NULL;

    while (1) {
        printf("\n");
        printf("1.BUBBLE_SORT_EFFICIENT, 2.SELECTION_SORT, 3.INSERTION_SORT, 4.MERGE_SORT\n");
        printf("5.MERGE_SORT_2, 6.MERGE_SORT_GFG, 7.QUICK_SORT, 8.SHELL_SORT, 99.DEL_ARRAY\n");

        printf("\n");
        printf("Enter OP: ");
        scanf("%d", &op);

        switch (op)
        {
            case BUBBLE_SORT:
                printf("Enter n: ");
                scanf("%d", &n);
                p = create_array(n);
                print_array(p, n, "INITIAL_ARRAY");
                do_bubble_sort(p, n);
                print_array(p, n, "SORTED ARRAY ");
                free(p);
                p = NULL;
                printf("\n");
                break;

            case BUBBLE_SORT_OPTIMIZED:
                printf("Enter n: ");
                scanf("%d", &n);
                p = create_array(n);
                print_array(p, n, "INITIAL_ARRAY");
                do_bubble_sort_optimized(p, n);
                print_array(p, n, "SORTED ARRAY ");
                free(p);
                p = NULL;
                printf("\n");
                break;

            case SELECTION_SORT:
                printf("Enter n: ");
                scanf("%d", &n);
                p = create_array(n);
                print_array(p, n, "INITIAL_ARRAY");
                do_selection_sort(p, n);
                print_array(p, n, "SORTED ARRAY ");
                free(p);
                p = NULL;
                printf("\n");
                break;

            case INSERTION_SORT:
                printf("Enter n: ");
                scanf("%d", &n);
                p = create_array(n);
                print_array(p, n, "INITIAL_ARRAY");
                do_insertion_sort(p, n);
                print_array(p, n, "SORTED ARRAY ");
                free(p);
                p = NULL;
                printf("\n");
                break;

            case MERGE_SORT:
                printf("Enter test iterations: ");
                scanf("%d", &n_iterations);

                tmp_n = n_iterations;

                while (n_iterations > 0)
                {
                    int *ap = NULL;
                    int num_elements = get_random_n();
                    ap = create_array(num_elements);
                    print_array(ap, num_elements, "INITIAL_ARRAY    ");
                    do_merge_sort(ap, num_elements);
                    print_array(ap, num_elements, "MERGE SORT ARRAY ");
                    free(ap);
                    ap = NULL;
                    n_iterations--;
                    printf("\n");
                }
                printf("=========== MERGE SORT END ================\n");
                break;

            case MERGE_SORT_2:
                printf("MERGE SORT 2: Enter test iterations: ");
                scanf("%d", &n_iterations);

                //n_iterations = tmp_n;

                while (n_iterations > 0)
                {
                    int *ap = NULL;
                    int num_elements = get_random_n();
                    ap = create_array(num_elements);
                    print_array(ap, num_elements, "INITIAL_ARRAY      ");
                    do_merge_sort_2(ap, num_elements);
                    print_array(ap, num_elements, "MERGE SORT_2 ARRAY ");
                    free(ap);
                    ap = NULL;
                    n_iterations--;
                    printf("\n");
                }
                printf("=========== MERGE SORT_2 END ================\n");
                break;
 
            case MERGE_SORT_GFG:
                printf("Enter test iterations: ");
                scanf("%d", &n_iterations);

                //n_iterations = tmp_n;

                while (n_iterations > 0)
                {
                    int *ap = NULL;
                    int num_elements = get_random_n();
                    ap = create_array(num_elements);
                    print_array(ap, num_elements, "INITIAL_ARRAY        ");
                    do_merge_sort_gfg(ap, 0, (num_elements - 1));
                    print_array(ap, num_elements, "MERGE_SORT_GFG ARRAY ");
                    free(ap);
                    ap = NULL;
                    n_iterations--;
                    printf("\n");
                }
                printf("=========== MERGE SORT_GFG END ================\n");
                break;               

            case QUICK_SORT:
                printf("Enter n: ");
                scanf("%d", &n);
                p = create_array(n);
                print_array(p, n, "INITIAL_ARRAY");
                do_quick_sort(p, n);
                print_array(p, n, "SORTED ARRAY ");
                free(p);
                p = NULL;
                printf("\n");
                break;

            case SHELL_SORT:
                printf("Enter n: ");
                scanf("%d", &n);
                p = create_array(n);
                print_array(p, n, "INITIAL_ARRAY");
                do_shell_sort(p, n);
                print_array(p, n, "SORTED ARRAY ");
                free(p);
                p = NULL;
                printf("\n");
                break;

            case DEL_ARRAY:
                if (p != NULL) {
                    printf("free()ing p %p.... ", p);
                    free(p);
                    p = NULL;
                }
                break;

            default: printf("Deafult case ... op %d", op);
                break;
        } // switch
    } // while

    return;
}

int main(int argc, char **argv)
{
    int run_op;

    printf("Press 1 for FULL run, 2 for SELECTIVE RUN: ");
    scanf("%d", &run_op);

    if (run_op == 1) {
        do_full_run();
    } else if (run_op == 2) {
        do_selective_run();
    }

    return 0;
}