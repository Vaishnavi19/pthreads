#include<stdio.h> 
#include<sys/types.h> 
#include<stdlib.h> 
#include<pthread.h> 
#include<semaphore.h> 
#include<unistd.h>


int count; 

sem_t mutex,items; 

void * c1(void * a) 

{ 

	int i; 
	char *argv[2];

	int *n =(int *) a ; 
	printf("\n-------------***********  counter1 ************------------------\n");

			if(count>0)
				{

					sem_wait(&items);             //wait 

					sem_wait(&mutex);
					
					for(i=0;i<*n;i++)
					{
						if(count!=0)
						{
						printf("counter1 processing..\n"); 
						count=count-1;
					        }
						else
						{
						printf("only %d items can be given\n",i);
						goto lab;
						}
					}

					printf("\nitems =%d \n",count); 

					sem_post(&mutex);             //signal 



					sleep(2); 
				}

    lab:   if(count==0)             
		{
			printf("No items in normal storage\n");
			argv[0]="./priority.out";
			argv[1]=NULL;
			execvp(argv[0],argv);
			pthread_exit(NULL);
		}

	printf("counter1 is idle\n");
	printf("\n-------------***********  counter1 ends ************------------------"); 
	pthread_exit(NULL);

} 

void * c2(void * a) 

{ 

	int *n =(int *) a ; 
	char *argv[2];
	int i; 
	printf("\n-------------***********  counter2 ************-----------------------");

		if(count>0)
		{
			sem_wait(&items); 
			sem_wait(&mutex); 

			
					for(i=0;i<*n;i++)
					{
						if(count!=0)
						{
						printf("\n counter1 processing..\n"); 
						count=count-1;
					        }
						else
						{
						printf("only %d items can be given\n\n",i);
						goto lab;
						}
					}

			sem_post(&mutex); 


			printf("\n items =%d\n ",count); 



			sleep(4); 
	}// end if

	 
 lab:	if(count==0) 
	{       
		printf("No items in normal storage\n");
		argv[0]="./priority";
		argv[1]=NULL;
		execvp(argv[0],argv);     
		pthread_exit(NULL);
		
	}

	printf("counter2 idle\n"); 
	printf("\n-------------***********  counter2 ends ************--------------");
	pthread_exit(NULL);
} 


void * c3(void * a) 

{ 

	int *n =(int *) a ; 
        char *argv[2];

	int i; 
	printf("\n-------------***********  counter3 ************------------------");
		if(count>0)
		{
			sem_wait(&items); 
			sem_wait(&mutex); 
			
			
					for(i=0;i<*n;i++)
					{
						if(count!=0)
						{
						printf("\n counter1 processing.."); 
						count=count-1;
					        }
						else
						{
						printf("only %d items can be given\n",i);
						goto lab;
						}
					} 

			sem_post(&mutex); 

			printf("\n items =%d \n ",count); 

			

			sleep(8); 
		}// end if

	
 lab:	if(count==0) 
	{       
		printf("No items in normal storage\n"); 
		argv[0]="./priority";
		argv[1]=NULL;
		execvp(argv[0],argv);         
		pthread_exit(NULL);
	}

	printf("counter3 idle \n"); 
	printf("\n------------***********  counter3 ends ************------------------");
	pthread_exit(NULL);
} 

void main() 

{ 

	pthread_t cus1,cus2,cus3; 
	int totitem,nc1,nc2,nc3,n[5],i;


	printf("tot itmes\n");
	scanf("%d",&totitem); 

	count=totitem; 

        printf("\n tot items is %d \n",totitem); 

	printf("cntr 1 cus:\n");
	scanf("%d",&nc1);

	printf("cntr2 cus:\n");
	scanf("%d",&nc2);

	printf("cntr3 cus:\n");
	scanf("%d",&nc3);

	sem_init(&(items),0,totitem); 

	sem_init(&(mutex),0,1); 

	//Creating customers 
	
	for(i=0;i<nc1;i++)
	{
	printf("\n----cus %d in counter1-----",i);
	printf("\nEnter no. of items to purchase cus-%d : ",i);
	scanf("%d",&n[i]);	
	pthread_create(&cus1,NULL,c1,(void * )&n[i]);
	pthread_join(cus1,NULL); 
	}

	for(i=0;i<nc2;i++)
	{
	printf("\n----cus %d in counter1-----",i);
	printf("\nEnter no. of items to purchase cus-%d : ",i);
	scanf("%d",&n[i]);
	pthread_create(&cus2,NULL,c2,(void * )&n[i]);
	pthread_join(cus2,NULL); 
	}

	for(i=0;i<nc3;i++)
	{
	printf("\n----cus %d in counter1-----",i);
	printf("\nEnter no. of items to purchase cus-%d : ",i);
	scanf("%d",&n[i]);
	pthread_create(&cus3,NULL,c3,(void * )&n[i]);
	pthread_join(cus3,NULL);
	} 

	
	printf("\nback to main...... ");
	


	sem_destroy(&items);
	sem_destroy(&mutex);

}
