#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>

int main()
{
    int shmid;
    void *shared_memory;
    char buff[100];
    shmid=shmget((key_t)2345,1024,0666|IPC_CREAT);
    printf("Key of shared memory is %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("Process attached at %p\n",shared_memory);
    printf("Enter some data to write in shared memory \n");
    read(0,buff,100);
    strcpy(shared_memory,buff);
    printf("You wrote: %s",(char *)shared_memory);
}
