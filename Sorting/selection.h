void selection(short a[],short size)
{
	printf("selection sort\n");
	for(short i=0;i<size-1;i++)
	{
		short min = i;
		for(short j=i+1;j<size;j++)
		{
			if(a[j]<a[min])
			{
				min = j;
			}
		}
		if(min!=i)
		{
			short temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
}
