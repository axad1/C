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
	if(stack->top == stack->size-1)
	{
		puts("Stack is Full");
		return 1;
	}
	return 0;
}
//	isEmpty
int isEmpty(Stack *stack)
{
	if(stack->top == -1)
	{
		puts("Stack is Empty");
		return 1;
	}
	return 0;	// false
}
//	Push
void push(Stack *stack, int n)
{
	if(!isFull(stack))
	{
		stack->arr[++stack->top] = n;
		puts("Pushed");
	}
}
//	Pop
void pop(Stack *stack)
{
	if(!isEmpty(stack))
	{
		stack->arr[stack->top--] = 0;
		puts("Popped");
	}
	
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
		if(!isEmpty(stack))
		{
			int temp = stack->top;
			while(temp!=-1)
				printf("%d\t", stack->arr[temp--]);
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

int main()
{
	Stack *stack = createStack(5);
//	for(int i=0; i<stack->size; i++)
		push(stack, 1);
	
	printStack(stack);
}
