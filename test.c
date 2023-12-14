#include <stdio.h> 
#include <unistd.h>
#include <fcntl.h>

char *message = "This is a message!!!" ;

int main(){
    int p[2];
    char buf[1024];
    
    pipe(p); /*create pipe*/
    if (fork() != 0) { /* I am the parent */
        write(p[1], message, strlen (message) + 1) ;
    }
    else { /*Child code */
        read(p[0], buf, 1024) ;
        printf("Data received through pipe %s\n", buf) ;
    }       

    return 0;
}