#include<stdio.h>
#include<sqlite3.c>
int main()
{
	//	sqlite3 structure defines a database handles
	sqlite3 *db;
	
	//	sqlite3_stmt structure represents a single SQL statement
    sqlite3_stmt *res;
    
	//	SQLITE_OK sqlite3_open(database_name, database_handle)
	//	:memory: is in-memory database
    int rc = sqlite3_open(":memory:", &db);
    
	//	SQLITE_OK is returned when the connection was successfully established
    if (rc != SQLITE_OK) {
    	
    	//	sqlite3_errmsg() function returns a string description of the error
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    
    /*	Before an SQL statement is executed, it must be first compiled into a byte-code
		with one of the sqlite3_prepare* functions. (The sqlite3_prepare() function is deprecated.)	*/
	/*
		The sqlite3_prepare_v2() function takes five parameters.
		The first parameter is the database handle obtained from the sqlite3_open() function.
		The second parameter is the SQL statement to be compiled.
		The third parameter is the maximum length of the SQL statement measured in bytes.
		Passing -1 causes the SQL string to be read up to the first zero terminator which is the end of the string here.
		(According to the documentation, it is possible to gain some small performance advantage
		by passing the exact number of bytes of the supplied SQL string).
		The fourth parameter is the statement handle. It will point to the precompiled statement
		if the sqlite3_prepare_v2() runs successfully.
		The last parameter is a pointer to the unused portion of the SQL statement.
		(Only the first statement of the SQL string is compiled, so the parameter points to what is left uncompiled.
		We pass 0 since the parameter is not important for us).
	*/
    rc = sqlite3_prepare_v2(db, "SELECT SQLITE_VERSION()", -1, &res, 0);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }    
    
    /*	The sqlite3_step() runs the SQL statement.
		SQLITE_ROW return code indicates that there is another row ready.
		Our SQL statement returns only one row of data, therefore, we call this function only once.	*/
    rc = sqlite3_step(res);
    
    if (rc == SQLITE_ROW) {
        printf("%s\n", sqlite3_column_text(res, 0));
    }
    
	//	The sqlite3_finalize() function destroys the prepared statement object.
    sqlite3_finalize(res);
    
    /*	The sqlite3_exec() function is a convenience wrapper around
	sqlite3_prepare_v2(), sqlite3_step(), and sqlite3_finalize()	*/
    
    //	sqlite3_close() function closes the database connection.
	sqlite3_close(db);
    
    return 0;
}
