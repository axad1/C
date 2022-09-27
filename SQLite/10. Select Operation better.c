#include<stdio.h>
#include<sqlite3.c>
int callback(void *notUsed, int argc, char **argv, char **azColName)
{
	char *c[argc];
	for(int i=0; i!=argc; i++)
		c[i] = azColName[i];
	for(int i=0; i!=argc; i++)
		printf("|  %s\t|\t%s\t|\n", azColName[i], argv[i]);
	puts("-------------------------");
	
}
int main()
{
	sqlite3 *db;
	sqlite3_open("test.db", &db);
	sqlite3_exec(db, "SELECT * FROM test", callback, 0, 0);
	puts(sqlite3_errmsg(db));
	sqlite3_close(db);
	
}
