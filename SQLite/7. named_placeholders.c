/*	Parameterized queries, also called prepared statements, increase security and performance.
	When we use parameterized queries, we use placeholders instead of
	directly writing the values into the statements.	*/

#include <stdio.h>
#include <sqlite3.c>

int main(void) {
    
    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt *res;
    
    int rc = sqlite3_open("test.db", &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    
	//	a question mark (?) is used as a placeholder which is later replaced with an actual value.
    char *sql = "SELECT Id, Name FROM Friends WHERE Id = ?";
    
	//	The sqlite3_prepare_v2() function compiles the SQL query.
    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
    
    if (rc == SQLITE_OK)
	{
		//	The sqlite3_bind_int() binds an integer value to the prepared statement.
       /*	second parameter is the index of the SQL parameter to be set.
			third parameter is the value to bind to the parameter.	*/
       sqlite3_bind_int(res, 1, 3);
    }
	else
	{    
       fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }
    
    //	The sqlite3_step() function evaluates the SQL statement.
    int step = sqlite3_step(res);
    
	//	If there is some row of data available, we get the values of two columns with the sqlite3_column_text() function.
    if (step == SQLITE_ROW) {
        
        printf("%s: ", sqlite3_column_text(res, 0));
        printf("%s\n", sqlite3_column_text(res, 1));
        
    } 

    sqlite3_finalize(res);
    sqlite3_close(db);
    
    return 0;
}
