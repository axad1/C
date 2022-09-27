#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>		//	exit()
void search(char table[5][5], char a, char b, int arr[]);
int validate(char *str);
int mod5(int a)
{
	printf("A = %d\n", a);
	if (a < 0)
		a += 5;
	printf("A = %d\n", a);
	return (a % 5);
}

int main()
{
	char table[5][5];
	puts("Playfair Cipher Decrypt");
	puts("(alphabetical characters)");
	printf("\t*Input key? : ");
	
	char key[30];		gets(key);
	int keysize = validate(key);
	puts(key);
	printf("\tkeysize = %d\n", keysize);
	
	printf("Enter Cipher: ");
	char str[100];		gets(str);
	int strsize = validate(str);
	puts(str);
	printf("strsize = %d\n", strsize);
	//	make str length even
	if(strsize%2 != 0)
	{
		str[strsize] = 'z';
		str[++strsize] = '\0';
		puts(str);
		printf("strsize = %d\n", strsize);
	}
	
	//	generate key table
	int space[26], row=0, col=0;
	for(int i=0; i<keysize; i++)
	{
		if(key[i] != 'j')
			space[key[i] - 'a'] = 2;
	}
	space['j' - 'a'] = 1;
	// map key characters to the table
	for(int i=0; i<keysize; i++)
	{
		if(space[key[i] - 'a'] == 2)
		{
			space[key[i] - 'a'] -= 1;
			table[row][col] = key[i];
			col++;
			if(col==5)
			{
				row++;
				col = 0;
			}
		}
	}
	//	map other alphabets to the table
	for(int i=0; i<26; i++)
	{
		if(space[i] != 1)
		{
			table[row][col] = 'a' + i;
			col++;
			if(col==5)
			{
				row++;
				col = 0;
			}
		}
	}
	
	//	Decrypt
	for(int i=0; i<strsize; i+=2)
	{
		int a[4];
		//	search the 'i' row and column
		search(table, str[i], str[i+1], a);
		//	when row is same
		if(a[0] == a[2])
		{
			str[i] = table[a[0]][mod5(a[1] - 1)];
			str[i+1] = table[a[0]][mod5(a[3] - 1)];
		}
		//	when column is same
		else if(a[1] == a[3])
		{
			str[i] = table[(a[0] - 1) % 5][a[1]];
			str[i+1] = table[(a[2] - 1) % 5][a[1]];
		}
		//	other
		else
		{
			str[i] = table[a[0]][a[3]];
			str[i+1] = table[a[2]][a[1]];
		}
	}
	
	//	print table
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<5; j++)
		printf("%c | ", table[i][j]);
		puts("");
	}
	
	printf("\n*Message: %s", str);
	
}
//	main ends

int validate(char *str)
{
	int count = 0;
	for(int i=0; str[i]!='\0'; i++)
	{
		if(isdigit(str[i]))
		{
			puts("Input alphabetical characters only.");
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

void search(char table[5][5], char a, char b, int arr[])
{
	//	replace j with i
	if(a == 'j')
		a = 'i';
	else if(b == 'j')
		b = 'i';
	//	check a,b row and column
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<5; j++)
		{
			if(table[i][j] == a)
			{
				arr[0] = i;
				arr[1] = j;
			}
			else if(table[i][j] == b)
			{
				arr[2] = i;
				arr[3] = j;
			}
		}
	}
}
