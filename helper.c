#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 1024


void create_pipe(int sf){
    int p[2];
    char buf[SIZE];

    if(pipe(p) == -1){
        printf("Pipe creation failed");
        exit(1);
    }

    pid_t pid = fork();

    if(pid < 0){
        printf("Failed to fork");
        exit(1);
    }

    if (pid > 0){ // Parent process
        close(p[1]);

        if (dup2(p[0], STDIN_FILENO) == -1){
            printf("dup2 failed");
            exit(1);
        }

        close(p[0]);

        while ((fgets(buf, 1024, stdin)) != NULL){
            printf("Data received through pipe %s", buf);
        }
 
        wait(NULL); // Waits for the child process to terminate
    } else{ // Child process
        close(p[0]);

        if(dup2(p[1], STDOUT_FILENO) == -1){
            printf("dup2 failed");
        }

        close(p[1]);

        if(dup2(sf, STDIN_FILENO) == -1){
            printf("dup2 failed");
            exit(1);
        }

        execl("/usr/bin/sort", "sort", "-n", (char *)NULL);

    }
}

int main(int argc, char* argv[]){
    int sf;

    if((sf = open(argv[1], O_RDONLY)) < 0){ // Opens the file and checks for errors
        printf("Error opening file\n");
        exit (1);
    }
    printf("Creating pipe\n");
    create_pipe(sf); // Calls the function to create the transfer 
    printf("Transfer complete\n");

    close(sf);

    return 0;
}