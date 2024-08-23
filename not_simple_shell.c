#include "shell.h"
#define PROMPT "$ "

/**
 *
 */
int main(int ac, char **av, char **env)
{
	size_t len = 0;
	ssize_t aux = 0;
	char **arg = NULL, *line = NULL, *command = NULL;
	int status, x = 0, i = 0, *argc = NULL;
	pid_t child = 0;

	while (1)
	{
		/* ------------- Leer el input ------------- */
		printf(PROMPT);
		aux = getline(&line, &len, stdin);
		if (aux == -1)
			break;
		line[aux] = '\0';
		/* ------------- executar ------------- */
		arg = tokenizator(arg, line, argc);
		if (line[0] == '/')
			command = arg[0];
		else
			command = _getcommand(env, arg[0]);
		if (command != NULL)
		{
			child = fork();
			if (child == 0)
			{
				if(execve(command, arg, NULL) == -1)
				{
					perror("ERROR");
					exit(0);
				}
			}
			else 
				wait(&child);
		/* ------------- frees ------------- */
			for (i = 0; arg[i] != NULL; i++)
				free(arg[i]);
			free(arg);
		}
	}
		free(line);
		return (0);
}
