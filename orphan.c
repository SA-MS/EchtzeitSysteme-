#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <errno.h>

#define CHILD  0

void handler(void);

int main()
{
  atexit(handler);
  int p = fork();

  if(p == CHILD ) 
{
    sleep(1);
    printf("Kind:  %u / %u\n",getpid(), getppid());
}
  else if (p > CHILD)
{
    printf("Vater: %u / %u\n",getpid(), getppid());
}
  else 
{
    perror("Fork failed. ");
}
return errno;
}
void handler()
{
char *owner = getlogin();
printf("Goodbye\n");
if(owner) printf("Process owner: %s\n", owner);
else perror("getlogin()");
}



