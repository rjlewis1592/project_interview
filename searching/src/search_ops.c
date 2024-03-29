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

int find_largest(int a[], int arr_sz)
{
    int i;
    int largest = INT_MIN;

    assert(arr_sz > 0);

    for (i = 0; i < arr_sz; i++) {
        if (a[i] > largest) {
            largest = a[i];
        }
    }

    return largest;
}

int find_second_largest(int a[], int arr_sz, int *second_largest)
{
    int i;
    int max, secnd_max;

    assert(arr_sz > 0);
    assert(second_largest != NULL);

    if (arr_sz < 2) {
        LOG_ERR("arr_sz = %d", arr_sz);
        return SEARCH_OPS_FAILURE;
    }


    max = secnd_max = INT_MIN;
    for (i = 0; i < arr_sz; i ++) {
        if (a[i] > max) {
            secnd_max = max;
            max = a[i];
        } else if ((a[i] != max) && (a[i] > secnd_max)) {
            secnd_max = a[i];
        }
    }

    if (secnd_max == INT_MIN) {
        LOG_DBG("NO second largest element in the array - identical array elements");
        return SEARCH_OPS_FAILURE;
    }

    *second_largest = secnd_max;

    LOG_DBG("max %d, secnd_max %d, *second_largest %d", max, secnd_max, *second_largest);

    return SEARCH_OPS_SUCCESS;
}

int find_smallest(int a[], int arr_sz)
{
    int i;
    int smallest = INT_MAX;

    assert(arr_sz > 0);

    for (i = 0; i < arr_sz; i++) {
        if (a[i] < smallest) {
            smallest = a[i];
        }
    }

    return smallest;
}

int find_second_smallest(int a[], int arr_sz, int *second_smallest)
{
    int i;
    int min, secnd_min;

    assert(arr_sz > 0);
    assert(second_smallest != NULL);

    if (arr_sz < 2) {
        LOG_ERR("arr_sz = %d", arr_sz);
        return SEARCH_OPS_FAILURE;
    }

    min = secnd_min = INT_MAX;
    for (i = 0; i < arr_sz; i ++) {
        if (a[i] < min) {
            secnd_min = min;
            min = a[i];
        } else if ((a[i] < secnd_min) && (a[i] != min)) {
            secnd_min = a[i];
        }
    }

    if (secnd_min == INT_MAX) {
        LOG_DBG("NO second smallest element in the array !!");
        return SEARCH_OPS_FAILURE;
    } 

    *second_smallest = secnd_min;

    LOG_DBG("min %d, smin  %d, *second_smallest %d", min, secnd_min, *second_smallest);

    return SEARCH_OPS_SUCCESS;
}