#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 *
 */
int main ()
{
	char *argumento = NULL;
	size_t len = 0;
	ssize_t aux = 0;

	while (1)
	{
		printf("$ ");
		aux = getline(&argumento,&len, stdin);
		printf("%s", argumento);
		if (argumento[0] == 27)
		{
			free(argumento);
			exit(0);
		}
	}
	exit(0);
	return (0);
}
