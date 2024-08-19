#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
/**
 *
 */
int main(int ac, char **av, char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		printf("The %d enviroment value is: %s\n", i, env[i]);
		i++;
	}
	return (1);
}
