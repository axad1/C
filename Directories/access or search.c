//	Check for existence only
#include<io.h>
#include<stdio.h>
int main()
{
	char search[32];
	printf("Enter a file name: ");
	scanf("%s", search);
/*	int _access(const char *_Filename,int _AccessMode);
	return 0 for success and -1 for failure
	AccessModes
	F_OK or 0	Check for existence
	X_OK or 1	Check for execute permission
	W_OK or 2	Check for write permission
	R_OK or 4	Check for read permission
*/

/*	if access is unsuccessful, errno is set to of the following:
	EACCES	Access denied
	ENOENT	File or path name not found
*/
	if((_access(search, 0)) == -1)
		perror("ERROR accessing file");
	else
		printf("File '%s' found.\n", search);
}
