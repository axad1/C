#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
	int front, rear, size;
	unsigned int capacity;
	int *arr;
} Queue;

int main()
{
	Queue *queue = malloc(sizeof(Queue));
	queue->capacity = 5;
	queue->size = queue->front = 0;
	queue->rear = queue->capacity - 1;
	queue->arr = malloc(sizeof(int) * queue->capacity);
	
	//	isFull
	if(queue->size == queue->capacity);
	
	//	isEmpty
	if(queue->size == 0);
	
	//	Enqueue
	queue->arr[++queue->rear % queue->capacity] = 2;
	queue->size++;
	
	//	Dequeue
	queue->front = ++queue->front % queue->capacity;
	queue->size--;
	
	//	Free
	free(queue->arr);
	free(queue);
}
