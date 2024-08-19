#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define DELIM " \n"

/**
 *
 */
int main (void)
{
	size_t len = 0;
	ssize_t aux = 0;
	char *token, **arg, *flag, *line = NULL;
	int argc = 0, status, x = 0, i = 0;
	pid_t child;

	while (1)
	{
		/* ------------- Leer el input ------------- */
		printf("$ ");
		aux = getline(&line, &len, stdin);
		if (aux == -1)
			break;
		line[aux] = '\0';
		/* ------------- Tokenizar ------------- */
		
		for (x = 0, argc = 1; line[x] != '\0'; x++)
		{
			if (line[x] == ' ' && line[x + 1] >= 97 && line[x + 1] <= 122)
				argc++;
		}
		arg = malloc(sizeof(char *) * (argc + 2)); /* (char * -> 8 bytes) * 5 = 40 */
		if (arg == NULL)
			break;
		for (i = 0; i <= argc + 1; i++)
			arg[i] = NULL;

		token = strtok(line, DELIM);
		argc = 0;
		while (token != NULL)
		{
			arg[argc] = strdup(token);
			token = strtok(NULL, DELIM);
			argc++;
		}

		for (int a = 0; arg[a] != NULL; a++)
			printf("arg[%d] -> %s\n", a, arg[a]); 
		/* ------------- executar ------------- */
		child = fork();
		if (child == 0)
		{
			if(execve(arg[0], arg, NULL) == -1)
			{
				perror("ERROR");
				exit(0);
			}
		}
		else 
			wait(&status);
		/* ------------- frees ------------- */
		for (i = 0; arg[i] != NULL; i++)
			free(arg[i]);
		free(arg);
	}
	free(line);
	return (0);
}
