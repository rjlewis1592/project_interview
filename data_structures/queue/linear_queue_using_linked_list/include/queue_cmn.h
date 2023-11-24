#ifndef  QUEUE_COMMON_H_
#define  QUEUE_COMMON_H_

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

#define QUEUE_OP_SUCCESS     0       // operation on queue successful
#define QUEUE_OP_FAIL     (-1)	// operation on queue failed

#define BUFLEN_8	        8 
#define BUFLEN_16	        16 
#define BUFLEN_24	        24 
#define BUFLEN_32	        32 

typedef struct queue queue_t;

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#ifdef QUEUE_DEBUG
#define LOG_DBG(fmt, args...) do { fprintf(stderr, "DEBUG: %s - %d@%s(): " fmt, __FILENAME__, __LINE__, __func__, ##args); printf("\n");} while (0)
#else
#define LOG_DBG(fmt, args...)    /* Don't do anything in release builds */
#endif // QUEUE_DEBUG


#define LOG_ERR(fmt, args...) do { fprintf(stderr, "ERROR: %s- %d@%s(): " fmt, __FILENAME__, __LINE__, __func__, ##args); printf("\n");} while (0)

#endif //  QUEUE_COMMON_H_
