#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 
#include "create_pipe.h"

#define UNABLE_TO_OPEN_FILE 1

int main(int argc, char* argv[]){
    int file;

    if((file = open(argv[1], O_RDONLY)) < 0){ // Opens the file to read and checks for errors
        printf("Error opening file\n");
        exit (1);
    }
    printf("Creating pipe\n");
    create_pipe(file); // Calls the function to create the transfer pipe
    printf("Completed!\n");

    close(file);

    return 0;
}