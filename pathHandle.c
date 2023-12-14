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
			if (strstr(*env, tokencpy))
				fpath = *env;
			env++;
		}
	}
	if (fpath != NULL && (access(fpath, X_OK) == 0))
	{
		_execute(fpath, NULL);
		free(fpath);
		return;
	}
	free(tokencpy);
}
