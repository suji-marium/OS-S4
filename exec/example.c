#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
    printf("Pid of example.c is %d\n",getpid());
    char *args[]={"hello","c","programming",NULL};
    execv("./hello",args);
    printf("Back to example.c");
}
