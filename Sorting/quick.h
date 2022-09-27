void swap(short *a,short *b)
{
	short temp = *a;
	*a = *b;
	*b = temp;
}
int partition(short a[],short low,short high)
{
	short pivot = a[high];
	short index = low-1;
	for(short i=low;i<high;i++)
	{
		if(a[i]<pivot)
		{
			index++;
			swap(&a[i],&a[index]);
		}
	}
	swap(&a[index+1],&a[high]);
	return (index+1);
}
void quicksort(short a[],short low,short high)
{
	if(low<high)
	{
		short pivot = partition(a,low,high);
		quicksort(a,low,pivot-1);
		quicksort(a,pivot+1,high);
	}
}
void quick(short a[],short size)
{
	printf("quick sort\n");
	quicksort(a,0,size-1);
}
