#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
	int front, rear;
	unsigned capacity, size;
	int *arr;
} Queue;

//	Create
Queue* createQueue(unsigned capacity)
{
	Queue *queue = malloc(sizeof(Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = queue->capacity - 1;
	queue->arr = malloc(queue->capacity * sizeof(int));
	return queue;
}

//	isFull
int isFull(Queue *queue)
{
	if(queue->size == queue->capacity)
	{
		puts("Queue is Full");
		return 1;
	}
	return 0;
}

//	isEmpty
int isEmpty(Queue *queue)
{
	if(queue->size == 0)
	{
		puts("Queue is Empty");
		return 1;
	}
	return 0;
}

//	Enqueue
void enqueue(Queue *queue, int data)
{
	if(!isFull(queue))
	{
		queue->rear = ++queue->rear % queue->capacity;
		queue->arr[queue->rear] = data;
		queue->size++;
	}
}

//	Dequeue
void dequeue(Queue *queue)
{
	if(!isEmpty(queue))
	{
		queue->front = ++queue->front % queue->capacity;
		queue->size--;
	}
}

//	Peek
int peek(Queue *queue)
{
	if(isEmpty(queue))
		return -1;
	return queue->arr[queue->front];
}

//	Free
void freeQueue(Queue *queue)
{
	free(queue->arr);
	free(queue);
	queue->size = 0;
}

//	Print
void printQueue(Queue *queue)
{
	if(!isEmpty(queue))
	{
		int i;
		for(i=queue->front; i!=queue->rear; i=(i+1)%queue->capacity)
			printf("%d\t", queue->arr[i]);
		printf("%d\n", queue->arr[i]);
	}
}

int main()
{
	Queue *queue = createQueue(10);
	for(int i=0; i<queue->capacity; i++)
		enqueue(queue, i+1);
	for(int i=0; i<5; i++)
		dequeue(queue);
	for(int i=15; i<20;i++)
		enqueue(queue, i+1);
	printQueue(queue);
	freeQueue(queue);
}
