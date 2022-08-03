#include <stdio.h>
#include <unistd.h>
int main()
{
    int n,pid,i,sume=0,sumo=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    pid=fork();
    
    if(pid==0)
    {
        printf("\nChild process");
        printf("\nPID : %d",getpid());
        printf("\nPPID: %d",getppid());
        for(i=0;i<n;i=i+2)
            sume=sume+i;
        printf("\nSum of even numbers %d",sume);
        
    }
    
    else if(pid>0)
    {
        printf("\nParent process");
        printf("\nPID : %d",getpid());
        for(i=1;i<n;i=i+2)
            sumo=sumo+i;
        printf("\nSum of odd numbers %d",sumo);
    }
}


