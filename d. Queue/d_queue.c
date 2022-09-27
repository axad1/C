/*
Queue* createQueue()
void enQueue(Queue *queue, int data)
void deQueue(Queue *queue)
int peek(Queue *queue)
void printQueue(Queue *queue)
void freeQueue(Queue *queue)
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
} node;
typedef struct queue{
	struct node *front, *rear;
} Queue;

//	Create Queue
Queue* createQueue()
{
	Queue *queue = (Queue*) malloc(sizeof(Queue));
	queue->front = queue->rear = NULL;
	return queue;
}
//	isEmpty
int isEmpty(Queue *queue)
{
	return queue->front == NULL;
}
//	Enqueue
void enQueue(Queue *queue, int data)
{
	node *temp = malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;
	if(!queue->rear)
		queue->front = queue->rear = temp;
	else
	{
		queue->rear->next = temp;
		queue->rear = temp;
	}
}
//	Dequeue
void deQueue(Queue *queue)
{
	if(!isEmpty(queue))
	{
		node *temp = queue->front;
		queue->front = temp->next;
		free(temp);
	}
	else
		puts("----- queue is empty -----");
}
//	Peek
int peek(Queue *queue)
{
	if(!isEmpty(queue))
		return queue->front->data;
	return -1;
}
//	Print
void printQueue(Queue *queue)
{
	if(!isEmpty(queue))
	{
		for(node *temp=queue->front; temp!=NULL; temp=temp->next)
			printf("%d\t", temp->data);
		puts("");
	}
}
//	Free
void freeQueue(Queue *queue)
{
	while(queue->front)
	{
		node *temp = queue->front;
		queue->front = temp->next;
		free(temp);
	}
	free(queue);
}
