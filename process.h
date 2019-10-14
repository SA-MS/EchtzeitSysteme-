#ifndef PROCESS_H
#define PROCESS_H



#include <stdlib.h>
#include <unistd.h>   /* Includes */
#include <stdint.h>
#include <stdio.h>

enum state {
READY = 0,
RUNNING = 1
};

struct process {
uint32_t p_id;
enum state p_state;
};

void p_switsch_state(struct process *p);
void p_print(struct process *p);

#endif
