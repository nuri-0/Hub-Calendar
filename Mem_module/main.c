#include <stdio.h>
#include <string.h>

int cnt;

struct member
{
	char name[10];
	char age[10];
	char sex[10];
	char mail[40];
	char ph_num[40];
};

//void join(struct member *info);
//void list(struct member *info);
//void insert(struct member *info);

int main(int argc, char *argv[])
{
	while(1){
		struct member info[100];
		int i;
		printf("1. ȸ������\n");
		printf("2. ȸ����� Ȯ��\n");
		printf("3. ȸ������ ����\n");
		printf("4.����\n");
		printf("��ȣ�� �Է��ϼ���.");
		scanf_s("%d", &i);
		printf("\n");
		
		if(i==1){
			join(info);
			i=0;
		}
		if(i==2){
			list(info);
		}
		if(i==3){
			insert(info);
		}
		if(i==4)
		break;
	}
	
	return 0;
	
}
