#include "shell.h"

/**
* _execute - executes the set commands
* @tokenArgs: the arguments (e.g -la)
* @fpath: the path of the file
* Return: void
*/


/*
* Description for * 1 *
* dynamincally allocate mmeory to handle
* the set pointers and arguments
* NULL indicaes termination of Array
*/

void _execute(char *fpath, char *tokenArgs)
{
	pid_t childPid;
	int status, stNum;
	char *_fpath;


	_fpath = strdup(fpath);
	childPid = fork();

	if (childPid == -1)
	{
		perror("Couldn't ran parallel processes");
		exit(EXIT_FAILURE);
	}

	if (childPid == 0)
	{
		char *envArgs[] = {NULL};
		char **newArgs = {NULL};

		newArgs[0] = _fpath;
		newArgs[1] = tokenArgs;
		newArgs[2] = NULL;

		execve(newArgs[0], newArgs, envArgs);
		perror("Command Execution Fail");
		exit(EXIT_FAILURE);
	}
	else
	{
		stNum = wait(&status);

		if (stNum == -1)
			perror("Error Terminating Child");
	}
	free(_fpath);
}
