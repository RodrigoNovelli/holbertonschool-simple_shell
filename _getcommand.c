#include "shell.h"
/*
 *
 *
 **/
char *_getcommand(char **env, char *input)
{
        int i = 0, dirlen = 0, tlen = 0;
        char *PATH = NULL, **dirs = NULL, *command = NULL, *path = NULL;
	/*-----------Recorre las env var y encuentra path--------*/
        while (env[i] != NULL)
        {
		if (env[i][0] == 'P' && env[i][1] == 'A')
		{
			PATH = strdup(env[i]);  /*duplica path*/
                }
                i++;
        }
	/*---- agrega / al comienzo del argumento -----*/
        dirlen = strlen(input);
        command = malloc(sizeof(char) * (dirlen + 2));
        if (command == NULL)
        {
                free(PATH);
                return (NULL);
        }
        command[0] = '/';
	command[1] = '\0';
        strcat(command, input);
	printf("str command %s\n", command); /* print */
        /*---Tokeniza las capretas----*/
        dirs = tokenizator(dirs, PATH);
        /*-----Lo concatena con cada capeta y checkea si es ejecutable------*/
        for (i = 1; dirs[i] != NULL; i++)
        {
                tlen = strlen(dirs[i]) + dirlen;
                path = malloc(sizeof (char) + (tlen + 3));
		path[0] = '\0';
		strcat(path, dirs[i]);
		strcat(path, command);
		printf("this is path = %s\n", path);
                if (path == NULL)
                {
                        for (i = 0; dirs[i] != NULL; i++)
                                free(dirs[i]);
                        free(dirs);
                        free(PATH);
                        free(command);
                        return (NULL);printf("str path %s\n", path);
		}
                if (access(path, X_OK) == 0)
                {
                        for (i = 0; dirs[i] != NULL; i++)
                                free(dirs[i]);
                        free(dirs);
                        free(PATH);
                        free(command);
                        return (path);
                }
                else
                        continue;
        }
        printf("Command not found x.x");
        for (i = 0; dirs[i] != NULL; i++)
                free(dirs[i]);
        free(dirs);
        free(PATH);
        free(command);
        free(path);
        return (NULL);
}
