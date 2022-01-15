#include <stdio.h>
#include "double_stack.h"

int main()
{
	STACK s;
	if (initialize(&s, 32) == -1) {
		puts("스택 생성 실패");
		return 1;
	}

	while (1) {
		int menu, x;
		printf("스택A : %d / %d\n스택B : %d / %d\n", getSizeA(&s), getCapacity(&s), getSizeB(&s), getCapacity(&s));
		printf("(1)푸시A (2)팝A (3)피크A (4)출력 (5)검색\n");
		printf("(6)푸시B (7)팝B (8)피크B (9)클리어 (0)종료 : ");
		scanf_s("%d", &menu);


		if (menu == 0) break;
		switch (menu) {
		case 1: // 푸시
			printf("데이터 : ");
			scanf_s("%d", &x);
			if (PushA(&s, x) == -1) puts("\a오류 : 푸시 실패"); // \a : 경고음
			break;
		case 2: // 팝
			if (PopA(&s, &x) == -1) puts("\a오류 : 팝 실패");
			else printf("팝 데이터는 %d입니다.\n", x);
			break;
		case 3: // 피크
			if (PeekA(&s, &x) == -1) puts("\a오류 : 피크 실패");
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
			else if(num <= s.ptrA) printf("검색한 데이터 %d는 A_stk[%d]에 있었습니다.\n", x, s.stk[num]);
			else printf("검색한 데이터 %d는 B_stk[%d]에 있었습니다.\n", x, s.stk[num]);
			break;
		case 6:
			printf("데이터 : ");
			scanf_s("%d", &x);
			if (PushB(&s, x) == -1) puts("\a오류 : 푸시 실패"); // \a : 경고음
			break;
		case 7:
			if (PopB(&s, &x) == -1) puts("\a오류 : 팝 실패");
			else printf("팝 데이터는 %d입니다.\n", x);
			break;
		case 8:
			if (PeekB(&s, &x) == -1) puts("\a오류 : 피크 실패");
			else printf("피크 데이터는 %d입니다.\n", x);
			break;
		case 9:
			Clear(&s);
			break;
		}
		printf("\n");
	}

	terminate(&s);
	return 0;

}