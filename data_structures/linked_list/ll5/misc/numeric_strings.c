#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>   // for the typedefs (redundant, actually)
#include <limits.h>
#include <assert.h>
#include <inttypes.h> // for the macros

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define LIST_DEBUG

#ifdef LIST_DEBUG
#define LOG_DBG(fmt, args...) do { fprintf(stderr, "DEBUG: %s - %d@%s(): " fmt, __FILENAME__, __LINE__, __func__, ##args); printf("\n");} while (0)
#else
#define LOG_DBG(fmt, args...)    /* Don't do anything in release builds */
#endif

#define LOG_ERR(fmt, args...) do { fprintf(stderr, "ERROR: %s- %d@%s(): " fmt, __FILENAME__, __LINE__, __func__, ##args); printf("\n");} while (0)

int conv_numstr_to_int(char *nptr, int base, int *out_val)
{	
	long result = 0;
	char *endptr = NULL;

	if ((nptr == NULL) || (out_val == NULL)) {
		LOG_ERR("nptr %p, endptr %p, out_val %p", nptr, endptr, out_val);
		return -1;
	}

	if (base != 10) {
		LOG_ERR("base %d - cannot be handled", base);
		return -1;
	}

	errno = 0;
	result = strtol(nptr, &endptr, 0);

	LOG_DBG("nptr \"%s\", endptr \"%s\", result %ld, errno %d, strerror(errno) \"%s\"\n", nptr, endptr, result, errno, strerror(errno));

	if (nptr == endptr) {
		LOG_ERR("NAN \"%s\", result %ld", nptr, result);
		return -1;
	}

    if (*endptr != '\0') {
        LOG_ERR("Further characters after number: \"%s\"", endptr);
		return -1;
	}

	if ((result == LONG_MAX || result == LONG_MIN) && (errno == ERANGE))
	{
    	// out of range, handle or exit
		LOG_ERR("OUT OF RANGE\n");
		return -1;
	}

	if (result >= INT_MAX) {
		LOG_ERR("Again overflow! result (%ld) > INT _MAX", result);
		return -1;
	}
 	/* If we got here, strtol() successfully parsed a number. */
    LOG_ERR("strtol() returned %ld\n", result);

	*out_val = (int)result; 
	return 0;

}
int main(int argc, char *argv[])
{
	int8_t a;
	int8_t x; 
	int8_t y;
	uint_fast16_t b;
	int8_t i8 = INT8_MIN;
	char *str = NULL;
	char *endptr = NULL;
	int result = 0xDEADBEEF;
	int base = 0;
	int ret = 0;

	if (argc != 3)  {
		LOG_ERR("Usage: <a.out> <numeric_string> <base>");
		exit (EXIT_FAILURE);
	}

	str = argv[1];
	base = atoi(argv[2]);

	printf("str \"%s\"\n", str);
	//printf("INT8_MIN %d, INT8_MAX %d\n", INT8_MIN, INT8_MAX);

	x = INT8_MIN;
	y = INT8_MAX;
	printf("INT8_MIN %" PRIi8 ", INT8_MAX %" PRIi8 "\n", x, y);


	a = 1;
	b = 2;
	printf("A = %" PRIi8 ", B = %" PRIuFAST16 "\n", a, b);


	printf("sizeof(int) 	%zu bytes\n", sizeof(long));
	printf("sizeof(long) 	%zu bytes\n", sizeof(long));

	ret = conv_numstr_to_int(str, base, &result);
	if (ret < 0) {
		LOG_ERR("Error - conv_numstr_to_int()");
		exit (EXIT_FAILURE);
	}

	printf("str \"%s\", result %d\n", str, result);

	return 0;
}
