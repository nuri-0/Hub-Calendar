#include <stdio.h>
#include <string.h>

int main()
{
    char calendar[5 * 12][31 * 200];
    //세로에 년과 월정보, 가로에 최대 31일에 대한 내용값
    //(년-2008)*12+(달-1)=값을 세로에 배정
    //(일-1)*200을 가로에 배정
    //re start!!
    //본래 4번에 배정되었던 검색하기 기능은
    //그냥 날짜설정하고 확인하기로 할수 있으므로 제외시킴
    char* pData;
    char temp[4], text[200];
    int i, pos, len, value, year, month, day;
    FILE* file;
    for (i = 0; i < 5 * 12; i++)//배열 내부값 초기화
        memset(calendar[i], 0, 31 * 200);
    pData = calendar[0];
    char my_query[100] = "";
    char b[50] = ")";
    char d[50] = "\'";
    char c[50] = ",";
    char year1[20] = "";
    char month1[20] = "";
    char day1[20] = "";


    while (1)
    {
        printf("일정관리 프로그램 2008년에서 2012년까지\n");
        printf("[1]날짜설정 [2]내용쓰기 [3]확인하기\n[4]저장하기 [5]불러오기 [0]종료하기\n");
        gets(temp);
        sscanf(temp, "%d", &value);
        if (value == 0)//[0]종료하기
            break;

        switch (value)
        {
        case 1://[1]날짜설정
            printf("년도: ");
            gets(temp);
            sscanf(temp, "%d", &year);
            itoa(year, year1, 10);
            if ((year < 2008) || (year > 2012))
            {
                printf("잘못된 년도 입력\n2008년에서 2012년 사이로 입력하세요\n\n");
                break;
            }

            printf(" 월 : ");
            gets(temp);
            sscanf(temp, "%d", &month);
            itoa(month, month1, 10);
            if ((month < 1) || (month > 12))
            {
                printf("잘못된 월 입력\n1월에서 12월 사이로 입력하세요\n\n");
                break;
            }
            pData = calendar[(year - 2008) * 12 + (month - 1)];

            printf(" 일 : ");
            gets(temp);
            sscanf(temp, "%d", &day);
            itoa(day, day1, 10);
            if ((month == 2) && ((year % 4) && (year % 400) && !(year % 100)) == 0)//이조건 만족하면 윤년
            {
                if ((day < 1) || (day > 29))//윤달일때의 에러처리
                {
                    printf("잘못된 일 입력\n1일에서 29일 사이로 입력하세요\n\n");
                    break;
                }
            }
            else if (month == 2)//윤달아닌 2월의 에러처리
            {
                if ((day < 1) || (day > 28))
                {
                    printf("잘못된 일 입력\n1일에서 28일 사이로 입력하세요\n\n");
                    break;
                }
            }
            else if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
            {
                if ((day < 1) || (day > 31))
                {
                    printf("잘못된 일 입력\n1일에서 31일 사이로 입력하세요\n\n");
                    break;
                }
            }
            else//나머지 월은 30일까지
            {
                if ((day < 1) || (day > 30))
                {
                    printf("잘못된 일 입력\n1일에서 30일 사이로 입력하세요\n\n");
                    break;
                }
            }
            printf("\n");
            pos = (day - 1) * 200;
            pData += pos;
            memcpy(pData, &day, 2);//일로 입력받은 최대 두자리 수를 메모리에 씀
            break;
        case 2://[2]내용쓰기
            printf("%d년 %d월 %d일에 내용을 씁니다\n", year, month, day);
            printf("내용입력: ");
            gets(text);
            len = strlen(text);
            if (len > 200)//200바이트 이상의 내용입력시의 에러처리
            {
                printf("너무 많은 내용을 입력하셨습니다\n\n");
                break;
            }
            strcpy(pData + 2, text);
            printf("\n");
            break;
        case 3://[3]확인하기
            printf("%d년 %d월 %d일 내용:%s", year, month, day, pData + 2);
            printf("\n\n");
            break;
        case 4://[4]저장하기
            
            strcpy(my_query ,"INSERT INTO todo VALUES('user_name', '");
            strcat(my_query, pData + 2);
            strcat(my_query, d);
            strcat(my_query, c);
            strcat(my_query, year1);
            strcat(my_query, c);
            strcat(my_query, month1);
            strcat(my_query, c);
            strcat(my_query, day1);
            strcat(my_query, b);

            printf("%s\n", my_query);
            mysql(my_query);
            
            break;
        case 5://[5]불러오기
            
            mysql_r("select * from todo");
            break;
        default:
            printf("잘못된 입력!\n\n");//초기메뉴에서 지정된값 이외의 값 입력시의 에러처리
            break;
        }
    }
    return 0;
}
