#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

// function to handle rm command to delele files in directory
void rm(char *dir, long i){
    if (i==1){
        //give prompt before removing
        char c;
        printf("Are you sure you want to delete %s? (y/n): ", dir);
        if(scanf("%c", &c));
        if (c=='y'){
            int check = remove(dir);
            if (!check){
                //printf("File deleted");
            }
            else{
                printf("Error: Command not found");
                printf("\n");
            }
        }
        else{
            
        }
    }
    else if (i==2){
        // give prompt if more than 3 files are to be deleted

    }
    else if (i==0){
        int check = remove(dir);
        if (!check){
            //printf("File deleted");
        }
        else{
            printf("Error: Command not found");
            printf("\n");
        }
    }
}

//driver code
int main(int argc, char *argv[]){
    long i=strtol(argv[2], NULL, 10);
    char *dir = argv[1];
    rm(dir,i);
    return 0;
}

    