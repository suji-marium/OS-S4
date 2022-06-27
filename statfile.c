#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char path[20];
	printf("Enter the path: ");
	scanf("%s",path);
	struct stat *buf;
	buf=malloc(sizeof(struct stat));
	stat(path,buf);
	int size=buf->st_size;
	printf("%d\n",size);
	int id=buf->st_uid;
	printf("%d\n",id);
	free(buf);
} 
