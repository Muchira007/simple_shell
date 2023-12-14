#include "shell.h"

void handleEoF(char *line);

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
			handleEoF(line);
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

/**
 * handleEoF - Handle the end-of-file condition.
 * @line: The input line
 */
void handleEoF(char *line)
{
	if (feof(stdin))
	{
		printf("\n");
		if (line != NULL)
			free(line);
		line = NULL;
		return;
	}
	else
	{
		perror("error can' read script");
		if (line != NULL)
			free(line);
		exit(EXIT_FAILURE);
	}
}
