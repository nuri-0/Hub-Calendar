void insert(struct member* info) {

	char a[50], b[50];
	int i, j;
  
	printf("수정하실 회원의 성함을 입력해주세요. : ");
	scanf("%s", a);
	printf("\n");

	for (i = 0; i < cnt; i++) {
		if (strcmp(a, info[i].name) == 0) {
			while (1)
			{
				printf("수정하실 정보는 무엇입니까? 숫자로 입력해주세요.")
					printf("1.이름 2.나이 3.성별 4. 이메일 5. 전화번호 6. 종료\n");
				scanf("%d", &j);

				if (j == 1) {
					printf("수정하실 이름을 입력해주세요: \n");
					scanf("%s", info[i].name);
					printf("\n");
				}
				if (j == 2) 
				{
					printf("수정하실 나이를 입력해주세요: \n");
					scanf("%s", info[i].age);
					printf("\n");
				}
				if (j == 3)
				{
					printf("수정하실 성별을 입력해주세요: \n");
					scanf("%s", info[i].sex);
					printf("\n");
				}
				if (j == 4)
				{
					printf("수정하실 이메일을 입력해주세요: \n");
					scanf("%s", info[i].mail);
					printf("\n");
				}
				if (j == 5)
				{
					printf("수정하실 휴대전화번로를 입력해주세요: \n");
					scanf("%s", info[i].ph_num);
					printf("\n");
				}
				if (j == 6)
				{
					goto r1;
				}

			}
		r1:;
		}
	}
}
