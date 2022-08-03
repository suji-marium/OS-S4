#include <stdio.h>

void firstfit(int blockSize1[],int m,int processSize1[],int n);
void bestfit(int blockSize2[],int m,int processSize2[],int n);
void worstfit(int blockSize2[],int m,int processSize2[],int n);

int main()
{
    int blockSize1[]={100,500,200,300,600};
    int processSize1[]={212,417,112,426};
    int m1=sizeof(blockSize1)/sizeof(blockSize1[0]);
    int n1=sizeof(processSize1)/sizeof(processSize1[0]);
    
    int blockSize2[]={100,500,200,300,600};
    int processSize2[]={212,417,112,426};
    int m2=sizeof(blockSize2)/sizeof(blockSize2[0]);
    int n2=sizeof(processSize2)/sizeof(processSize2[0]);
    
    int blockSize3[]={100,500,200,300,600};
    int processSize3[]={212,417,112,426};
    int m3=sizeof(blockSize3)/sizeof(blockSize3[0]);
    int n3=sizeof(processSize3)/sizeof(processSize3[0]);
    
    firstfit(blockSize1,m1,processSize1,n1);
    bestfit(blockSize2,m2,processSize2,n2);
    worstfit(blockSize3,m3,processSize3,n3);
}

void firstfit(int blockSize1[],int m,int processSize1[],int n)
{
    int i,j;
    int allocation[n];
    for(i=0;i<n;i++)
        allocation[i]=-1;
        
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(blockSize1[j]>=processSize1[i])
            {
                allocation[i]=j;
                blockSize1[j]-=processSize1[i];
                break;
            }
    
    printf("Firstfit\n");    
    printf("Process No\t Process Size\t Block No\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t",i+1);
        printf("%d\t\t",processSize1[i]);
        if(allocation[i]!=-1)
            printf("%d",allocation[i]+1);
        else 
            printf("Not Allocated");
        printf("\n");
    }
        
}

void bestfit(int blockSize2[],int m,int processSize2[],int n)
{
    int i,j;
    int allocation[n];
    for(i=0;i<n;i++)
        allocation[i]=-1;
    
    for(i=0;i<n;i++)
    {
        int indexPlaced=-1;
        for(j=0;j<m;j++)
        {
            if(blockSize2[j]>=processSize2[i])
            {
                if(indexPlaced==-1)
                    indexPlaced=j;
                else if(blockSize2[j]<blockSize2[indexPlaced])
                    indexPlaced=j;
            }
        }
        if(indexPlaced!=-1)
        {
            allocation[i]=indexPlaced;
            blockSize2[indexPlaced]-=processSize2[i];
        }
    }
    
    printf("Bestfit\n");
    printf("Process No\tProcess Size\tBlock No\n");
    
    for(i=0;i<n;i++)
    {
        printf("%d\t\t",i+1);
        printf("%d\t\t",processSize2[i]);
        if(allocation[i]!=-1)
            printf("%d\t\t",allocation[i]+1);
        else
            printf("\tNot Allocated");
        printf("\n");
    }
    
}
    
void worstfit(int blockSize2[],int m,int processSize2[],int n)
{
    int i,j;
    int allocation[n];
    for(i=0;i<n;i++)
        allocation[i]=-1;
    
    for(i=0;i<n;i++)
    {
        int indexPlaced=-1;
        for(j=0;j<m;j++)
        {
            if(blockSize2[j]>=processSize2[i])
            {
                if(indexPlaced==-1)
                    indexPlaced=j;
                else if(blockSize2[j]>blockSize2[indexPlaced])
                    indexPlaced=j;
            }
        }
        if(indexPlaced!=-1)
        {
            allocation[i]=indexPlaced;
            blockSize2[indexPlaced]-=processSize2[i];
        }
    }
    
    printf("Worstfit\n");
    printf("Process No\tProcess Size\tBlock No\n");
    
    for(i=0;i<n;i++)
    {
        printf("%d\t\t",i+1);
        printf("%d\t\t",processSize2[i]);
        if(allocation[i]!=-1)
            printf("%d\t\t",allocation[i]+1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}
        
    
    
    
    
    
    
    
    
    
    
    
