#include "processmodel.h"


void print(struct pctx *ctx)
{
	if(ctx == NULL || ctx->running == NULL)
{
	  fprintf(stderr,"Error: Null pointer in print\n");
}

	printf("Process ID | Process State\n");
	printf("Laufende Prozess : \n");
        p_print(ctx->running);
	printf("Warteschlange Proczesse : \n");
	q_print(ctx->qready);
}


void step(struct pctx *ctx)
{
        if(ctx == NULL || ctx->running == NULL)
{
        fprintf(stderr,"Error: Null pointer in step\n");
}

	if(ctx->running->p_state != RUNNING)
{
	printf("Error : Laufende Prozess laueft nicht \n");
}

	q_add(ctx->qready,ctx->running);
	p_switch_state(ctx->running);
	ctx->running = q_remove(ctx->qready);
	ctx->running->p_state = RUNNING;
}
