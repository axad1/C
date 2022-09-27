/*
Stack* createStack(unsigned int size)
int isFull(Stack *stack)
int isEmpty(Stack *stack)
void push(Stack *stack, int n)
void pop(Stack *stack)
int top(Stack *stack)
void printStack(Stack *stack)
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Stack{
	int top;
	unsigned int size;
	int *arr;
} Stack;

//	Create
Stack* createStack(unsigned int size)
{
	Stack *stack = malloc(sizeof(Stack));
	stack->size = size;
	stack->top = -1;
	stack->arr = malloc(stack->size * sizeof(int));
	return stack;
}
//	isFull
int isFull(Stack *stack)
{
	return stack->top == stack->size-1;
}
//	isEmpty
int isEmpty(Stack *stack)
{
	return stack->top == -1;
}
//	Push
void push(Stack *stack, int n)
{
	if(!isFull(stack))
		stack->arr[++stack->top] = n;
	else
		puts("----- stack is full -----");
}
//	Pop
void pop(Stack *stack)
{
	if(!isEmpty(stack))
		stack->top--;
	else
		puts("----- stack is empty -----");
}
//	Top
int top(Stack *stack)
{
	if(isEmpty(stack))
		return -1;
	return stack->arr[stack->top];
}
//	Print
void printStack(Stack *stack)
{
	if(stack)
	{
		if(!isEmpty(stack));
		{
			for(int i=stack->top; i>-1; i--)
				printf("%d\t", stack->arr[i]);
			puts("");
		}
	}
}
//	Free
void freeStack(Stack *stack)
{
	if(stack)
	{
		free(stack->arr);
		free(stack);
	}
}
