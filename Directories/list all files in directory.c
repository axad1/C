//	C Program to List Files in Directory

#include<dirent.h>
#include<stdio.h>
int main()
{
    DIR *d = opendir(".");
    struct dirent *dir;
    if(d)
	{
		while((dir = readdir(d)) != NULL)
			puts(dir->d_name);
		closedir(d);
	}
}
