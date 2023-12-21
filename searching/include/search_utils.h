#ifndef  SEARH_UTILS_H_
#define  SEARH_UTILS_H_

#include "search_cmn.h"

int get_random_n();
int *create_array(int n);
void do_swap(int *x, int *y);
int* dup_array(int *src, int n);
void print_array(int *a, int n, const char *title);
int do_my_compare(const void *x, const void *y);


#endif // SEARH_UTILS_H_ 