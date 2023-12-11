#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/** prompt - displays user prompt
*	only terminates on signal calls
*	exit()
*	displays error and then prompt 
* Return: void
*/

int prompt(void)
{
	pid_t child_pid, wt_pid;
		
	unsigned int i = 0;
	int status;
	ssize_t rd_Cmd;
	char *str_Buffer;
	size_t len;

	static char *exec_Args[] = {NULL};
	char *prompt_dec = "zm_ssh:>-> ";
	
	
	
	str_Buffer = NULL;
	len = 0;
	
	while (!i)
	{
		write(1, prompt_dec, strlen(prompt_dec));
		
		
		child_pid = fork(); /** create parallel process */
		
		if (child_pid == -1)
		{
			/** checks if the process is created*/
			perror("Error executing fork");
			return (1);
		}
		
		if (child_pid == 0)
		{
			/** process to wait on */
			rd_Cmd = getline(&str_Buffer, &len, stdin);
			
			if (rd_Cmd == -1)
				perror("Getline");
		}
		else
		{
			/** Father process
			* executes after value is read
			*/
			wt_pid = wait(&status);	
			
			if (wt_pid == -1)
			{
				perror("child process terminated");
				return (1);
			}
			
			/** change this path */
			execve("/bin/ls", exec_Args, NULL);
			perror("Confirm your working directory");
			
			
		}
		
		if (strcmp(str_Buffer, "exit") == 0)
			i = 1;
		free(str_Buffer);
	}	
	return (0);
}
