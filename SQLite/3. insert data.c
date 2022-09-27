#include<stdio.h>
#include<sqlite3.c>
int main()
{
	sqlite3 *db;
	char *err_msg = 0;
	
	int rc = sqlite3_open("test.db", &db);
	
	if(rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		
		return 1;
	}
	
	char *sql = "DROP TABLE IF EXISTS Cars;"
				"CREATE TABLE Cars(Id INT, Name TEXT, Price INT);"
				"INSERT INTO Cars VALUES(1, 'Audi', 52642);";
	
	/*	The sqlite3_exec() function is a convenience wrapper around
	sqlite3_prepare_v2(), sqlite3_step(), and sqlite3_finalize()
	that allows an application to run multiple statements of SQL without having to use a lot of C code.	*/
	/*
	The function's third parameter is a callback function invoked for each result row
	coming out of the evaluated SQL statement.
	The fourth parameter is the first parameter to the callback function.
	If we do not need them, we can pass 0 to these parameters.
	*/
	rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
	
	if(rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", err_msg);
		
		sqlite3_free(err_msg);
		sqlite3_close(db);
		
		return 1;
	}
	
	sqlite3_close(db);
}
