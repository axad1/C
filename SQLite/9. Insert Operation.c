#include<stdio.h>
#include<sqlite3.c>
int main()
{
	sqlite3 *db;
	sqlite3_open("test.db", &db);
	char *sql = "CREATE TABLE IF NOT EXISTS Company(\
	Id INT PRIMARY KEY NOT NULL,\
	Name TEXT NOT NULL,\
	Age INT NOT NULL,\
	Address CHAR(50),\
	Salary REAL);";
	sqlite3_exec(db, sql, 0, 0, 0);
//	---------------------------------
	
	sql = "INSERT INTO Company(Id, Name, Age, Address, Salary) \
	VALUES(1, 'PAUL', 30, 'California', 1000.0);\
		INSERT INTO Company(Id, Name, Age, Address, Salary) \
	VALUES(2, 'Allen', 32, 'Norway', 2000.0);\
	INSERT INTO Company(Id, Name, Age, Address, Salary) \
	VALUES(3, 'Mark', 33, 'Texas', 3000.0);";

	sqlite3_exec(db, sql, 0, 0, 0);
	
	sqlite3_close(db);
}
