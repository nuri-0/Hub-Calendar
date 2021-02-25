#include <mysql.h>
#include <string.h>
#include <stdio.h>


void finish_with_error(MYSQL* conn)
{
    fprintf(stderr, "%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}


void mysql(char query[])
{
    MYSQL* conn = mysql_init(NULL);
    

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

    printf("OK!\n\n");
    mysql_close(conn);
    

}
