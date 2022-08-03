#include <stdio.h>
#include <dirent.h>
int main()
{
    struct dirent *de;
    char filepath [100];
    printf("Enter the path of the directory:\n ");
    scanf("%s",filepath);
    DIR *dr=opendir(filepath);
    if(dr==NULL)
    {
        printf("Could not open the directory");
        return 0;
    }
    printf("Files in the directory are:\n");
    while((de=readdir(dr))!=NULL)
    {
        printf("\n%s\n",de->d_name);
    }
    closedir(dr);
    return 0;
}
