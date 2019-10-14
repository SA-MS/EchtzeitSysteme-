#include "queue.h" 

void q_add(struct queue *q, struct process *p)
{
   if (q == NULL || p == NULL)
{
	fprintf(stderr,"Error : NULL zeiger in q_add");
	
}

	struct q_node *e = calloc(1,sizeof(struct q_node));
	e->p = p;

	if (q->end != NULL)
{
	  q->end->next = e;
	  q->end = e;
}
	else if (q->start == NULL)
{
	  q->start = e;
      q->end = e;
}
	else
{
	fprintf(stderr,"Error : Warteschlange Zeiger in q_add");
	
}
}

struct process *q_remove(struct queue *q)
{
	if(q == NULL)
{
	  printf("Error : NULL Zeiger in q_remove");

}
	if(q->start == NULL)
{
	  q->end = NULL;
          return NULL;
}
	if(q->start->p == NULL)
{
	  fprintf(stderr,"Error : NULL Zeiger in q_remove ; q->start->p");
	  
}
	struct process *p = q->start->p;
	struct q_node *e = q->start;

	if(q->start->next != NULL)
{
	  q->start = q->start->next;
}
	else 
{
	  q->start = NULL;
	  q->end = NULL;
}
	free(e);
	return p;
}

void q_print(struct queue *q)
{
	if(q == NULL)
{
	  fprintf(stderr,"Error : NULL Zeiger in q_print ");

}
//	printf("\n---------------------------\n");
//	printf("Process ID  | Process state\n");
	struct q_node *e = q->start ;
	
	for(; e != NULL ; e = e->next)
{
	p_print(e->p);
}
}





