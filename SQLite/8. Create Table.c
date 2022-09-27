#include<stdio.h>
#include<sqlite3.c>
int main()
{
	sqlite3 *db;
	sqlite3_open("test.db", &db);
	
	char *sql = "CREATE TABLE IF NOT EXISTS Family(\
	Id INT PRIMARY KEY NOT NULL,\
	Name TEXT NOT NULL,\
	Age INT NOT NULL,\
	Address CHAR(50),\
	Salary REAL);";
	
	int rc = sqlite3_exec(db, sql, 0, 0, 0);
	
	printf("%s", sqlite3_errmsg(db));
	
	sqlite3_close(db);
}
