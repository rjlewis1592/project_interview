#ifndef  TREE_CMN_H_
#define  TREE_CMN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>

#define TREE_OP_SUCCESS     0       // operation on tree successful
#define TREE_OP_FAIL     (-1)	    // operation on tree failed

#define BUFLEN_8	        8 
#define BUFLEN_16	        16 
#define BUFLEN_24	        24 
#define BUFLEN_32	        32 


#define TREE_MAX(a, b)           ((a) > (b) ? (a) : (b))
#define TREE_MIN(a, b)           ((a) < (b) ? (a) : (b))

typedef struct bst_node bst_node_t;

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#ifdef TREE_DEBUG
#define LOG_DBG(fmt, args...) do { fprintf(stderr, "DEBUG: %s - %d@%s(): " fmt, __FILENAME__, __LINE__, __func__, ##args); printf("\n");} while (0)
#else
#define LOG_DBG(fmt, args...)    /* Don't do anything in release builds */
#endif // TREE_DEBUG


#define LOG_ERR(fmt, args...) do { fprintf(stderr, "ERROR: %s- %d@%s(): " fmt, __FILENAME__, __LINE__, __func__, ##args); printf("\n");} while (0)

#endif //  TREE_CMN_H_
