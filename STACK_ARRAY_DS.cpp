/*
1.stack is a logical data structure following principle of first in last out
2.we can implement stack using both array and lnked list
3.there is one thing called top,that always point to the top og the stack and
insertion and deletion taken from that point only
*/
#include<stdio.h>
#include<stdlib.h>
//defining the size of stack
#define size 5
//implementing stack using array
int stack[size];
//always point to the top
int top=-1;
//inserting the data at the top of the stack = push function
void push ()
{
	//check if the stack is full
	if(top == size-1)
	{
		printf("\nstack is full");
		return;
	}
	printf("\nenter the element:  ");
	scanf("%d",&stack[++top]);
}
//deleting the element at the top of the stack = pop function
void pop ()
{
	//check if the stack is empty
	if(top == -1)
	{
		printf("\nstack is empty");
		return;
	}
	printf("\ndeleted element: %d",stack[top--]);
}
//display elements in the stack = dislay
void display ()
{
	int i=top;
	//check if the stack is empty
	if(top == -1)
	{
		printf("\n stack is empty");
		return;
	}
	
	while(i >= 0)
	{
		printf("\n%d",stack[i--]);
	}
}
//display the top element present in the stack = peek
void peek ()
{
	//check if the stack is empty
	if(top == -1)
	{
		printf("\n stack is empty");
		return;
	}
	printf("\n%d",stack[top]);
}
int main ()
{
	int n;
	 while(1)
	 {
	 	printf("\n<------WELCOME USER------>");
	 	printf("\n1.push");
		printf("\n2.pop");
		printf("\n3.peek");
		printf("\n4.display");
		printf("\n5.exit");
		printf("\nenter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
		case 1: push ();
			break;	
		case 2: pop ();
			break;
		case 3: peek ();
			break;	
		case 4: display ();
			break;
		case 5: return 0;
			break;	
		default: printf("\ninvalid input");
			break;	
		}	
     }
 }
