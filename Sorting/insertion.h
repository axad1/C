void insertion(short a[],short size)
{
	printf("insertion sort\n");
	for(short i=1;i<size;i++)
	{
		short j, temp=a[i];
		for(j=i-1;j>=0 && a[j]>temp;j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=temp;
	}
}
