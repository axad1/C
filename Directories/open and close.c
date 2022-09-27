/* Example for _close and _open */

#include<fcntl.h>	//	O_CREAT
#include<io.h>
#include<stdio.h>
int main()
{
	
/*	int _open(const char *file, int oflag[, int pmode]);
Flags
	_O_APPEND	Position file pointer to end
	_O_BINARY	Open file in binary mode
	_O_CREAT	Create file if it does not exist
	_O_EXCL	Used with O_CREAT, returns an error if file exists
	_O_RDONLY	Open file for reading only
	_O_RDWR	Open file for reading and writing
	_O_TEXT	Open file in text mode
	_O_TRUNC	Truncates existing file
	_O_WRONLY	Opens file for writing only
Return Value
	EEXIST	File already exists
	EINVAL	Invalid oflag or pmode argument
	EMFILE	No more file handles available
	ENOENT	File or path name not found

*/
	int file = _open("temp.dat", O_CREAT);
	if(file < 0)
		perror("Can't create temp.dat");
	else
	{
		printf("Created temp.dat\n");
		int result = _close(fd);
		printf("Close() result code is %d\n", result);
	}
}
