#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/types.h>
#include <sys/wait.h>

#include "create_pipe.h"

int main(int argc, char* argv[]){
    int file;

    if((file = open(argv[1], O_RDONLY)) < 0){ // Opens the file and checks for errors
        printf("Error opening file\n");
        exit (1);
    }
    printf("Creating pipe\n");
    create_pipe(file); // Calls the function to create the transfer pipe
    printf("Transfer complete\n");

    close(file);

    return 0;
}