#include "shell.h"

/**
* prompt - provides console prompt
* Return: void
*/

int prompt(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	printf(":-> ");
	while ((read = getline(&line, &len, stdin)) != -1)
	{
		/**
		* remove newline if it exists
		* replace it with '\0'
		* decrement count to exclude newline
		*/
		if (line[read - 1] == '\n')
		{
			line[read - 1] = '\0';
			read--;
		}

		if (strcmp(line, "exit") == 0)
			break;

		printf(":-> ");
		_strtoken(line);
	}

	free(line);
	return (0);
}
