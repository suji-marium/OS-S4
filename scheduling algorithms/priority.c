#include <stdio.h>

int main()
{
    int n,index,i,j,t,tot_wt=0,tot_tat=0,burst,temp;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int p[n],bt[n],wt[n],tat[n],pr[n];
    printf("Enter process no,burst time,priority\n");
    printf("PNO\tBT\tPriority\n");
    for(i=0;i<n;i++)
        scanf("%d%d%d",&p[i],&bt[i],&pr[i]);
    
    for(i=0;i<n-1;i++)
    {
        index=i;
        for(j=i+1;j<n;j++)
            if(pr[j]<pr[index])
                index=j;
        t=pr[i];
        pr[i]=pr[index];
        pr[index]=t;
        
        t=bt[i];
        bt[i]=bt[index];
        bt[index]=t;
        
        t=p[i];
        p[i]=p[index];
        p[index]=t;
    }
    
    for(i=0;i<n;i++)
    {
        if(i==0)
            wt[i]=0;
        else
            wt[i]=burst;
        burst+=bt[i];
    }
    
    for(i=0;i<n;i++)
    {
        temp+=bt[i];
        tat[i]=temp;
    }
    
    printf("\nPNO\tBT\tPriority\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\t\t%d\t%d\n",p[i],bt[i],pr[i],wt[i],tat[i]);
    
    for(i=0;i<n;i++)
    {
        tot_wt+=wt[i];
        tot_tat+=tat[i];
    }
    
    printf("\nAverage waiting time is %f\nAverage turn around time is %f\n",(float)tot_wt/(float)n,(float)tot_tat/(float)n);
    
}
