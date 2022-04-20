#include <stdio.h>
#include "Member.h"
#include "ArrayLinkedList.h"

typedef enum {
	TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR,
	PRINT_CRNT, RMV_CRNT, SRCH_NO, SRCH_NAME, FIND_N_NODE, RMV_REPEAT, PRINT_ALL, CLEAR
}Menu;

Menu SelectMenu()
{
	int i, ch;
	char* mstring[] = {
		"머리에 노드 삽입", "꼬리에 노드 삽입", "머리 노드 삭제", "꼬리 노드 삭제",
		"선택한 노드 출력", "선택한 노드 삭제", "번호로 검색", "이름으로 검색",
		"n번째의 인덱스 반환", "중복 노드 삭제", "모든 노드를 출력", "모든 노드를 삭제"
	};

	do {
		for (i = TERMINATE; i < CLEAR; i++) {
			printf("(%2d) %-18s ", i + 1, mstring[i]);
			if (i % 3 == 2) putchar('\n');
		}
		printf("( 0) 종료 : ");
		scanf_s("%d", &ch);
	} while (ch < TERMINATE || ch > CLEAR);

	return (Menu)ch;
}

void main() {
	Menu menu;
	List list;
	int n = 0;
	Initialize(&list, 30);

	do {
		Member x;
		switch (menu = SelectMenu()) {
			// 머리에 노드 삽입
		case INS_FRONT:
			x = ScanMember("머리에 삽입", MEMBER_NO | MEMBER_NAME);
			InsertFront(&list, &x);
			break;

			// 꼬리에 노드 삽입
		case INS_REAR:
			x = ScanMember("꼬리에 삽입", MEMBER_NO | MEMBER_NAME);
			InsertRear(&list, &x);
			break;

			// 머리 노드 삭제
		case RMV_FRONT:
			RemoveFront(&list);
			break;

			// 꼬리 노드 삭제
		case RMV_REAR:
			RemoveRear(&list);
			break;

			// 선택한 노드의 데이터 출력
		case PRINT_CRNT:
			PrintLnCurrent(&list);
			break;

			// 선택한 노드를 삭제
		case RMV_CRNT:
			RemoveCurrent(&list);
			break;

			// 번호로 검색
		case SRCH_NO:
			x = ScanMember("검색", MEMBER_NO);
			if (search(&list, &x, MemberNoCmp) != null)
				PrintLnCurrent(&list);
			else
				puts("그 번호의 데이터가 없습니다.");
			break;

			// 이름으로 검색
		case SRCH_NAME:
			x = ScanMember("검색", MEMBER_NAME);
			if (search(&list, &x, MemberNameCmp) != null)
				PrintLnCurrent(&list);
			else
				puts("그 이름의 데이터가 없습니다.");
			break;

		case FIND_N_NODE:
			printf("n번째 노드의 인덱스를 반환합니다. : ");
			scanf("%d", &n);
			list.crnt = Retrieve(&list, n);
			PrintLnCurrent(&list);

		case RMV_REPEAT:
			Purge(&list, MemberCompare); // MemberCompare 함수에 대한 연구 필요
			break;

			// 모든 노드의 데이터 출력
		case PRINT_ALL:
			Print(&list);
			break;

			// 모든 노드 삭제
		case CLEAR:
			Clear(&list);
			break;
		}
		putchar('\n');
	} while (menu != TERMINATE);

	Terminate(&list);

}