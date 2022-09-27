/*
	Example for _chsize
	Also demonstrates _open, fopen
	This program creates two files of the given size in the directory from
	which it is run.
*/
//#include <dos.h>
#include<fcntl.h>
#include<io.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *fname[2] = {"file1","file2"};
	long sizes[2] = {10000l, 20000l};
	
	//	Create file one
	int file1 = _open(fname[0], O_CREAT | O_WRONLY);
	if(file1 == -1)
		perror("No file1");
	
	//	Create and open file 2
	FILE *file2 = fopen(fname[1]," wb");
	if(file2 == 0)
		perror("No file2");

	//	give sizes in bytes
	_chsize(file1, 1024*1024);
	//	[Note] convert argument of type 'struct FILE*' to 'int'
	_chsize(fileno(file2), sizes[1]);
	
}

