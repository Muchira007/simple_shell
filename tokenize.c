#include "shell.h"

/**
* _strtoken - provides executable from prompt
* @line: the string to tokenize
* Return: void
*/

void _strtoken(char *line)
{
	const char *del = " \n";
	char *token, *tokenArgs, *strCpy;
	char *fpath = "/bin/";

	strCpy = strdup(line);

	if (strCpy == NULL)
	{
		perror("Could not copy string");
		return;
	}
	token = strtok(strCpy, del);

	if (token != NULL)
	{
		pathFinder(token);

		/**
		* continue to tokenize the string
		* treat them as arguments
		*/

		tokenArgs = strtok(NULL, del);
		while (tokenArgs != NULL)
		{
			_execute(fpath, tokenArgs);
			tokenArgs = strtok(NULL, del);
		}

		free(strCpy);
	}
	else
	{
		free(strCpy);
		perror("invalid command");
	}
}
