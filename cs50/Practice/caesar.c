#include<cs50.c>
int main(int argc, char *argv[])
{
	printf("argc = %i\n",argc);
	printf("argv = %s\n",argv[1]);
	if(argc != 2)
	{
		printf("Usage: ./caesar key\n");
		return 1;
	}
	int key;
	sscanf(argv[1],"%d",&key);
	
	char *str = get_string("","Plaintext: ");
	for(int i=0; str[i] != '\0'; i++)
	{
		if(isalpha(str[i]))
		{
			if(isupper(str[i]))
			{
				str[i] = (((str[i] - 'A') + key) % 26) + 'A';
			}
			else
			{
				str[i] = (((str[i] - 'a') + key) % 26) + 'a';
			}
		}
	}
	printf("ciphertext: %s\n", str);
	return 0;
}
