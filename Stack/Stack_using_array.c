/*This is a array implementation of Stack*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 6

/*Declaration of stack*/
int stack[MAX];
int top=0;

/*This function performs the Push operation*/
int push()
{
	if(top == MAX)
	{
		printf("Overflow condition, No space for New Element\n");
	}
	else
	{
		printf("Enter the number to push\n");
		scanf("%d",&stack[top]);
		top++;
	}
	return 0;
}

/*This function performs the Pop operation*/
int pop()
{
	if(top == 0)
	{
		printf("Underflow Condition, Nothing to pop\n");
	}
	else
	{
		printf("Going to pop from the stack\n");
		printf("Popped Element is : %d\n",stack[--top]);
	}
	return 0;
}

/*This function performs the Display operation*/
int display()
{
	int i;

	if(top == 0)
	{
		printf("Nothing to display\n");
	}
	else
	{
		for(i = 0;i < top;i++)
		{
			printf("Element at position %d is : %d\n",i,stack[i]);
		}
	}
	return 0;
}

/*This function performs the operation as per the user choice*/
int operations(char choice)
{
	switch(choice)
	{
		case '1':
			push();
			break;
		case '2':
			pop();
			break;
		case '3':
			printf("Display Stack\n");
			display();
			break;
		case '0':
			printf("Going to Quit\n");
			exit(1);
		default:
			printf("Invalid choice\n");
	}	
	
}

/*This function gets the input choice from the user*/
char mainmenu()
{
	char choice;
	printf("\n\n***************STACK******************\n");
	printf("PRESS 1: PUSH\n");
	printf("PRESS 2: POP\n");
	printf("PRESS 3: DISPLAY\n");
	printf("PRESS 0: QUIT\n");
	printf("Please enter your choice\n");
	scanf(" %c",&choice);
	return choice;
}

/*Driver program*/
int main()
{
	char choice;
	while(1)
	{
		choice = mainmenu();
		operations(choice);
	}	
	return 0;
}
