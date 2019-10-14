#include "process.h"

/* Implemetierung */ 

void p_switch_state(struct process *p)
{

   if (p == NULL)
{
     fprintf(stderr,"Error : Segmantation fault\n");
}
   if(p->p_state == READY)
{
      p->p_state = RUNNING;
} 
   else 
{
      p->p_state = READY;
}
}

void p_print(struct process *p)
{
    printf("%10u |  " , p->p_id);
   if (p->p_state == READY )
{
      printf("READY\n");
}
   else
{
      printf("RUNNING\n");
}
}

