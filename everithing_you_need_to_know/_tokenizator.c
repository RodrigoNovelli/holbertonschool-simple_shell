#include "shell.h"
char **tokenizator (char **arg, char *line, int *len)
{
	int x = 0, aux = 0, argc = 0;
	int i = 0;
	char *token = NULL;

	argc = 0;
	for (x = 0, argc = 1; line[x] != '\0'; x++)
	{
		if (line[x] == ' ' || line[x] == '=' || line[x] == ':')
			argc++;
	}
	arg = malloc(sizeof(char *) * (argc + 2)); /* (char * -> 8 bytes) * 5 = 40 */
	if (arg == NULL)
		return (NULL);
	for (i = 0; i <= argc + 1; i++)
		arg[i] = NULL;
	token = strtok(line, DELIM);
	while (token != NULL)
	{
		arg[aux] = strdup(token);
		token = strtok(NULL, DELIM);
		aux++;
	}
	for (aux = 0; arg[aux] != NULL; aux++)
		printf("arg[%d] -> %s\n", aux, arg[aux]);
	return (arg);
}
