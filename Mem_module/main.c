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

//void join(struct member *info); 지금은 주석처리, 추후 코드 추가 및 수정시에 같이 열어볼 예정.
//void list(struct member *info);
//void insert(struct member *info);

int main(int argc, char *argv[])
{
	while(1){
		struct member info[100];
		int i;
		printf("1. 회원가입\n");
		printf("2. 회원목록 확인\n");
		printf("3. 회원정보 수정\n");
		printf("4.종료\n");
		printf("번호를 입력하세요.");
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
