#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
/**
 *
 */
int main (void)
{
	char *argumento = NULL;
	size_t len = 0;
	ssize_t aux = 0;
	char *token;
	char s[2] = " ";

	while (1)
	{
		printf("$ ");
		aux = getline(&argumento,&len, stdin);
		token = strtok(argumento, s);
		while (token != NULL)
		{
			printf("%s\n", token);
			token = strtok(NULL, s);
		}
		if (argumento[0] == 27)
		{
			free(argumento);
			exit(0);
		}
	}
	exit(0);
	return (0);
}
