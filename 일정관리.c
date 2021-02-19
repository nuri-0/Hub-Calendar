#include <stdio.h>
#include <string.h>

int main()
{
    char calendar[5 * 12][31 * 200];
    //���ο� ��� ������, ���ο� �ִ� 31�Ͽ� ���� ���밪
    //(��-2008)*12+(��-1)=���� ���ο� ����
    //(��-1)*200�� ���ο� ����
    //re start!!
    //���� 4���� �����Ǿ��� �˻��ϱ� �����
    //�׳� ��¥�����ϰ� Ȯ���ϱ�� �Ҽ� �����Ƿ� ���ܽ�Ŵ
    char* pData;
    char temp[4], text[200];
    int i, pos, len, value, year, month, day;
    FILE* file;
    for (i = 0; i < 5 * 12; i++)//�迭 ���ΰ� �ʱ�ȭ
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
        printf("�������� ���α׷� 2008�⿡�� 2012�����\n");
        printf("[1]��¥���� [2]���뾲�� [3]Ȯ���ϱ�\n[4]�����ϱ� [5]�ҷ����� [0]�����ϱ�\n");
        gets(temp);
        sscanf(temp, "%d", &value);
        if (value == 0)//[0]�����ϱ�
            break;

        switch (value)
        {
        case 1://[1]��¥����
            printf("�⵵: ");
            gets(temp);
            sscanf(temp, "%d", &year);
            itoa(year, year1, 10);
            if ((year < 2008) || (year > 2012))
            {
                printf("�߸��� �⵵ �Է�\n2008�⿡�� 2012�� ���̷� �Է��ϼ���\n\n");
                break;
            }

            printf(" �� : ");
            gets(temp);
            sscanf(temp, "%d", &month);
            itoa(month, month1, 10);
            if ((month < 1) || (month > 12))
            {
                printf("�߸��� �� �Է�\n1������ 12�� ���̷� �Է��ϼ���\n\n");
                break;
            }
            pData = calendar[(year - 2008) * 12 + (month - 1)];

            printf(" �� : ");
            gets(temp);
            sscanf(temp, "%d", &day);
            itoa(day, day1, 10);
            if ((month == 2) && ((year % 4) && (year % 400) && !(year % 100)) == 0)//������ �����ϸ� ����
            {
                if ((day < 1) || (day > 29))//�����϶��� ����ó��
                {
                    printf("�߸��� �� �Է�\n1�Ͽ��� 29�� ���̷� �Է��ϼ���\n\n");
                    break;
                }
            }
            else if (month == 2)//���޾ƴ� 2���� ����ó��
            {
                if ((day < 1) || (day > 28))
                {
                    printf("�߸��� �� �Է�\n1�Ͽ��� 28�� ���̷� �Է��ϼ���\n\n");
                    break;
                }
            }
            else if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
            {
                if ((day < 1) || (day > 31))
                {
                    printf("�߸��� �� �Է�\n1�Ͽ��� 31�� ���̷� �Է��ϼ���\n\n");
                    break;
                }
            }
            else//������ ���� 30�ϱ���
            {
                if ((day < 1) || (day > 30))
                {
                    printf("�߸��� �� �Է�\n1�Ͽ��� 30�� ���̷� �Է��ϼ���\n\n");
                    break;
                }
            }
            printf("\n");
            pos = (day - 1) * 200;
            pData += pos;
            memcpy(pData, &day, 2);//�Ϸ� �Է¹��� �ִ� ���ڸ� ���� �޸𸮿� ��
            break;
        case 2://[2]���뾲��
            printf("%d�� %d�� %d�Ͽ� ������ ���ϴ�\n", year, month, day);
            printf("�����Է�: ");
            gets(text);
            len = strlen(text);
            if (len > 200)//200����Ʈ �̻��� �����Է½��� ����ó��
            {
                printf("�ʹ� ���� ������ �Է��ϼ̽��ϴ�\n\n");
                break;
            }
            strcpy(pData + 2, text);
            printf("\n");
            break;
        case 3://[3]Ȯ���ϱ�
            printf("%d�� %d�� %d�� ����:%s", year, month, day, pData + 2);
            printf("\n\n");
            break;
        case 4://[4]�����ϱ�
            
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
        case 5://[5]�ҷ�����
            
            mysql_r("select * from todo");
            break;
        default:
            printf("�߸��� �Է�!\n\n");//�ʱ�޴����� �����Ȱ� �̿��� �� �Է½��� ����ó��
            break;
        }
    }
    return 0;
}
