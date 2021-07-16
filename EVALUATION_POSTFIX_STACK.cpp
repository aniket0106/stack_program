/*
1.scan the postfix expression from left to right
2.if scanned character is digit then check until the space encountered
  form the number of those character and push it into stack
3.if the scanned character is space then ignore it and continue
4.if the scanned character is an operator 
  4.1 pop two elements from the stack
  4.2 apply operation on two element, remember one thing second element pop - first element pop
  4.3 push the result into the stack
5. repeat step until whole postfix expression scanned
6. pop and display the result
7.exit
*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char postfix[30]="100 20 - 15 5 + /";
//structure of stack
struct Stack
{
	int data;
	struct Stack *next;
};
//top of the stack
struct Stack *top=NULL;
//creation of node in stack
struct Stack* nn (int data)
{
	struct Stack *p=(struct Stack*)malloc(sizeof(struct Stack));
	p->data=data;
	p->next=NULL;
	return p;
}
//push the node into the stack
void push (int data)
{
	struct Stack *p=nn(data);
	if(top==NULL)
		top=p;
	else
	{
		p->next=top;
		top=p;
	}
}
//pop the node from the stack
int pop ()
{
	int data;
	struct Stack *ptr;
	ptr=top;
	data=top->data;
	top=top->next;
	free(ptr);
	ptr=NULL;
	return data;
}
//peek operation in the stack
int peek ()
{
	return top->data;
}
//postfix evaluation
void postfixEvaluation ()
{
	int i=0,num=0,pop_1=0,pop_2=0;
	for(i=0;postfix[i];i++)
	{
		if(isdigit(postfix[i]))
		{
			//program for converting string into number
			num=0;
			while(isdigit(postfix[i]))
			{
				//ascii value of '0'=48 and '9'=57
				num=num*10+(postfix[i]-'0');
				i++;
			}
			push(num);
		}
	    else if(postfix[i]==' ')
		    	continue;
		else
		{
			pop_1=pop();
			pop_2=pop();
			if(postfix[i]=='+')
				push(pop_2+pop_1);
			else
			 if(postfix[i]=='-')
				push(pop_2-pop_1);
			else
			 if(postfix[i]=='*')
				push(pop_2*pop_1);
			else
			 if(postfix[i]=='/')
				push(pop_2/pop_1);
		}	
	}	
	printf("\n%d",pop());	
}
int main()
{
	postfixEvaluation();
	return 0;
}
