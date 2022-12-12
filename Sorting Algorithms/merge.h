void merging(short a[],short low,short mid,short high)
{
	short index=low;
	short b[high+1];
	short l,r;
	l=low;
	r=mid+1;
	while(l<=mid && r<=high)
	{
		if(a[l]<a[r])
		{
			b[index]=a[l];
			l++;
		}
		else
		{
			b[index]=a[r];
			r++;
		}
		index++;
	}
	if(l>mid)
	{
		while(r<=high)
		{
			b[index]=a[r];
			r++; index++;
		}
	}
	else
	{
		while(l<=mid)
		{
			b[index]=a[l];
			l++; index++;
		}
	}
	for(l=low;l<=high;l++)
	{
		a[l] = b[l];
	}
}
void mergesort(short a[],short low,short high)
{
	if(low<high)
	{
		short mid = (low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merging(a,low,mid,high);
	}
}
void merge(short a[],short size)
{
	printf("merge sort\n");
	mergesort(a,0,size-1);
}
