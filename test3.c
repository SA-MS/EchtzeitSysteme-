#include "processmodel.h"

int main()
{

struct pctx *p_ctx = calloc(1,sizeof(struct pctx));
struct queue *q_test = calloc(1,sizeof(struct queue));
struct process *p_test = calloc(1,sizeof(struct process));
p_ctx->qready = q_test;
p_test->p_state = RUNNING;
p_test->p_id = 1;
p_ctx->running = p_test;
q_remove(q_test);
for (int i = 2; i<=10 ; i++)
{
struct process *p_test = calloc(1,sizeof(struct process));
p_test->p_state = READY;
p_test->p_id = i;
if (p_test->p_state == READY)
{
	q_add(q_test,p_test);
}
}
while(1)
{
	print(p_ctx);
	step(p_ctx);
	sleep(1);
}

return 0;
}


