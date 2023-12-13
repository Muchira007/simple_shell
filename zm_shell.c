#include "shell.h"

/**
* main - simple shell main
* Return: - 0 Success
*/

int main(void)
{
	while (1)
	{
		if (prompt() == 0)
		{
			break;
		}
	}
	return (0);
}
