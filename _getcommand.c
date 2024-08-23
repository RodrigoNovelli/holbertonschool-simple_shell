#include "shell.h"
/*
 *
 *
 **/
char *_getcommand(char **env, char *input)
{
        int i = 0, x = 0;
        char *PATH = NULL, **dirs = NULL, *command = NULL;
	/*-----------Recorre las env var y encuentra path--------*/
        while (env[i] != NULL)
        {
		if (env[i][0] == 'P' && env[i][1] == 'A')
		{
			PATH = strdup(env[i]);  /*duplica path*/
                }
                i++;
        }
	/*---Tokeniza las capretas----*/
        dirs = tokenizator(dirs, PATH);
	/*---- agrega / al comienzo del argumento -----*/
	for (x = 0; input[x] != 0; x++)
		;
	command = malloc(sizeof(char) * (x + 1));

	if (command == NULL)
	{
		for (i = 0; dirs[i] != NULL; i++)
			free(dirs[i]);
		free(dirs);
		free(PATH);
	}

	command[0] = '/';
	for (x = 1, i = 0; input[i] != 0; x++)
	{
		command[x] = input[i];
		i++;
	}
	/*-----Lo concatena con cada capeta y checkea si es ejecutable------*/
	for (i = 1; dirs[i] != NULL; i++)
        {
		strcat(dirs[i], command);
		if (access(dirs[i], X_OK) == 0)
		{
			command = strdup(dirs[i]);
			for (i = 0; dirs[i] != NULL; i++)
				free(dirs[i]);
			free(dirs);
			free(PATH);
			return (command);
		}
	}
	printf("Command not found x.x");
	for (i = 0; dirs[i] != NULL; i++)
		free(dirs[i]);
	free(dirs);
	free(PATH);
        return (NULL);
}
