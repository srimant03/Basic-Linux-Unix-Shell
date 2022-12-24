#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

// function to handle ls command
void ls(char *dir, long l, long a){
    DIR *d=opendir(dir);
    struct dirent *dr;
    if (!d){
        if (errno == ENOENT){
            printf("ERROR: Directory does not exist");
        }
        else if (errno == ENOTDIR){
            printf("ERROR: Not a directory");
        }
        else{
            printf("Error");
        }
    }
    else{
        if (l==0 && a==1){
            while((dr=readdir(d))!=NULL){
                printf("%s ", dr->d_name);
            }
            printf("\n");
        }
        else if (l==0 & a==0){
            while((dr=readdir(d))!=NULL){
                if ((dr->d_name)[0]!='.'){
                    printf("%s ", dr->d_name);
                }
            }
            printf("\n");
        }
        else if (l==1 & a==0){
            while((dr=readdir(d))!=NULL){
                printf("%s ", dr->d_name);
                printf("\n");
            }
        }
    }
    closedir(d);
}

int main(int argc, char *argv[]){
    long l=strtol(argv[2], NULL, 10);
    long a=strtol(argv[3], NULL, 10);
    //printf("%ld",l);
    //printf("%ld",a);
    //printf("hello");
    //printf("\n");
    ls( ".", l,a);
}

