#include<stdio.h>

int rescnt=2,flag1=0,flag2=0,flag3=0;

main()
{
int c1,c2,c3,a1,a2,a3;
printf("-------------in reserved mode-----------\n\n");
printf("No. of items in reserved mode is %d\n\n",rescnt);
printf("Enter the no. of items needed by the customer in counter1 and their A.T\n");
scanf("%d %d",&c1,&a1);
printf("Enter the no. of items needed by customer in counter2 and their A.T\n");
scanf("%d %d",&c2,&a2);
printf("Enter the no. of items needed by customer in counter3 and their A.T\n");
scanf("%d %d",&c3,&a3);

// giving priority to the customers who are currently in service in all counters. 
// Other customers who are standing at the back of them are not considered for priority
if(c1<=rescnt && c2<=rescnt && c3<=rescnt)
{
	if(c1>c2 && c1>c3)
        {
		printf("processing....\n\n");
		rescnt=rescnt-c1;
		flag1=1;
		printf("items given to customer in counter1\n\n");
		printf("reserved mode = %d\n",rescnt);
        }
	else if(c2>c3 && c2>c1)
		{
			printf("processing....\n\n");
			rescnt=rescnt-c1;
			flag2=1;
			printf("items given to customer in counter2\n\n");
			printf("reserved mode = %d\n",rescnt);
		}
	else if(c3>c2 && c3>c1)
		{
			printf("processing....\n\n");
			rescnt=rescnt-c1;
			flag3=1;
			printf("items given to customer in counter2\n\n");
			printf("reserved mode = %d\n",rescnt);
		}

//when any 2 customers request for same number of items arrival time is considered for priority
//(less arrival-time  =high-priority)
	else if((c1==c2 && a1<a2 && c1>c3) || (c1==c3 && a1<a3 && c1>c2))
	{
			printf("processing....\n\n");
			rescnt=rescnt-c1;
			flag1=1;
			printf("items given to customer in counter1\n\n");
			printf("reserved mode = %d\n",rescnt);
	}
	else if((c2==c1 && a2<a1 && c2>c3) || (c2==c3 && a1<a3 && c2>c1))
	{
			printf("processing....\n\n");
			rescnt=rescnt-c1;
			flag1=1;
			printf("items given to customer in counter2\n\n");
			printf("reserved mode = %d\n",rescnt);
	}
	else if((c3==c2 && a3<a2 && c1>c3) || (c3==c1 && a3<a1 && c3>c1))
	{
			printf("processing....\n\n");
			rescnt=rescnt-c1;
			flag1=1;
			printf("items given to customer in counter1\n\n");
			printf("reserved mode = %d\n",rescnt);
	}

//when all 3 customers request for same number of items
	else if(c1==c2 && c1==c3)
	{
		if(a1<a2 && a1<a3)
		{ 
			printf("processing....\n\n");
			rescnt=rescnt-c1;
			flag1=1;
			printf("items given to customer in counter1\n\n");
			printf("reserved mode = %d\n",rescnt);	
		}
		else if(a2<a1 && a2<a3)
		{ 
			printf("processing....\n\n");
			rescnt=rescnt-c1;
			flag1=1;
			printf("items given to customer in counter2\n\n");
			printf("reserved mode = %d\n",rescnt);	
		}
		else
		{ 
			printf("processing....\n\n");
			rescnt=rescnt-c1;
			flag1=1;
			printf("items given to customer in counter3\n\n");
			printf("reserved mode = %d\n",rescnt);	
		}
	}

}

//if items requested is more than the number of items in reserved mode

else
printf("Enter 2 or less than 2 items\n\n");

//if reserved mode contains some more items after satisfying the customer with higher priority

if(rescnt!=0)
{
	if(flag1==0 && flag2==0 && flag3==1)
	{
		 printf("one item remaining");
		 printf("Enter the Arrival time of customers in counter 1 & 2\n\n");
		 scanf("%d %d",&a1,&a2);
		  printf("processing...\n\n");
		 if(a1<a2)
			 {
			  rescnt=rescnt-1;
			  printf("Item given to customer in counter1\n");
			 }
		 else
			 {
			   rescnt=rescnt-1;
			  printf("Item given to customer in counter2\n");
			  }
		  printf("\n\n-----------********* all items emptied *********----------------\n\n"); 
	 } 

	else if(flag1==1 && flag2==0 && flag3==0)
	{
		 printf("one item remaining");
		 printf("Enter the Arrival time of customers in counter 2 & 3\n\n");
		 scanf("%d %d",&a2,&a3);
		  printf("processing...\n\n");
		 if(a2<a3)
			 {
			  rescnt=rescnt-1;
			  printf("Item given to customer in counter2\n");
			 }
		 else
			 {
			   rescnt=rescnt-1;
			  printf("Item given to customer in counter3\n");
			  }
		  printf("\n\n-----------********* all items emptied *********----------------\n\n"); 
	 } 

	else if(flag1==0 && flag2==1 && flag3==0)
	{
		 printf("one item remaining");
		 printf("Enter the Arrival time of customers in counter 1 & 3\n\n");
		 scanf("%d %d",&a1,&a3);
		  printf("processing...\n\n");
		 if(a1<a3)
			 {
			  rescnt=rescnt-1;
			  printf("Item given to customer in counter1\n");
			 }
		 else
			 {
			   rescnt=rescnt-1;
			  printf("Item given to customer in counter3\n");
			  }
	 	 printf("\n\n-----------********* all items emptied *********----------------\n\n"); 
	 } 

}

else
printf("\n\n-----------********* all items emptied *********----------------\n\n"); 

}

