#include <stdio.h>
#include <unistd.h>
main()
{
	int pid,pid1,pid2;
	pid=fork();
	if (pid==-1)
	{
		printf(" Error in process creation");
		exit(1);
	}
	if (pid!=0)
	{
		pid1=getpid();
		printf("The parent process Id is %d",pid1);
	}
	else
	{
		pid2=getpid();
		printf("the child process Id is %d",pid2);
	}
}
