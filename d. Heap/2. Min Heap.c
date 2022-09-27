#include<stdio.h>
#include<stdlib.h>
typedef struct heap{
	int *arr, size;
	unsigned capacity;
} Heap;
//	Create
Heap* createHeap(unsigned capacity)
{
	Heap *heap = malloc(sizeof(Heap));
	heap->capacity = capacity;
	heap->size = 0;
	heap->arr = malloc(sizeof(int) * capacity);	
	return heap;
}
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(int a[], int size, int i)
{
	int left,right;
	left = (2*i)+1;
	right = (2*i)+2;
	int parent=i;
	if(a[left]<a[parent] && left<size)
		parent = left;
	if(a[right]<a[parent] && right<size)
		parent = right;
	if(parent!=i)
	{
		swap(&a[i], &a[parent]);
		heapify(a, size, parent);
	}
}
//	Insert
void insertKey(Heap *heap, int key)
{
	heap->arr[heap->size++] = key;
	
	for(int i=(heap->size/2)-1; i>=0; i--)
		heapify(heap->arr, heap->size, i);
}
//	Delete
void deleteKey(Heap *heap, int key)
{
	for(int i=0; i<heap->size; i++)
	{
		if(key == heap->arr[i])
		{
			swap(&heap->arr[i], &heap->arr[--heap->size]);
			for(int j=heap->size-1; j>=0; j--)
				heapify(heap->arr, heap->size, j);
			break;
		}
	}
}
//	Extract Min
int extractMin(Heap *heap)
{
	if(heap && heap->size>0)
	{
		swap(&heap->arr[0], &heap->arr[--heap->size]);
		heapify(heap->arr, heap->size, 0);
		return heap->arr[heap->size];
	}
	return -1;
}
//	Print
void printHeap(Heap *heap)
{
	if(heap && heap->size>0)
	{
		for(int i=0; i<heap->size; i++)
			printf("%d\t", heap->arr[i]);
		puts("");
	}
	
}
//	Free
void freeHeap(Heap *heap)
{
	if(heap)
	{
		free(heap->arr);
		free(heap);
	}
}

int main()
{
	Heap *heap = createHeap(20);
	for(int i=heap->capacity; i>0;)
		insertKey(heap, i--);
		
	printHeap(heap);
	
	
	for(int i=heap->size; i>0; i--)
		printf("%d\t", extractMin(heap));
	
	freeHeap(heap);
}
