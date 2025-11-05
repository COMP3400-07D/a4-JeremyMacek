#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

// TODO: Include more header files (read the manpages to find out more!)

int main(int argc, const char* argv[]) {

    if (argc < 2){
        printf("ERROR: No arguments");
        return 1;
    }

    if ((argc - 1) % 2 == 0){
        int items = argc / 2;

        char * args[] = {"echo", argv[items], argv[items + 1], NULL};
        int eret = execv("/bin/echo", args);

        if (eret == -1){
            perror("exec");
            return 1;
        } 
    }
    else{
        int items = argc / 2;

        char * args[] = {"echo", argv[items], NULL};
        int eret = execv("/bin/echo", args);

        if (eret == -1){
            perror("exec");
            return 1;
        }
    }

    return 0;
}
