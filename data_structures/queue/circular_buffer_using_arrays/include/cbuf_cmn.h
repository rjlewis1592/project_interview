#ifndef  CBUF_CMN_H_
#define  CBUF_CMN_H_

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
#include <assert.h>

#define CBUF_OPS_SUCCESS    (0)     // operation on circular buffer successful
#define CBUF_OPS_FAIL       (-1)	// operation on circular buffer failed

#define BUFLEN_8	        8 
#define BUFLEN_16	        16 
#define BUFLEN_24	        24 
#define BUFLEN_32	        32 

typedef struct circular_buffer cbuf_t;

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#ifdef CBUF_DEBUG
#define LOG_DBG(fmt, args...) do { fprintf(stderr, "DEBUG: %s - %d@%s(): " fmt, __FILENAME__, __LINE__, __func__, ##args); printf("\n");} while (0)
#else
#define LOG_DBG(fmt, args...)    /* Don't do anything in release builds */
#endif

#define LOG_ERR(fmt, args...) do { fprintf(stderr, "ERROR: %s - %d@%s(): " fmt, __FILENAME__, __LINE__, __func__, ##args); printf("\n");} while (0)

#endif //  CBUF_CMN_H_
