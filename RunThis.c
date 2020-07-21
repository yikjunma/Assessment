#include <stdio.h>   /* printf, stderr, fprintf */
#include <sys/types.h> /* pid_t */
#include <unistd.h>  /* _exit, fork */
#include <stdlib.h>  /* exit */
#include <errno.h>   /* errno */
#include <sys/wait.h>
#include <string.h>

void main(void)
{
   	pid_t  pid, roscorepid;
	
	
	pid = fork();

	if (pid < 0)
        	exit(EXIT_FAILURE);
    
    	if (pid > 0)
	{
		system("roscore");
		
		exit(EXIT_SUCCESS);
	}
       		
    	if (setsid() < 0)
	{exit(EXIT_FAILURE);}

       	sleep(4);
	pid = fork();
    
    	if (pid < 0)
        	exit(EXIT_FAILURE);
    
    	if (pid > 0)
    	{
		system("gnome-terminal -- bash -c 'rostopic echo /cmd_vel'");
		system("rosrun husky_clockwise clockwise");
		system("rosrun husky_anti_clockwise anticlockwise.py");
        	exit(EXIT_SUCCESS);
    	}		
}
