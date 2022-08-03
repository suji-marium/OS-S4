

#include <stdio.h>

int main()
{
    int n,index,i,j,t,tot_wt=0,tot_tat=0,burst,temp;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int p[n],at[n],bt[n],wt[n],tat[n];
    printf("Enter process no,arrival time,burst time\n");
    printf("PNO\tAT\tBT\n");
    for(i=0;i<n;i++)
        scanf("%d%d%d",&p[i],&at[i],&bt[i]);
    
    for(i=0;i<n-1;i++)
    {
        index=i;
        for(j=i+1;j<n;j++)
            if(at[j]<at[index])
                index=j;
        
        t=at[i];
        at[i]=at[index];
        at[index]=t;
        
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
            wt[i]=at[i];
        else
            wt[i]=burst-at[i];
        burst+=bt[i];
    }
    
    for(i=0;i<n;i++)
    {
        temp+=bt[i];
        tat[i]=temp-at[i];
    }
    
    printf("PNO\tAT\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],wt[i],tat[i]);
    
    for(i=0;i<n;i++)
    {
        tot_wt+=wt[i];
        tot_tat+=tat[i];
    }    
    printf("Average waiting time is %f\nAverage turn around time is %f\n",(float)tot_wt/(float)n,(float)tot_tat/(float)n);
}
















