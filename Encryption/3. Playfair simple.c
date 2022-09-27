#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int validate(char *str)
{
	int count=0;
	for(int i=0; str[i]!='\0'; i++)
	{
		if(isdigit(str[i]))
		{
			puts("input alphabets only");
			exit(0);
		}
		if(!isspace(str[i]))
		{
			if(isupper(str[i]))
			{
				str[i] = tolower(str[i]);
			}
			str[count++] = str[i];
		}
	}
	str[count] = '\0';
	return count;
}
int main()
{
	char table[5][5];
	puts("Playfair");
	printf("Enter key: ");
	char key[30];		gets(key);
	int keysize = validate(key);
	
	printf("Enter Message: ");
	char str[100];		gets(str);
	int strsize = validate(str);
	if(strsize%2 != 0)
	{
		str[strsize] = 'z';
		str[++strsize] = '\0';
	}
	
	int space[26];
	for(int i=0; i<keysize; i++)
	{
		if(key[i] != 'j')
		space[key[i] - 'a'] = 2;
	}
	space['j' - 'a'] = 1;
	int row=0, col=0;
	for(int i=0; i<keysize; i++)
	{
		if(space[key[i] - 'a'] == 2)
		{
			table[row][col] = key[i];
			space[key[i] - 'a'] -= 1;
			col++;
			if(col==5)
			{
				row++;
				col=0;
			}
		}
	}
	for(int i=0; i<26; i++)
	{
		if(space[i] != 1)
		{
			table[row][col] = 'a' + i;
			col++;
			if(col==5)
			{
				row++;
				col=0;
			}
		}
	}
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<5; j++)
			printf("%c | ", table[i][j]);
		printf("\n");
	}
//	encryption
	for(int i=0; i<strsize; i+=2)
	{
		if(str[i] == 'j')
			str[i] = 'i';
		else if(str[i+1] == 'j')
			str[i+1] = 'i';
		
		int row_a, row_b, col_a, col_b;
		for(int j=0; j<5; j++)
		{
			for(int k=0; k<5; k++)
			{
				if(table[j][k] == str[i])
				{
					row_a = j;
					col_a = k;
				}
				else if(table[j][k] == str[i+1])
				{
					row_b = j;
					col_b = k;
				}
			}
		}
		if(row_a == row_b)
		{
			str[i] = table[row_a][(col_a+1)%5];
			str[i+1] = table[row_a][(col_b+1)%5];
		}
		else if(col_a == col_b)
		{
			str[i] = table[(row_a+1)%5][col_a];
			str[i+1] = table[(row_b+1)%5][col_a];
		}
		else
		{
			str[i] = table[row_a][col_b];
			str[i+1] = table[row_b][col_a];
		}
	}
	printf("Cipher: %s", str);
}
