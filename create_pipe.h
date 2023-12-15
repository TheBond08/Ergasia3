#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 1024

#define UNABLE_TO_CREATE_PIPE 2
#define FORK_FAILED 3
#define DUP2_FAILED 4

void create_pipe(int file);