#include "shell.h"

/**
* _execute - executes the set commands
* @token: the executable (e.g ls)
*	ls -la
* @tokenArgs: the arguments (e.g -la)
* Return: void
*/


/*
* Description for * 1 *
* dynamincally allocate mmeory to handle
* the set pointers and arguments
* NULL indicaes termination of Array
*/

void _execute(char *token, char *tokenArgs)
{
	pid_t childPid;
	int status, stNum;

	childPid = fork();

	if (childPid == -1)
	{
		perror("Couldn't ran parallel processes");
		exit(EXIT_FAILURE);
	}

	if (childPid == 0)
	{
		/* 1 */
		char *envArgs[] = {NULL};
		char **newArgs = malloc(sizeof(char *) * (2 + 1));

		if (newArgs == NULL)
		{
			perror("Error allocating memory");
			exit(EXIT_FAILURE);
		}

		newArgs[0] = token;
		newArgs[1] = tokenArgs;
		newArgs[2] = NULL;

		execve(token, newArgs, envArgs);

		perror("Command Execution Fail");
		exit(EXIT_FAILURE);
		free(newArgs);
	}
	else
	{
		stNum = wait(&status);

		if (stNum == -1)
			perror("Error Terminating Child");
	}
}