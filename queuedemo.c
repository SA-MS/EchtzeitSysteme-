#include "queue.h"

int main()
{

struct queue *q_test = calloc(1,sizeof(struct queue));

for(int i=0 ; i<10 ; i++)
{

struct process *p_test = calloc(1,sizeof(struct process));


p_test->p_id = i;
p_test->p_state = READY;

q_add(q_test,p_test);
q_print(q_test);
sleep(1);
}
for(int i=0 ; i<10 ; i++)
{

q_remove(q_test);
q_print(q_test);
sleep(1);
}

return 0;
}
