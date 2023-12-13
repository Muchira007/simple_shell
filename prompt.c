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

	while (1)
	{
		printf(":-> ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				free(line);
				return (0);
			}
			else
			{
			perror("error can' read script");
			free(line);
			exit(EXIT_FAILURE);
		}
	}
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

		_strtoken(line);
	}

	free(line);
	return (0);
}
