#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, const char* argv[]) {
    
    if (argc < 2){
        printf("ERROR: No arguments");
        return 1;
    }

    for (int i = 1; i < argc; i++){
        const char* word = argv[i];
        
        
        for (int j = 0; word[j] != '\0'; j++){
            printf("%c", toupper(word[j]));
        }

        if (i < argc - 1){
            printf(",");
        }
    }
    printf("\n");
    return 0;
}
