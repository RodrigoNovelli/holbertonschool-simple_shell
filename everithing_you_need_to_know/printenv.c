#include "shell.h"
/*
 *
 *
 **/
int main(int ac, char **av, char **env)
{
        int i = 0;
        char *PATH = NULL;
        char **dirs;
        int *len;
	char *command = "/ls";
        while (env[i] != NULL)
        {
                if (env[i][0] == 'P' && env[i][1] == 'A')
                {
                        printf("The path value is %s \n", env[i]);
                        PATH = strdup(env[i]);
                        printf(" The PATH VARIABLE is: %s \n", PATH);
                }
                i++;
        }
        dirs = tokenizator(dirs, PATH, len);
	for (i = 1; dirs[i] != NULL; i++)
        {
                printf("Directory %d : %s\n", i, dirs[i]);
		strcat(dirs[i], command);
		printf("This is the command %s", dirs[i]);
		if (access(dirs[i], X_OK) == 0)
			printf("Me ejecuto con exito, soy: %s\n", dirs[i]); // aca tirar exiecve
		else
			printf("Perdon no me ejecuto :("); // este else no va, reemplasar por else adentro del execve para el error tendria que quedar for(dirs++) - if acces() - adentro del if acceces un fork execve con if para error
        }
	// si iteraste todo el path y no encontraste el commando printear command not found
        return (1);
}
