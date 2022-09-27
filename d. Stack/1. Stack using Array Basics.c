#include<stdio.h>
#include<stdlib.h>
struct stack{
	int top;
	unsigned int size;
	int *arr;
};
int main()
{
	//	Create
	struct stack *stack = malloc(sizeof(struct stack));
	stack->size = 5;
	stack->top = -1;
	stack->arr = malloc(stack->size * sizeof(int));
	
	//	isFull
	if(stack->top == stack->size-1);
	
	//	Push
	stack->arr[++stack->top] = 1;
	
	//	isEmpty
	if(stack->top == -1);
	
	//	Pop
	stack->arr[stack->top--];
	
	//	Peek
	//	if empty return INT_MIN else value
	stack->arr[stack->top];
}
