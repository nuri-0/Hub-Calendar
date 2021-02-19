#include <mysql.h>
#include <string.h>
#include <stdio.h>

/*
void finish_with_error(MYSQL* conn)
{
    fprintf(stderr, "%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}
*/
void mysql_r(char query[])
{
    MYSQL* conn = mysql_init(NULL);
    MYSQL_RES* sql_result;
    MYSQL_ROW   sql_row;

    if (conn == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    if (mysql_real_connect(conn, "localhost", "root", "1234", "CAL", 0, NULL, 0) == NULL)
    {
        finish_with_error(conn);
    }

    if (mysql_query(conn, query))
    {
        finish_with_error(conn);
    }

    sql_result = mysql_store_result(conn);

    while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
    {
        printf("%+11s %+15s %+5s %+5s %+5s \n", sql_row[0], sql_row[1], sql_row[2], sql_row[3], sql_row[4]);
    }
    mysql_close(conn);
    

    
}
