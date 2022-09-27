#include<cs50.c>
int main()
{
	string str = get_string("","string: ");
	int w,l,s;
	l=s=0;
	w=1;
	
	for(int i=0;str[i] != '\0';i++)
	{
		if(isspace(str[i]))
		{
			w++;
		}
		if(isalpha(str[i]))
		{
			l++;
		}
		if(str[i] == '.' || str[i] == '?' || str[i] == '!')
		{
			s++;
		}
	}
	
	
	float index,L,S;
	L = l/(float)w * 100;
	S = s/(float)w * 100;
	index = 0.0588 * L - 0.296 * S - 15.8;
	
	
	if(index>=16)
	{
		printf("Grade 16+\n");
	}
	else if(index<1)
	{
		printf("Before Grade 1\n");
	}
	else
	{
		printf("Grade %i", (int)round(index));
	}
}
