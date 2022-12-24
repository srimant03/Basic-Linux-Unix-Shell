#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <pthread.h>
#include <sys/wait.h>

// generate shell prompt for user
void printPrompt()
{
    char cwd[1024];
    if(getcwd(cwd, sizeof(cwd)));
    printf("%s >>$ ", cwd);
}

// take input from stdin
void takeInput(char *str)
{
    int max;
    if(fgets(str, 100, stdin));
}

void printTokens(char **tokens){
    int j = 0;
    while(tokens[j]!=NULL){
        printf("%s", tokens[j]);
        printf("\n");
        j++;
    }
}

// function to parse string into arguments and return token
char **parseInput(char *str)
{
    char **tokens = malloc(100 * sizeof(char *));
    char *token = strtok(str, " ");
    int i = 0;
    while (token != NULL)
    {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    return tokens;
}

//function to handle echo command
void echo(char **tokens){
    int i = 1;
    while(tokens[i]!=NULL){
        printf("%s ", tokens[i]);
        i++;
    }
}

//function to handle pwd command
void pwd(){
    char cwd[1024];
    if(getcwd(cwd, sizeof(cwd)));
    printf("%s", cwd);
}

//function to handle cd command
void cd(char **tokens){
    //if(chdir(tokens[1]));
    int x=chdir(tokens[1]);
    if (x==-1){
        printf("ERROR: No such file or directory");
        printf("\n");
    }
}

void check_thread(char *command){
    int ret = 0;
    ret = system(command);
    if (ret != 0)
    {
        printf("ERROR::system(%s) failed. errno=%d\n", command, errno);
    }
    else{}
}

// C program for linux shell

int main(){
    while(1){
        printPrompt();
        char line[100];
        takeInput(line);
        char **tokens = parseInput(line);
        //printTokens(tokens);
        if(strcmp(tokens[0], "echo")==0){
            if (strcmp(tokens[1], "-e")==0){
                int i = 2;
                while(tokens[i]!=NULL){
                    printf("%s", tokens[i]);
                    i++;
                }
            }
            else if (strcmp(tokens[1], "-n")==0){
                printf("%s",tokens[2]);
            }
            else{
                echo(tokens);
            }
        }
        else if (strcmp(tokens[0], "pwd")==0){
            if (strcmp(tokens[1], "-P")==0){
                //printf("-P");
                pwd();
                printf("\n");
            }
            else if(strcmp(tokens[1], "-L")==0){
                //printf("-L");
                pwd();
                printf("\n");
            }
            else if(strcmp(tokens[1], "\n")==0){
                pwd();
                printf("\n");
            }
            else{
              printf("ERROR: Command Not Found- Invalid Option");
              printf("\n");
            }
        }
        else if (strcmp(tokens[0], "cd")==0){
            cd(tokens);
        }
        else{
            int x=0;
            int i=0;
            while(tokens[i]!=NULL){
                if(strcmp(tokens[i], "&t")==0){
                    x=1;
                    break;
                }
                i++;
            }
          if (x==1){
                if (strcmp(tokens[0], "ls")==0){
                    char* command[]={"./ls",NULL};
                    if (strcmp(tokens[1], "-l")==0){
                        command[0] = "./ls . 1 0";
                    }
                    else if (strcmp(tokens[1], "-a")==0){
                        command[0]="./ls . 0 1";
                    }
                    else{
                        command[0]="./ls . 0 0";
                    }
                    int count = 0;
                    int ret = 0;
                    pthread_t threadId[1];
                    for (count = 0; count < 1; count++){
                        ret = pthread_create(&threadId[count], NULL, (void *)check_thread, command[count]);
                        if (ret != 0)
                        {
                            printf("ERROR::pthread_create() failed. errno=%d\n", errno);
                        }
                        else{}
                    }

                    for(int i = 0; i < 1; i++){
                        pthread_join(threadId[i], NULL);
                    }
                }
                else if (strcmp(tokens[0], "date")==0){
                    char* command[]={"./date",NULL};
                    if (strcmp(tokens[1], "-u")==0){
                        command[0]="./date 1";
                    }
                    else if(strcmp(tokens[1], "\"+%D\"")==0){
                        command[0]="./date 2";
                    }
                    else{
                        command[0]="./date 0";
                    }
                    int count = 0;
                    int ret = 0;
                    pthread_t threadId[1];
                    for (count = 0; count < 1; count++){
                        ret = pthread_create(&threadId[count], NULL, (void *)check_thread, command[count]);
                        if (ret != 0)
                        {
                            printf("ERROR::pthread_create() failed. errno=%d\n", errno);
                        }
                        else{}
                    }
                    for (int i = 0; i < 1; i++){
                        pthread_join(threadId[i], NULL);
                    }
                }
                else if (strcmp(tokens[0], "rm")==0){
                    char* command[]={"./rm",NULL};
                    if (strcmp(tokens[1], "-i")==0){
                        char s1[100] = "./rm ";
                        strcat(s1, tokens[2]);
                        strcat(s1, " 1");
                        command[0] = s1;
                    }
                    else if (strcmp(tokens[1], "-f")==0){
                        char s1[100]="./rm ";
                        strcat(s1, tokens[2]);
                        strcat(s1, " 1");
                        command[0] = s1;
                    }
                    else{
                        char s1[100] = "./rm ";
                        strcat(s1, tokens[1]);
                        strcat(s1, " 0");
                        command[0] = s1;
                    }
                    int count = 0;
                    int ret = 0;
                    pthread_t threadId[1];
                    for (count = 0; count < 1; count++){
                        ret = pthread_create(&threadId[count], NULL, (void *)check_thread, command[count]);
                        if (ret != 0)
                        {
                            printf("ERROR::pthread_create() failed. errno=%d\n", errno);
                        }
                        else{}
                    }
                    for (int i = 0; i < 1; i++){
                        pthread_join(threadId[i], NULL);
                    }

                }
                else if (strcmp(tokens[0], "mkdir")==0){
                    char* command[]={"./mkdir",NULL};
                    if (strcmp(tokens[1], "-p")==0){
                        char s1[100] = "./mkdir ";
                        strcat(s1, tokens[2]);
                        strcat(s1, " 2");
                        command[0] = s1;
                    }
                    else if(strcmp(tokens[1], "-v")==0){
                        char s1[100] = "./mkdir ";
                        strcat(s1, tokens[2]);
                        strcat(s1, " 1");
                        command[0] = s1;
                    }
                    else{
                        char s1[100] = "./mkdir ";
                        strcat(s1, tokens[1]);
                        strcat(s1, " 0");
                        command[0] = s1;
                    }
                    int count = 0;
                    int ret = 0;
                    pthread_t threadId[1];
                    for (count = 0; count < 1; count++){
                        ret = pthread_create(&threadId[count], NULL, (void *)check_thread, command[count]);
                        if (ret != 0)
                        {
                            printf("ERROR::pthread_create() failed. errno=%d\n", errno);
                        }
                        else{}
                    }
                    for (int i = 0; i < 1; i++){
                        pthread_join(threadId[i], NULL);
                    }
                }
                else if (strcmp(tokens[0], "cat")==0){
                    char* command[]={"./cat",NULL};
                    if (strcmp(tokens[1], "-n")==0){
                        char s1[100] = "./cat ";
                        strcat(s1, tokens[2]);
                        strcat(s1, " 1");
                        command[0] = s1;
                    }
                    else if(strcmp(tokens[1], "-E")==0){
                        char s1[100] = "./cat ";
                        strcat(s1, tokens[2]);
                        strcat(s1, " 2");
                        command[0] = s1;
                    }
                    else{
                        char s1[100] = "./cat ";
                        strcat(s1, tokens[1]);
                        strcat(s1, " 0");
                        command[0] = s1;
                    }
                    int count = 0;
                    int ret = 0;
                    pthread_t threadId[1];
                    for (count=0; count<1; count++){
                        ret = pthread_create(&threadId[count], NULL, (void *)check_thread, command[count]);
                        if (ret != 0)
                        {
                            printf("ERROR::pthread_create() failed. errno=%d\n", errno);
                        }
                        else{}
                    }
                    for (int i = 0; i < 1; i++){
                        pthread_join(threadId[i], NULL);
                    }
                }
                else{
                    printf("ERROR: Command Not Found");
                }
            }
            else{
                //printf("yes");
                if (strcmp(tokens[0], "ls")==0){
                pid_t x = fork();
                if (x==0){
                    if(strcmp(tokens[1], "-l")==0){
                        static char *args[] = {"./ls", ".", "1","0",NULL};
                        execv(args[0], args);
                    }
                    else if(strcmp(tokens[1], "-a")==0){
                        static char *args[] = {"./ls", ".", "0","1",NULL};
                        execv(args[0], args);
                    }
                    else if(strcmp(tokens[1], "\n")==0){
                        static char *args[] = {"./ls", ".", "0","0",NULL};
                        execv(args[0], args);
                    }
                    else{
                        printf("ERROR: Command Not Found Invalid Option");
                        printf("\n");
                    }
                }
                else{
                    wait(NULL);
                }
            }
            else if(strcmp(tokens[0], "date")==0){
                pid_t x = fork();
                if (x==0){
                    if(strcmp(tokens[1], "-u")==0){
                        static char *args[] = {"./date", "1", NULL};
                        execv(args[0], args);
                    }
                    else if(strcmp(tokens[1], "\"+%D\"")==0){
                        static char *args[] = {"./date", "2", NULL};
                        execv(args[0], args);
                    }
                    else if(strcmp(tokens[1], "\n")==0){
                        static char *args[] = {"./date","0", NULL};
                        execv(args[0], args);
                    }
                    else{
                        printf("ERROR: Command Not Found Invalid Option");
                        printf("\n");
                    }
                }
                else{
                    wait(NULL);
                }
            }
            else if(strcmp(tokens[0], "rm")==0){
                pid_t x = fork();
                if (x==0){
                    if (strcmp(tokens[1], "-i")==0){
                        char *args[] = {"./rm", tokens[2], "1", NULL};
                        execv(args[0], args);
                    }
                    else if (strcmp(tokens[1], "-f")==0){
                        char *args[] = {"./rm", tokens[2], "1", NULL};
                        execv(args[0], args);
                    }
                    else if(strcmp(tokens[1], "\n")==0){
                        char *args[] = {"./rm", tokens[1], "0", NULL};
                        execv(args[0], args);
                    }
                    else{
                        printf("ERROR: Command Not Found Invalid Option");
                        printf("\n");
                    }
                }
                else{
                    wait(NULL);
                }
            }
            else if(strcmp(tokens[0], "mkdir")==0){
                pid_t x=fork();
                if (x==0){
                    if (strcmp(tokens[1], "-p")==0){
                        char *args[] = {"./mkdir", tokens[2], "2", NULL};
                        execv(args[0], args);
                    }
                    else if (strcmp(tokens[1], "-v")==0){
                        char *args[]={"./mkdir", tokens[2],"1", NULL};
                        execv(args[0], args);
                    }
                    else if(strcmp(tokens[2], "\n")==0){
                        char *args[] = {"./mkdir", tokens[1], "0", NULL};
                        execv(args[0], args);
                    }
                    else{
                        printf("ERROR: Command Not Found Invalid Option");
                        printf("\n");
                    }
                }
                else{
                    wait(NULL);
                }
            }
            else if(strcmp(tokens[0], "cat")==0){
                pid_t x=fork();
                if (x==0){
                    if (strcmp(tokens[1], "-n")==0){
                        char *args[] = {"./cat", tokens[2], "1", NULL};
                        execv(args[0], args);
                    }
                    else if (strcmp(tokens[1], "-E")==0){
                        char *args[]={"./cat", tokens[2],"2", NULL};
                        execv(args[0], args);
                    }
                    else if(strcmp(tokens[1], "\n")==0){
                        char *args[] = {"./cat", tokens[1], "0", NULL};
                        execv(args[0], args);
                    }
                    else{
                        printf("ERROR: Command Not Found Invalid Option");
                        printf("\n");
                    }
                }
                else{
                    wait(NULL);
                }
            }
            else if(strcmp(tokens[0], "exit")==0){
              break;
            }
            else if (strcmp(tokens[0], "\n")==0){
              
            }
            else{
              printf("ERROR: Command Not Found");
              printf("\n");
            }
        }
    }
  }
  return 0;
}

