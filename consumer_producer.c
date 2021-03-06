#include <stdio.h>
#include <stdlib.h>

int mutex=1,full=0,empty=4,x=0;//empty is assigned with a value ie size of buffer


void producer()
	{
		--mutex;
		++full;
		--empty;
		x++;
		printf("Producer produces item %d",x);
		++mutex;
	}

void consumer()
	{
		--mutex;
		--full;
		++empty;
		printf("Consumer consumes item %d",x);
		x--;
		++mutex;
	}

int main()
	{
		int i,n;
		printf("\n1.Producer \n2.Consumer \n3.Exit");

		for (i = 1; i > 0; i++) {
			printf("\n\nEnter your choice: ");
		        scanf("%d",&n);
			switch(n)
			{
				case 1:
					if(mutex==1 && empty!=0)
						producer();
					else
						printf("Buffer is full");
		
					break;	

				case 2:
					if(mutex==1 && full!=0)
						consumer();
					else
						printf("Buffer is empty");

					break;

				case 3:
					printf("Going to exit");
					exit(0);
						break;
		
			} 
		}
	}
