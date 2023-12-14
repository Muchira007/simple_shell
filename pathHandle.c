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
	char *tokenArgs = "default_value";

	env = environ;

	if (stat(tokencpy, &st) == 0)
	{
		printf("Found here:%s", tokencpy);
		fpath = strdup(tokencpy);
	}
	else
	{
		while (*env != NULL)
		{
			if (strstr(*env, tokencpy))
			{
				printf("found here: %s", *env);
				fpath = *env;
			}
			env++;
		}
	}
	if fpath != NULL && (access(fpath, X_OK) == 0)
	{
		printf("Executable: %s\n", fpath);
		_execute(fpath, tokenArgs);
		
		free(fpath);
		return;
	}
	free(tokencpy);
}
