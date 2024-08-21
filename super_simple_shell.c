#include "shell.h"
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
		arg = tokenizator(arg, line, argc);
		child = fork();
		/* --------------executttte---------------- */
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
		/* ------------------- frees ------------- */
		for (i = 0; arg[i] != NULL; i++)
			free(arg[i]);
		free(arg);
	}
	free(line);
	return (0);
}
