#ifndef  QUEUE_DEFS_H_
#define  QUEUE_DEFS_H_

/* Definition of node */
struct node {
	int data;
	struct node *next;
};

typedef struct node node_t;

struct queue {
	node_t *head; // remove from head
	node_t *tail; // add at tail
};
#endif //  QUEUE_DEFS_H_
