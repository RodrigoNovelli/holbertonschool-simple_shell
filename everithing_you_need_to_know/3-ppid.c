#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/**
 *
 */

int main(void)
{
pid_t my_pid;
pid_t parent;

my_pid = gitpid();
parent = getppid();

printf("PID: %u, PPID: %u\n", my_pid, parent);
return (0);
}
