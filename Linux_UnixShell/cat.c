#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

// function to handle cat command with options

void cat(char *dir, int i){
    FILE *fp;
    char c;
    int line = 1;
    fp = fopen(dir, "r");
    if (fp == NULL){
        printf("ERROR: File does not exist");
    }
    else{
        if (i==0){
            while((c=fgetc(fp))!=EOF){
                printf("%c", c);
            }
            printf("\n");
        }
        
        else if(i==1){
            printf("%d ", line);
            while((c=fgetc(fp))!=EOF){
                if (c=='\n'){
                    line++;
                    printf("%c", c);
                    printf("%d ", line);
                }
                else{
                    printf("%c", c);
                }
            }
            printf("\n");
        }
        else if(i==2){
            // display $ sign at the end of each line
            while((c=fgetc(fp))!=EOF){
                if (c=='\n'){
                    printf("$");
                    printf("%c", c);
                }
                else{
                    printf("%c", c);
                }
            }
            printf("$");
        }
    }
    fclose(fp);
}

int main(int argc, char *argv[]){
    long i=strtol(argv[2], NULL, 10);
    char *dir = argv[1];
    cat(dir, i);
    return 0;
}

