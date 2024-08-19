#include "shell.h"
#define DELIM " \n"
#define PROMPT "$ "

/**
 *
 */
int main(int ac, char **av, char **env)
{
	size_t len = 0;
	ssize_t aux = 0;
	char **arg = NULL, *line = NULL;
	int status, x = 0, i = 0;
	int *argc = NULL;
	pid_t child = 0;

	while (1)
	{
		/* ------------- Leer el input ------------- */
		printf(PROMPT);
		aux = getline(&line, &len, stdin);
		if (aux == -1)
			break;
		line[aux] = '\0';
		/* ------------- Tokenizar ------------- */
		
		/* for (x = 0, argc = 1; line[x] != '\0'; x++)
		{
			if (line[x] == ' ' && line[x + 1] >= 97 && line[x + 1] <= 122)
				argc++;
		}
		arg = malloc(sizeof(char *) * (argc + 2));
		if (arg == NULL)
			return (NULL);
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
		arg = tokenizator(arg, line, argc);
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
