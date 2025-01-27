#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
int status,pid,child_pid;
pid=fork();
if(pid==-1)
{
printf("Child process creation failed");
return -1;
}
else if(pid==0)
{
printf("inside the child process with PID:%d\n",getpid());
execlp("/bin/date","date",NULL);
return 0;
}
else
{
child_pid=wait(&status);
printf("Inside parent process with PID:%d",getpid());
printf("Child process complete");
return 0;
}
}

