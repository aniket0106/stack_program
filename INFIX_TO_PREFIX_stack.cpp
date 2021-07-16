/*
1.reverse the INFIX expression
2.scan the infix expression from left to right
3.if the scanned character is an operand then output the result
4.if the scanned character is ')' then push it into the stack
5.if the scanned characte is '(' then pop and output the result until ')' encounter
and discard both the parenthesis
6.else,
  6.1 if the precedence of the scanned operator is lower than the precedence of the 
  operator in the stack then pop all the operators from the stack which are greater 
  than in precedence than that of the scanned operator to the stack(if you encounter
  parenthesis while poping than stop there and push the scanned operator in the stack)
  6.2else, if the precedence of the scanned operator is greater than the precedence of
  the operator at the top of the stack or if th stack is empty or if the stack contain
  ')' push it to the stack
7.repeat step 3-7 until infix expression is scanned
8.pop and output from the stack and until it is not empty
9.reverse the output
10.print the output
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char infix[30]="a+b/(c*d)*(e+f*g)+h";
char prefix[30];
//structure of the stack
struct Stack
{
	char data;
	struct Stack *next;
};
//creation of top of the stack
struct Stack *top=NULL;
//creation of new node int the stack
struct Stack* nn (char data)
{
	struct Stack *p=(struct Stack*)malloc(sizeof(struct Stack));
	p->data=data;
	p->next=NULL;
	return p;
}
//pushing node into the stack
void push (char data)
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
//poping node in the list
char pop ()
{
	struct Stack *ptr;
	int data;
	data=top->data;
	ptr=top;
	top=top->next;
	free(ptr);
	ptr=NULL;
	return data;
}
//peek operation in stck
char peek ()
{
	return top->data;
}
//program to reverse the string
void reverse (char *str)
{
	int i=0;
	char ch;
	unsigned long n=strlen(str);
	for(i=0;i<n/2;i++)
	{
		ch=str[i];
		str[i]=str[n-i-1];
		str[n-i-1]=ch;	
	}
}
//check whether character is operand or not
int isOperand (char ch)
{
	if(ch>='a' && ch<='z' || ch>='A' && ch<='Z' || ch>='0' && ch<='9')
		return 1;
	else
		return 0;
}
//return priority of operand
int priority (char ch)
{
	if(ch=='+' || ch=='-')
		return 1;
	if(ch=='*' || ch=='/')
		return 2;
	else
		return -1;
}
//infix to postfix conversion
void infixToPostfix ()
{
	int i=0,j=0;
	reverse(infix);
	for(i=0;infix[i];i++)
	{
		if(isOperand(infix[i]))
			prefix[j++]=infix[i];
		else if(infix[i]==')')
				push(infix[i]);
		else if(infix[i]=='(')
			 {
			 	while(peek()!=')')
			 		prefix[j++]=pop();
			 	pop();
			 }
		else
		{
			while(top != NULL && priority(infix[i])<priority(peek()))
				prefix[j++]=pop();
			push(infix[i]);
		}
	}
	while(top != NULL)
		prefix[j++]=pop();
	reverse(prefix);	
}
int main()
{
	infixToPostfix();
		printf("%s",prefix);
}
