#ifndef  SORT_CMN_H_
#define  SORT_CMN_H_

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
#include <stdint.h>

#define SORT_OPS_SUCCESS     (0)
#define SORT_OPS_FAILURE     (-1)

#define BUFLEN_8	        8U
#define BUFLEN_16	        16U
#define BUFLEN_24	        24U
#define BUFLEN_32	        32U
#define BUFLEN_64	        64U
#define BUFLEN_128	        128U
#define BUFLEN_256	        256U
#define BUFLEN_512	        512U
#define BUFLEN_1024	        1024U

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#ifdef SORT_OPS_DEBUG
#define LOG_DBG(fmt, args...) do { fprintf(stderr, "DEBUG: %s - %d@%s(): " fmt, __FILENAME__, __LINE__, __func__, ##args); printf("\n");} while (0)
#else
#define LOG_DBG(fmt, args...)    /* Don't do anything in release builds */
#endif


#define LOG_ERR(fmt, args...) do { fprintf(stderr, "ERROR: %s - %d@%s(): " fmt, __FILENAME__, __LINE__, __func__, ##args); printf("\n");} while (0)

#endif // SORT_CMN_H_
