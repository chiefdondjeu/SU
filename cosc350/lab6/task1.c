//Florent Dondjeu Tschoufack
//Oct 26, 2020
//lab 6
//task1.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

char *mygetenv(char *env)
{
    char **ptr = environ;
    int n = 0;
    
    while(ptr[n] != NULL)
    {
        //find the index where the equal sign reside
        int index = 0;
        for(;ptr[n][index] != '='; index++)
        {}

        //compare passed in arg to index char by char
        int check = 0;
        for(int i = 0; i < index; i++)
        {
            if(env[i] == ptr[n][i])
                check++;
            else break;
        }
        if(check == strlen(env))
            return ptr[n];

        n++;
    }
    
    return NULL;
}

int main(int argc, char *argv[])
{
    if(argc == 1 || argc > 3)
    {
        printf("Need to pass in an env variable as an argument.\n\te.g ./task1 HOME\n");
        exit(1);
    }

    char *result = mygetenv(argv[1]);
    
    if(result == NULL)
        printf("Variable could not be found!\n");
    else
        printf("Output %s\n", result);

    return 0;
}
