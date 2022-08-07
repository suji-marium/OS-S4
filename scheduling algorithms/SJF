#include <stdio.h>

struct process 
{
    int BT,WT,AT,TAT;
};

struct process a[10];


int main()
{   
    int i,n,count=0,short_p=0,t,tot_wt=0,tot_tat=0,temp[10];
    printf("Enter number of processes:");
    scanf("%d",&n);
    printf("Enter arrival time and burst time of process:\n");
    printf("\nAT\tBT\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].AT,&a[i].BT);
        temp[i]=a[i].BT;
    }
    a[9].BT=10000;
    
    for(t=0;count!=n;t++)
    {
        short_p=9;
        for(i=0;i<n;i++)
        {
            if(a[i].BT<a[short_p].BT &&(a[i].AT<=t && a[i].BT>0))
            {
                short_p=i;
            }
        }
        a[short_p].BT=a[short_p].BT-1;
        if(a[short_p].BT==0)
        {
            count++;
            a[short_p].WT=t+1-a[short_p].AT-temp[short_p];
            a[short_p].TAT=t+1-a[short_p].AT;
            tot_wt+=a[short_p].WT;
            tot_tat+=a[short_p].TAT;
        }
    }
    printf("\nPNO\tAT\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
    {
       printf("\n%d\t%d\t%d\t%d\t%d\n",i+1,a[i].AT,a[i].BT,a[i].WT,a[i].TAT);
    }
    printf("\nAverage waiting time is %f\nAverage turn around time is %f\n",(float)tot_wt/(float)n,(float)tot_tat/(float)n);
}
