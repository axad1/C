#include<stdio.h>
void swap(short *a,short *b)
{
	short temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(short a[],short n,short i)
{
	short l,r,parent=i;
	l=(2*i)+1;
	r=(2*i)+2;
	if(a[l]>a[parent] && l<n)
	{
		parent = l;
	}
	if(a[r]>a[parent] && r<n)
	{
		parent = r;
	}
	if(parent!=i)
	{
		swap(&a[i],&a[parent]);
		heapify(a,n,parent);
	}
}
void buildheap(short a[], short n)
{
	//	build heap
	for(short i=(n/2)-1;i>=0;i--)
	{
		heapify(a,n,i);
	}
}
void heapsort(short a[],short n)
{
//	delete items from top
	for(short i=n-1;i>0;i--)
	{
		swap(&a[0],&a[i]);
		heapify(a,i,0);
	}
}
int main()
{
    short a[] = {4,1,3,9,7};
    short size = sizeof(a)/sizeof(short);
    
    
    buildheap(a,5);
    heapsort(a,5); 
    
    
    for(short i=0;i<size;i++)
    {
    	printf("%i\t",a[i]);
	}
}
