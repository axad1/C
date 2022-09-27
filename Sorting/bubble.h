void bubble(short a[], short size)
{
	printf("bubble sort\n");
	for(short i=0;i<size-1;i++)
	{
		short flag = 1;
		for(short j=0;j<size-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				short temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag = 0;
			}
		}
		if(flag)
		break;
	}
}
