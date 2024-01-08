#include "sort_cmn.h"
#include "sort_utils.h"
#include "sort_ops.h"

// 90, 10, 30, 50, 20
void do_bubble_sort(int a[], int n)
{

}

void do_bubble_sort_optimized(int a[], int n)
{
    int i, j;

    if (n < 0) {
        fprintf(stderr, "Invalid n %d\n", n);
        return;
    }

    for (i = 0; i < (n - 1); i++) {
        bool swapped = false;

        for (j = 0; j < (n - i - 1); j++) {
            if (a[j] > a[j + 1]) {
                do_swap(&a[j], &a[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }

    return;
}

void do_selection_sort(int a[], int n)
{
    int i, j;
    int min_idx = 0;

    for (i = 0; i < (n - 1); i++) {
        min_idx = i;
        for (j = (i + 1); j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        if ( min_idx != i) {
            do_swap(&a[i], &a[min_idx]);
        }
    } // for
}

void do_insertion_sort(int a[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j] > key)) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

void do_merge(int *a, int *la, int lsz, int *ra, int rsz)
{
    int ai, li, ri; 

    assert(a && la && ra);
    assert((lsz > 0) && (rsz > 0));

    ai = li = ri = 0;
    while ((li < lsz) && (ri < rsz)) {
        if (la[li] <= ra[ri]) {
            a[ai++] = la[li++];
        } else {
            a[ai++] = ra[ri++];
        }
    }

    while (li < lsz) {
        a[ai++] = la[li++];
    }
    while (ri < rsz) {
        a[ai++] = ra[ri++];
    }
}

void do_merge_sort(int a[], int n)
{
    int i;
    int mid = 0, lsz = 0, rsz = 0;
    int *la = NULL;
    int *ra = NULL;

    if (n < 2) {
        return;
    }

    mid = n / 2;

    lsz = mid;
    rsz = (n - mid);
    la = (int *)calloc(lsz, sizeof(int));
    ra = (int *)calloc(rsz, sizeof(int));

    if (!la || !ra) {
        LOG_ERR("malloc(): %s(%d)", strerror(errno), errno);
        exit (EXIT_FAILURE);
    }

    // populate left array
    for (i = 0; i < lsz; i++)
        la[i] = a[i];

    // populate right array
    for (i = 0; i < rsz; i++)
        ra[i] = a[mid + i];

    do_merge_sort(la, lsz);
    do_merge_sort(ra, rsz);

    do_merge(a, la, lsz, ra, rsz);

    if (la)
        free(la);

    if (ra)
        free(ra);

    return;
}

void merge_arrays_2(int arr[], int l, int m, int r)
{
    int i, j, k;
    int lsz = m - l + 1;
    int rsz = r - m;

    int *la = (int *)malloc(sizeof(int) * lsz);
    int *ra = (int *)malloc(sizeof(int) * rsz);

    for (i = 0; i < lsz; i++) {
        la[i] = arr[l + i];
    }

    for (j = 0; j < rsz; j++) {
        ra[j] = arr[m + 1 + j];
    }

    i = j = 0;
    k = l;
    while ((i < lsz) && (j < rsz)) {
        if (la[i] <= ra[j]) {
            arr[k] =  la[i++];
        } else {
            arr[k] =  ra[j++];
        }
        k++;
    }

    while (i < lsz) {
        arr[k++] = la[i++];
    }
    while (j < rsz) {
        arr[k++] = ra[j++];
    }

    free(la);
    free(ra);
}


void merge_sort_2(int arr[], int l, int r)
{
    if (l < r) {

        int m = l + (r - l) / 2;

        merge_sort_2(arr, l, m);
        merge_sort_2(arr, (m + 1), r);

        merge_arrays_2(arr, l, m, r);
    }

    return;
}

void do_merge_sort_2(int a[], int n)
{
    merge_sort_2(a, 0, (n - 1));
}

int get_randomized_pivot_index(int l, int r)
{
    return r;
}

int do_partition(int a[], int l, int r)
{
    int i, j, pi;
    int pivot;

    pi = get_randomized_pivot_index(l, r);
    pivot = a[pi];
    i = l - 1;

    for (j = l; j <= r; j++) {
        if (a[j] < pivot) {
            i++;
            do_swap(&a[i], &a[j]);
        }
    }

    do_swap(&a[i + 1], &a[pi]); // position the pivot

    return (i + 1); // pivot index
} 

void do_my_quick_sort(int a[], int l, int r)
{
    if (l < r) {
        int pi = do_partition(a, l, r);
        do_my_quick_sort(a, l, (pi - 1));
        do_my_quick_sort(a, (pi + 1), r);
    }

    return;
}

void do_quick_sort(int a[], int n)
{
    do_my_quick_sort(a, 0, (n - 1));

    return;
}

void do_shell_sort(int a[], int n)
{
    int i, j, gap;

    for (gap = (n / 2); gap > 0; gap = (gap / 2)) {
        for (i = gap; i < n; i = (i + gap)) {
            for (j = i - gap; (j >= 0) && (a[j] > a[j + gap]); j = (j - gap)) {
                do_swap(&a[j], &a[j + gap]);
            }
        }
    }
    return;
}


// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
static void do_merge_gfg(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays
	int L[n1], R[n2];

	// Copy data to temp arrays L[] and R[]
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Merge the temp arrays back into arr[l..r
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[],
	// if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[],
	// if there are any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void do_merge_sort_gfg(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		// Sort first and second halves
		do_merge_sort_gfg(arr, l, m);
		do_merge_sort_gfg(arr, m + 1, r);

		do_merge_gfg(arr, l, m, r);
	}
}