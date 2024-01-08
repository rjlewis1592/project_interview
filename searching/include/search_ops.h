#ifndef SEARCH_OPS_H_
#define SEARCH_OPS_H_

bool do_linear_search(int arr[], int n, int key, int *pos);
bool do_recursive_binary_search(int arr[], int n, int key, int *pos);
bool do_iterative_binary_search(int arr[], int n, int key, int *pos);
int find_largest(int arr[], int n);
int find_second_largest(int arr[], int n);
int find_smallest(int arr[], int n);
#endif // SEARCH_OPS_H_
