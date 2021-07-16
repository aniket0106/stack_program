//implementing stack using singly linked list
#include<stdio.h>
#include<stdlib.h>
//creation of top pointing to the last element of the stack
struct Stack *top=NULL;
//structure of the node
struct Stack
{
	int data;
	struct Stack *next;
};
//creation of node 
struct Stack* nn (int ele)
{
	struct Stack *p=(struct Stack*)malloc(sizeof(struct Stack));
	p->data=ele;
	p->next=NULL;
}
//inserting at the beginning of the stack(linked list) = push
void push ()
{
	struct Stack *p;
	int data;
	printf("\nenter the data: ");
	scanf("%d",&data);
	p=nn(data);
	//if the stack is empty
	if(top == NULL)
		top=p;
	//insert at the beginning
	else
	{
		p->next=top;
		top=p;
	}
}
//deleting at the beginning of the stack(linked list) = pop
void pop ()
{
	struct Stack *ptr=NULL;
	//check if the stack is empty
	if(top == NULL)
	{
		printf("\nstack is empty");
		return;
	}
	//delete from the beginning
	ptr=top;
	top=ptr->next;
	free(ptr);
	ptr=NULL;
}
//displaying all the element of the stack(linked list) = display
void display ()
{
	struct Stack *ptr=top;
	//check if the stack is empty
	if(top == NULL)
	{
		printf("\n stack is empty");
		return;
	}
	while(ptr != NULL)
	{
		printf("\n%d",ptr->data);
		ptr=ptr->next;
	}
}
//displaying top element at the stack(linked list) = peek
void peek ()
{
	//check if the stack is empty
	if(top == NULL)
	{
		printf("\n stack is empty");
		return;
	}
	printf("\n%d",top->data);
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
