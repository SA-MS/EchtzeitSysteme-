#include "process.h" 

int main()
{


struct process *test_p = calloc(1,sizeof(struct process));

test_p->p_state = READY;
test_p->p_id = 1; 

while(1)
{
p_print(test_p);
p_switch_state(test_p);
sleep(1);

}

return 0;
}
