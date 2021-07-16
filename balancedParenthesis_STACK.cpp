//checking for the balanced parenthesis application of the stack
/*
1.scan from left to right
2.if '(','{','[' encounter then push it into stack
3.if ')','}',']' then check whether top is null or if data present is not of corresponding
  type then unbalanced else pop
4.repeat step 2 and 3 for whole expression
5.if stack is empty then balanced parenthesis, else unbalanced parenthesis
6.print the output
*/
#include<stdio.h>
#include<stdlib.h>
//creation of top pointing to the last element of the stack
struct Stack *top=NULL;
//structure of the node
struct Stack
{
	char data;
	struct Stack *next;
};
//creation of node 
struct Stack* nn (char ele)
{
	struct Stack *p=(struct Stack*)malloc(sizeof(struct Stack));
	p->data=ele;
	p->next=NULL;
}
//inserting at the beginning of the stack(linked list) = push
void push (char c1)
{
	struct Stack *p=nn(c1);
	//if the stack is empty
	if(top == NULL)
		top=p;
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
	ptr=top;
	top=ptr->next;
	free(ptr);
	ptr=NULL;
}
//check whether the parenthesis are balanced or not
int checkBalanced (char *str)
{
	int i=0;
	//scan from left to right
	for(i=0;str[i];i++)
	{
		//if this condition encounter then push it into the stack
		if(str[i] == '{' || str[i] == '(' || str[i] == '[')
			push(str[i]);
		/*if this condition occured then check if top is empty or if top->data is its openning bracket
		  type or not if false not balanced and if true then pop it*/
		else if(str[i] == '}')
		{
			if(top == NULL || top->data != '{')
				return 0;
			pop();
		}
		/*if this condition occured then check if top is empty or if top->data is its openning bracket
		  type or not if false not balanced and if true then pop it*/
		else if(str[i] == ']')
		{
			if(top == NULL || top->data != '[')
				return 0;
			pop();
			
		}
		/*if this condition occured then check if top is empty or if top->data is its openning bracket
		  type or not if false not balanced and if true then pop it*/
		else if(str[i] == ')')
		{
			if(top == NULL || top->data != '(')
				return 0;
			pop();
			
		}
	}
	//check if the stack is empty or not empty stack indicate balanced parenthesis and filled represent unbalanced
	if(top == NULL)
		return 1;
	else
		return 0;
}
int main ()
{
	int res;
	char ch[20]="[()]{}{[()()]()}";
	res = checkBalanced(ch);
	if(res == 0)
		printf("\nNOT balanced");
	else
		printf("\nBalanced");

}
