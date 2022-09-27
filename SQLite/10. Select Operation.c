/*
typedef int (*sqlite3_callback)(
	void*,		Data provided in the 4th argument of sqlite3_exec()
	int,		The number of columns in row 
	char**,		An array of strings representing fields in the row
	char**,		An array of strings representing column names 
*/
#include<stdio.h>
#include<sqlite3.c>
int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	for(int i=0; i<argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i]? argv[i]:"NULL");
	}
	puts("");
}


int main()
{
	sqlite3 *db;
	sqlite3_open("data.db", &db);
	char *sql = "SELECT * FROM Customer";
	const char* data = "CallbacCompanyon called";
	
	sqlite3_exec(db, sql, callback, (void*)data, 0);
	
	printf("%s", sqlite3_errmsg(db));
	
	sqlite3_close(db);
}
