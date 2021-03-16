void list(struct member *info)
{
	int i, j;
	printf("1. 전체 회원정보 조회 2.개인 회원정보 조회\n");
	scnaf("%d, &i");
	
	if (i == 1)
	{
		for (j = 0; j < cnt; j++)
		{
			printf("이름:%s 나이:%s 성별:%s 이메일:%s 휴대전화 번호: %s\n"), info[j].name, info[j].age, info[j].sex, info[j].mail, info[j].ph_num);
		}
	}
	else {
		char a[50];
		int i;
		printf("이름을 입력하세요: ");
		scaf("%s", a);
		printf("\n");

		for (i = 0; i < cnt; i++) {
			if (strcmp(a, info[i], name) == 0) {
				printf("이름:%s 나이:%s 성별:%s 이메일:%s 휴대전화 번호: %s\n"), info[i].name, info[i].age, info[i].sex, info[i].mail, info[i].ph_num);
			}
		}
	}
}
