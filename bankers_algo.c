#include <stdio.h>

int main()
{
    int np,nr;
    printf("Enter number of processes: ");
    scanf("%d",&np);
    printf("Enter number of resources: ");
    scanf("%d",&nr);
    int allocation[np][nr],max[np][nr],avilable[nr],i,j,need[np][nr];
    printf("Enter Allocation Matrix: \n");
    for(i=0;i<np;i++)
        for(j=0;j<nr;j++)
            scanf("%d",&allocation[i][j]);
    
    printf("Enter Maximum Matrix: \n");
    for(i=0;i<np;i++)
        for(j=0;j<nr;j++)
            scanf("%d",&max[i][j]);
        
    printf("Enter Available Matrix: \n");
    for(j=0;j<nr;j++)
        scanf("%d",&avilable[j]);
        
    for(i=0;i<np;i++)
        for(j=0;j<nr;j++)
            need[i][j]=max[i][j]-allocation[i][j];
    
    printf("Need Matrix: \n");
    for(i=0;i<np;i++)
    {   printf("\n");
        for(j=0;j<nr;j++)
            printf("%d\t",need[i][j]);
    }
    
    int finish[np],safeseq[np],ind=0,k,flag;
    for(i=0;i<np;i++)
        finish[i]=0;
        
    for(k=0;k<np;k++)
    {
        for(i=0;i<np;i++)
        {
            if(finish[i]==0)
            {
                flag=0;
                for(j=0;j<nr;j++)
                {
                    if(need[i][j]>avilable[j])
                        flag=1;
                    break;
                }
                if(flag==0)
                {
                    safeseq[ind++]=i;
                    for(j=0;j<nr;j++)
                        avilable[j]+=allocation[i][j];
                    finish[i]=1;    
                }
            }
        }
    }
    
    printf("\n\nSafe Sequence: ");
    for(i=0;i<np-1;i++)
        printf("P%d->",safeseq[i]);
    printf("P%d\n",safeseq[np-1]);
        
}
