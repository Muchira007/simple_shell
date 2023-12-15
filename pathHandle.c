#include "shell.h"
/**
 * pathFinder - reads the path
 * @token: ...
 * end
 */

void pathFinder(char *token)
{
	struct stat st;
	char **env;
	char *fpath = NULL;
	char *tokencpy = strdup(token);

	env = environ;
	if (stat(tokencpy, &st) == 0)
		fpath = strdup(tokencpy);
	else
	{
		while (*env != NULL)
		{
			fpath = malloc(strlen(*env) + strlen("/") + strlen(tokencpy) + 1);
			if (fpath == NULL)
			{
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
			}

			strcpy(fpath, *env);
			strcat(fpath, "/");
			strcat(fpath, tokencpy);
			if (access(fpath, X_OK) == 0)
			{
				break;
			}
			else
			{
				free(fpath);
				fpath = NULL;
			}
			env++;
		}
	}
	if (fpath != NULL)
	{
		_execute(fpath, NULL);
		free(fpath);
	}
	free(tokencpy);
}
