#include <stdio.h>
#include <sys/stat.h>
void statfile(struct stat buf);

int main()
{
   char path[100];
   struct stat buf;
   printf("Enter the path of a file: ");
   scanf("%s",path);
   stat(path,&buf);
   statfile(buf);
}

void statfile(struct stat buf)
{
    printf("\nUid: %d",buf.st_uid);
    printf("\nSize: %ld",buf.st_size);
}
