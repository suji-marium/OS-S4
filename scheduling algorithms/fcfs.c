#include <stdio.h>

int main()
{
    int n,i,j,temp,index,tot_wt=0,tot_tat=0;
    printf("Enter number of proceses: ");
    scanf("%d",&n);
    int p[n],at[n],bt[n],tat[n],ct[n],wt[n];
    printf("\nEnter Process No, Arrival Time and Burst Time\n");
    printf("\nPNO AT BT\n");
    for(i=0;i<n;i++)
        scanf("%d%d%d",&p[i],&at[i],&bt[i]);
    
    for(i=0;i<n-1;i++)
    {
        index=i;
        for(j=i+1;j<n;j++)
        {
            if(at[j]<at[index])
                index=j;
        }
       temp=at[i];
       at[i]=at[index];
       at[index]=temp;
      
       temp=bt[i];
       bt[i]=bt[index];
       bt[index]=temp;
       
       temp=p[i];
       p[i]=p[index];
       p[index]=temp;
    }
    temp=0;
    ct[0]=bt[0]+at[0];
    for(i=1;i<n;i++)
    {
        if(ct[i-1]<at[i])
            temp=at[i]-ct[i-1];
        ct[i]=ct[i-1]+bt[i]+temp;
    }
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        tot_wt+=wt[i];
        tot_tat+=tat[i];
    }
    printf("\nPNO\tAT\tBT\tCT\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],wt[i],tat[i]);
    
    printf("Average waiting time is %f \nAverage turn around time is %f\n",(float)tot_wt/(float)n,(float)tot_tat/(float)n);
}
    










