#ifndef  CBUF_DEFS_H_
#define  CBUF_DEFS_H_

/* circular queue structure */
struct circular_buffer {
	int *buffer; 
	int bufsz;
	int read_idx;
	int write_idx;
};
#endif //  CBUF_DEFS_H_