#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,rq[100],intial,thm=0;
    printf("Enter number of request: ");
    scanf("%d",&n);
    printf("Enter request sequence:\n");
    for(i=0;i<n;i++)
        scanf("%d",&rq[i]);
    printf("Enter intial head position: ");
    scanf("%d",&intial);
    for(i=0;i<n;i++)
    {
        thm=thm+abs(intial-rq[i]); //thm:Total Head Movement and abs: absolute value
        intial=rq[i];
    }
    printf("Total Head Movement: %d",thm);
}
