#include <stdio.h>
#include "IntStack.h"

int main()
{
	IntStack s;
	if (Initialize(&s, 64) == -1) {
		puts("스택 생성 실패");
		return 1;
	}

	while (1) {
		int menu, x;
		printf("현재 데이터 수 : %d / %d\n", getSize(&s), getCapacity(&s));
		printf("(1)푸시 (2)팝 (3)피크 (4)출력 (5)검색\n"); 
		printf("(6)Full? (7)Empty? (8)스택 클리어 (0)종료 : ");
		scanf_s("%d", &menu);


		if (menu == 0) break;
		switch (menu) {
		case 1: // 푸시
			printf("데이터 : ");
			scanf_s("%d", &x);
			if (Push(&s, x) == -1) puts("\a오류 : 푸시 실패"); // \a : 경고음
			break;
		case 2: // 팝
			if(Pop(&s,&x) == -1) puts("\a오류 : 팝 실패");
			else printf("팝 데이터는 %d입니다.\n",x);
			break;
		case 3: // 피크
			if(Peek(&s,&x) == -1) puts("\a오류 : 피크 실패");
			else printf("피크 데이터는 %d입니다.\n", x);
			break;
		case 4: // 전부 출력
			Print(&s);
			break;
		case 5: // 검색
			printf("검색할 데이터 : ");
			scanf_s("%d", &x);
			int num = Search(&s, x);
			if (num == -1) puts("\a오류 : 검색 실패");
			else printf("검색한 데이터 %d는 stk[%d]에 있었습니다.\n", x, s.stk[num]);
			break;
		case 6:
			if (IsFull(&s)) puts("스택이 가득 찼습니다.");
			else puts("아직 가득차지 않았습니다.");
			break;
		case 7:
			if (IsEmpty(&s)) puts("스택이 비었습니다.");
			else puts("스택에 push된 데이터가 있습니다.");
			break;
			/*--- 빈 상태 / 가득 찬 상태 ---*/
			// printf("스택이 비어 %s.\n", IsEmpty(&s) ? "있습니다" : "있지 않습니다");
			// printf("스택이 가득 %s.\n", IsFull(&s) ? "찼습니다" : "차지 않았습니다");
			// break;
		case 8:
			Clear(&s);
			puts("스택이 클리어 되었습니다.");
			break;
		}
		printf("\n");
	}

	Terminate(&s);
	return 0;

}