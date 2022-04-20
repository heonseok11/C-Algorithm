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
		"�Ӹ��� ��� ����", "������ ��� ����", "�Ӹ� ��� ����", "���� ��� ����",
		"������ ��� ���", "������ ��� ����", "��ȣ�� �˻�", "�̸����� �˻�",
		"n��°�� �ε��� ��ȯ", "�ߺ� ��� ����", "��� ��带 ���", "��� ��带 ����"
	};

	do {
		for (i = TERMINATE; i < CLEAR; i++) {
			printf("(%2d) %-18s ", i + 1, mstring[i]);
			if (i % 3 == 2) putchar('\n');
		}
		printf("( 0) ���� : ");
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
			// �Ӹ��� ��� ����
		case INS_FRONT:
			x = ScanMember("�Ӹ��� ����", MEMBER_NO | MEMBER_NAME);
			InsertFront(&list, &x);
			break;

			// ������ ��� ����
		case INS_REAR:
			x = ScanMember("������ ����", MEMBER_NO | MEMBER_NAME);
			InsertRear(&list, &x);
			break;

			// �Ӹ� ��� ����
		case RMV_FRONT:
			RemoveFront(&list);
			break;

			// ���� ��� ����
		case RMV_REAR:
			RemoveRear(&list);
			break;

			// ������ ����� ������ ���
		case PRINT_CRNT:
			PrintLnCurrent(&list);
			break;

			// ������ ��带 ����
		case RMV_CRNT:
			RemoveCurrent(&list);
			break;

			// ��ȣ�� �˻�
		case SRCH_NO:
			x = ScanMember("�˻�", MEMBER_NO);
			if (search(&list, &x, MemberNoCmp) != null)
				PrintLnCurrent(&list);
			else
				puts("�� ��ȣ�� �����Ͱ� �����ϴ�.");
			break;

			// �̸����� �˻�
		case SRCH_NAME:
			x = ScanMember("�˻�", MEMBER_NAME);
			if (search(&list, &x, MemberNameCmp) != null)
				PrintLnCurrent(&list);
			else
				puts("�� �̸��� �����Ͱ� �����ϴ�.");
			break;

		case FIND_N_NODE:
			printf("n��° ����� �ε����� ��ȯ�մϴ�. : ");
			scanf("%d", &n);
			list.crnt = Retrieve(&list, n);
			PrintLnCurrent(&list);

		case RMV_REPEAT:
			Purge(&list, MemberCompare); // MemberCompare �Լ��� ���� ���� �ʿ�
			break;

			// ��� ����� ������ ���
		case PRINT_ALL:
			Print(&list);
			break;

			// ��� ��� ����
		case CLEAR:
			Clear(&list);
			break;
		}
		putchar('\n');
	} while (menu != TERMINATE);

	Terminate(&list);

}