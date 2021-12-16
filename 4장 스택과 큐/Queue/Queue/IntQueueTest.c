#include <stdio.h>
#include "IntQueue.h"

int main()
{
	QUE q;

	if (Initialize(&q, 6) == -1) {
		puts("큐 생성 실패");
		return 1;
	}

	while (1) {
		int m, x, idx;

		printf("현재 데이터 수 : %d / %d \n", Size(&q), Capacity(&q));
		printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (5)검색\n");
		printf("(6)비었나? (7)가득인가? (8)검색2 (9)모두삭제 (0)종료 : ");
		scanf_s("%d", &m);

		if (m == 0) break;
		switch (m) {
		case 1: 
			printf("데이터 : "); scanf_s("%d", &x);
			if (Enque(&q, x) == -1) puts("인큐 실패");
			break;
		case 2:
			if (Deque(&q, &x) == -1) puts("디큐 실패");
			else printf("디큐한 데이터 : %d", x);
			break;
		case 3:
			if (Peek(&q, &x) == -1) puts("피크 실패");
			else printf("피크한 데이터 : %d", x);
			break;
		case 4:
			Print(&q);
			break;
		case 5:
			printf("검색할 데이터 : "); scanf_s("%d", &x);
			idx = Search(&q, x); //	if ((idx = Search(&que, x)) == -1)
			if (idx == -1) puts("검색 실패"); 
			else printf("검색한 데이터 %d는 que[%d]에 있습니다!", x, idx);
			break;
		case 6:
			printf("큐가 %s.", IsEmpty(&q) ? "비었습니다!" : "큐에 정보가 있습니다!");
			break;
		case 7:
			printf("큐가 %s.", IsFull(&q) ? "가득입니다!" : "아직 공간이 있습니다.");
			break;
		case 8:
			printf("검색할 데이터 : "); scanf_s("%d", &x);
			if ((idx = Search2(&q, x)) == -1) puts("검색 실패");
			else printf("검색한 데이터 %d는 front에서 %d번째 위치에 있습니다!", x, idx);
			break;
		case 9:
			Clear(&q);
			break;
		}
		printf("\n\n");
	}

	Terminate(&q);
	return 0;
}