#ifndef  STACK_DEFS_H_
#define  STACK_DEFS_H_

// list entry definition
struct stack_entry {
    int data;
    struct stack_entry *next;   
};

#endif //  STACK_DEFS_H_