/*
#include <mysql.h>
#include <string.h>
#include <stdio.h>


#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "1234"
#define DB_NAME "CAL"
#define CHOP(x) x[strlen(x) - 1] = ' '

void mysql(char * my_query)
{
    MYSQL* connection = NULL, conn;
    MYSQL_RES* sql_result;
    MYSQL_ROW   sql_row;
    int       query_stat;

    char name[12];
    char address[80];
    char tel[12];
    char query[255];

    mysql_init(&conn);

    connection = mysql_real_connect(&conn, DB_HOST,
        DB_USER, DB_PASS,
        DB_NAME, 3306,
        (char*)NULL, 0);

    if (connection == NULL)
    {
        printf(stderr, "Mysql connection error : %s", mysql_error(&conn));
        return 1;
    }


    if (mysql_query(connection, my_query) != 0) {
        // 에러
    }
    printf("\n\n확인!\n\n");

    sql_result = mysql_store_result(connection);
    /*
    while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
    {
        printf("%+11s\n", sql_row[0]);
    }

    
    mysql_close(connection);

    

    
}
*/