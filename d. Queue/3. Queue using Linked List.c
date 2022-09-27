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
	if(!queue->front)
	{
		puts("Queue is Empty");
		return 1;
	}
	return 0;
}
//	Enqueue
void enqueue(Queue *queue, int data)
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
void dequeue(Queue *queue)
{
	if(!isEmpty(queue))
	{
		node *temp = queue->front;
		queue->front = temp->next;
		free(temp);
	}
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
	for(node *temp=queue->front; temp!=NULL; temp=temp->next)
		printf("%d\t", temp->data);
	puts("");
}
//	Free
void freequeue(Queue *queue)
{
	while(queue->front)
	{
		node *temp = queue->front;
		queue->front = temp->next;
		free(temp);
	}
	free(queue);
}

int main()
{
	Queue *queue = createQueue();
	for(int i=0; i<10; i++)
		enqueue(queue, i+1);

	printQueue(queue);
	
	for(int i=0; i<5; i++)
	dequeue(queue);
	
	printQueue(queue);
	
	for(int i=15; i<20; i++)
		enqueue(queue, i+1);
		
	printQueue(queue);
	freequeue(queue);
}
