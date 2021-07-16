/*
ALGORITHM FOR CONVERSION OF INFIX TO POSTFIX
1.scan the infix expression from left to right
2.IF the scanned character is an operand, output it.
3.IF the scanned character is an '(' push it into stack
4.IF the scanned character is an ')', pop the stack and output it until a '(' is encountered 
  and discard both the parenthesis
5.ELSE, 
  5.1 IF the precedence of the scanned operator is lower or equal than the precedence of the operator 
      in the stack then pop all the operator from the stack which are greater than or equal to its
      precedence than that of the scanned operator. After doing that push it scanned operator to the
      stack(if you encounter parenthesis while popping then stop there and push the scanned operator 
      in the stack
  5.2 ELSE, the precedence of the scanned operator is greater than the precedence of the operator at
      the top of the stack or if the stack is empty or if the stack contain a '(' push it in the stack
6.repeat step 2 to 6 until infix expression is scanned 
7.pop and output from the stack until it is not empty
8.print the output 
*/
#include<stdio.h>
#include<stdlib.h>
//character array to store the infix expression
char infix[30]="x+y^z*p/q^r^s";
//character array to store our postfix expression
char postfix[30];
//structure of our stack
struct Stack
{
	char data;
	struct Stack *next;
};
//top of the stack
struct Stack *top=NULL;
//creation of new node for stack
struct Stack* nn (char ele)
{
	struct Stack *p=(struct Stack*)malloc(sizeof(struct Stack));
	p->data=ele;
	p->next=NULL;
	return p;
}
//push function 
void push(char ele)
{
	struct Stack *p=nn(ele);
	if(top == NULL)
		top=p;
	else
	{
		p->next=top;
		top=p;
	}
}
//pop function
char pop()
{
	struct Stack *ptr=top;
	char ch=top->data;
	top=top->next;
	free(ptr);
	ptr=NULL;
	return ch;
}
//peek function
char peek ()
{
	return top->data;
}
//function to check whether a given string is operand or not
int isOperand(char ch)
{
	if(ch>='a' && ch<='z' || ch>='A' && ch<='Z' || ch>='0' && ch<='9')
		return 1;
	else
		return 0;
}
//checking the priority of the operator present in the stack
int priority_in (char ch)
{
	if(ch=='+' || ch=='-')
		return 2;
	if(ch=='*' || ch=='/')
		return 4;
	if(ch=='^')
		return 5;
	else
		return -1;
}
//checking the priority of the operator pushing in the stack
int priority_out (char ch)
{
	if(ch=='+' || ch=='-')
		return 1;
	if(ch=='*' || ch=='/' )
		return 3;
	if(ch=='^')
		return 6;
	else
		return -1;
}

//function to convert the infix expression to postfix expression
void infixToPostfix()
{
	int i=0,j=0;
	//step 1 scanning the expression from left to right
	for(i=0;infix[i];i++)
	{
		//step 2 if the scanned character is an operand
		if(isOperand(infix[i]))
			postfix[j++]=infix[i];
		//step 3 if the scanned character is (
		else if(infix[i]=='(')
				push(infix[i]);
		//step 4 if the scanned character is )
		else if(infix[i]==')')
		{
			while(peek() != '(')
				postfix[j++]=pop();
			pop();
		}
		//step 5 inserting operator according to precedence into the stack
		else
		{
			
				while(top!=NULL && priority_out(infix[i])<=priority_in(peek()))
					postfix[j++]=pop();
				push(infix[i]);
		}
	}//complete loop will be the step 6
	//step 7 pop and output from the stack until its empty
	while(top!=NULL)
		postfix[j++]=pop();
}
int main()
{
	int i=0;
	infixToPostfix();
	for(i=0;postfix[i];i++)
		printf("%c",postfix[i]);
	return 0;
}

