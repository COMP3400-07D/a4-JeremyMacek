#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {
    if (argc < 2){
        printf("ERROR: No arguments");
        return 1;
    }

    pid_t pid = fork();

    if (pid > 0){

        int status = 0;
        wait(&status);

        if (WIFEXITED(status)){
            int code = WEXITSTATUS(status);
            if (code == 0){
                printf("FOUND: %s\n", argv[1]);
                return 0;
            }
            else if (code == 1){
                printf("NOT FOUND: %s\n", argv[1]);
                return 0;
            }
            else if (code == 2){
                printf("ERROR: %s Does not exist\n", argv[2]);
                return 1;
            }
            else{
                printf("ERROR: Child process didn't exit normally\n");
                return 1;
            }
        }

    }
    else if (pid == 0){

        char *const args[] = {"grep", "-sq", argv[1], argv[2], NULL};
        execv("/usr/bin/grep", args);

        perror("execv failed");
        exit(2);
    }
    else{
        perror("Fork failed");
        return 1;
    }

    return 0;
}
