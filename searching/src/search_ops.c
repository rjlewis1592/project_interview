#include "search_cmn.h"
#include "search_utils.h"
#include "search_ops.h"

static bool do_rec_bin_search(int arr[], int left_idx, int right_idx, int key, int *pos);

bool do_linear_search(int arr[], int n, int key, int *pos)
{
    int i;

    assert(n > 0);

    i = 0;
    while ((i < n) && (arr[i] != key)) {
        i++;
    }

    if (i == n) {
        LOG_ERR("key %d NOT found", key);
        return false;
    }

    LOG_DBG("key %d found @ position %d", key, i);
    if (pos != NULL) {
        *pos = i;
    }

    return true;
}

static bool do_rec_bin_search(int arr[], int left_idx, int right_idx, int key, int *pos)
{
    int mid_idx;

    if (left_idx > right_idx) {
        LOG_DBG("key %d NOT found", key);
        return false;
    }

    mid_idx = left_idx + ((right_idx - left_idx) / 2);

    if (key == arr[mid_idx]) {
        LOG_DBG("key %d found at position %d", key, mid_idx);
        if (pos != NULL) {
            *pos = mid_idx;
        }
        return true;
    }

    if (key < arr[mid_idx]) {
        return do_rec_bin_search(arr, left_idx, (mid_idx - 1), key, pos);
    } 

    //key > arr[mid_idx]
    return do_rec_bin_search(arr, (mid_idx + 1), right_idx, key, pos);
}

bool do_recursive_binary_search(int arr[], int n, int key, int *pos)
{
    int left_idx, right_idx;

    assert(n > 0);

    /* Sort the given array in asecnding order */
    qsort((void *)arr, (size_t)n, (size_t) sizeof(int), do_my_compare);
    print_array(arr, n, "QSORT_ARRAY");

    left_idx = 0;
    right_idx = n - 1;

    return do_rec_bin_search(arr, left_idx, right_idx, key, pos);
}

bool do_iterative_binary_search(int arr[], int n, int key, int *pos)
{
    int left_idx, right_idx;

    assert(n > 0);

    /* Sort the given array in asecnding order */
    qsort((void *)arr, (size_t)n, (size_t) sizeof(int), do_my_compare);

    print_array(arr, n, "QSORT_ARRAY");

    left_idx = 0;
    right_idx = n - 1;

    while (left_idx <= right_idx) {
        int mid_idx = left_idx + ((right_idx - left_idx) / 2);

        if (key == arr[mid_idx]) {
          LOG_DBG("key %d found at position %d", key, mid_idx);
            if (pos != NULL) {
                *pos = mid_idx;
            }
            return true;
        }

       (key < arr[mid_idx]) ? (right_idx = (mid_idx - 1)) : (left_idx = (mid_idx + 1));
       
    }

    LOG_ERR("key %d NOT found", key);

    return false;
}