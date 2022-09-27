/*
Queue* createQueue(unsigned capacity)
void enQueue(Queue *queue, int data)
void deQueue(Queue *queue)
int isFull(Queue *queue)
int isEmpty(Queue *queue)
int peek(Queue *queue)
void freeQueue(Queue *queue)
*/

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
	return queue->size == queue->capacity;
}

//	isEmpty
int isEmpty(Queue *queue)
{
	return queue->size == 0;
}

//	Enqueue
void enQueue(Queue *queue, int data)
{
	if(!isFull(queue))
	{
		queue->rear = ++queue->rear % queue->capacity;
		queue->arr[queue->rear] = data;
		queue->size++;
	}
	else
		puts("----- queue is full -----");
}

//	Dequeue
void deQueue(Queue *queue)
{
	if(!isEmpty(queue))
	{
		queue->front = ++queue->front % queue->capacity;
		queue->size--;
	}
	else
		puts("----- queue is empty -----");
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
