#incloude "process.h"

void p_switch_state(struct process *p)
{
   if (p == NULL)
{
   fprintf(stderr, "Error : Segmantation fault\n");
}
   if(p->p_state ==READY)
{
      p->p_state = RUNNING;
}

   else
{
      p->p_state = READY;
}
}

void p_print(struct process *p)
