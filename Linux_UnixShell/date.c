#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>

// print current day, date and time
void date(long option){
    if (option==0){
        //display local time and date
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        //printf("%d-%d-%d %d:%d:%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        printf("%s", asctime(&tm));
    }
    else if (option==1){
        //display UTC time
        time_t t = time(NULL);
        struct tm tm = *gmtime(&t);
        printf("%s", asctime(&tm));
    }
    else if (option==2){
        // display date in format of mm/dd/yyyy
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("%d-%d-%d",tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900);
        printf("\n");
    }
}

// driver code
int main(int argc, char *argv[]){
    long option=strtol(argv[1], NULL, 10);
    date(option);
    return 0;
}