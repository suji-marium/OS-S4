#include <stdio.h>

int main()
{
    int n,index,i,j,t,tot_wt=0,tot_tat=0,burst,temp,qt,flag=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int x=n;
    int p[n],at[n],bt[n],wt[n],tat[n],rt[n];
    printf("Enter process no,arrival time,burst time\n");
    printf("PNO\tAT\tBT\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&p[i],&at[i],&bt[i]);
        rt[i]=bt[i];
    }
    printf("Enter the quantum time:");
    scanf("%d",&qt);
    for(i=0,t=0;x!=0;)
    {
        if(rt[i]<=qt && rt[i]>0)
        {
            t+=rt[i];
            rt[i]=0;
            flag=1;
        }
        
        else if(rt[i]>0)
        {
            t+=qt;
            rt[i]-=qt;
        }
        
        if(flag==1 && rt[i]==0)
        {
            x--;
            p[j]=i+1;
            wt[j]=t-at[i]-bt[i];
            tat[j++]=t-at[i];
            flag=0;
        }
        
        if(i==n-1)
            i=0;
        else if(at[i+1]<=t)
            i++;
        else
            i=0;
    }
    
    printf("\nPNO\tAT\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],wt[i],tat[i]);
    
    for(i=0;i<n;i++)
    {
        tot_wt+=wt[i];
        tot_tat+=tat[i];
    }    
    printf("\nAverage waiting time is %f\nAverage turn around time is %f\n",(float)tot_wt/(float)n,(float)tot_tat/(float)n);
}









