#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

// function to handle mkdir command
void mkdir1(char *dir, long i){
    if (i==0){
        int check = mkdir(dir, 0777);
        if (!check){
            
        }
        else{
            printf("Error");
        }
    }
    else if (i==1){
        // give verbose after creating
        int check = mkdir(dir, 0777);
        if (!check){
            printf("Created Directory %s", dir);
            printf("\n");
        }
        else{
            printf("Error");
        }
    }
}


//driver code
int main(int argc, char *argv[]){
    long i=strtol(argv[2], NULL, 10);
    char *dir = argv[1];
    //printf("%ld", i);
    mkdir1(dir, i);
    return 0;
}