#include "create_pipe.h"

void create_pipe(int file){
    int pipes[2];
    char buf[SIZE];

    if(pipe(pipes) == -1){ // Checks if the pipe creation has succeeded
        printf("Pipe creation failed");
        exit(1);
    }

    pid_t pid = fork();

    if(pid < 0){ // Checks if the fork process succeeded
        printf("Fork failed");
        exit(1);
    }

    if (pid > 0){ // Parent process
        close(pipes[1]);

        if (dup2(pipes[0], STDIN_FILENO) == -1){
            printf("dup2 failed");
            exit(1);
        }

        close(pipes[0]);

        while ((fgets(buf, SIZE, stdin)) != NULL){
            printf("Data received through pipe %s", buf);
        }
 
        wait(NULL); // Waits for the child process to terminate
    } else{ // Child process
        close(pipes[0]);

        if(dup2(pipes[1], STDOUT_FILENO) == -1){
            printf("dup2 failed");
        }

        close(pipes[1]);

        if(dup2(file, STDIN_FILENO) == -1){
            printf("dup2 failed");
            exit(1);
        }

        execl("/usr/bin/sort", "sort", "-n", (char *)NULL); // Runs the command sort -n for the file

    }
}