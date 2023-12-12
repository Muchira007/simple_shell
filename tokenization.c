#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
 * _print creating a custom printf function
 *
 */
void _print(const char *composition)
{
	write(STDOUT_FILENO, composition, strlen(composition));
}
/**
 * comd_exec - a tokenization function
 * @args:
 * @count:
 *
 */
void comd_exec(char *str_Buffer, char *args[], int count)
{
	char *args[255];
	char *tokenisation = strtok((char *)str_Buffer, "");
	
	while (tokenisation != NULL)
	{
		args[count++] = tokenisation;
		tokenisation = strtok(NULL, "");
	}
	args[count++] = NULL;
	execve(args[0], args);

	_print("error executing .\n");
	exit(EXIT_FAILURE);
}
