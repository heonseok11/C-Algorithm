#include <stdio.h>
#include "IntQueue.h"

int main()
{
	QUE q;

	if (Initialize(&q, 6) == -1) {
		puts("ť ���� ����");
		return 1;
	}

	while (1) {
		int m, x, idx;

		printf("���� ������ �� : %d / %d \n", Size(&q), Capacity(&q));
		printf("(1)��ť (2)��ť (3)��ũ (4)��� (5)�˻�\n");
		printf("(6)�����? (7)�����ΰ�? (8)�˻�2 (9)��λ��� (0)���� : ");
		scanf_s("%d", &m);

		if (m == 0) break;
		switch (m) {
		case 1: 
			printf("������ : "); scanf_s("%d", &x);
			if (Enque(&q, x) == -1) puts("��ť ����");
			break;
		case 2:
			if (Deque(&q, &x) == -1) puts("��ť ����");
			else printf("��ť�� ������ : %d", x);
			break;
		case 3:
			if (Peek(&q, &x) == -1) puts("��ũ ����");
			else printf("��ũ�� ������ : %d", x);
			break;
		case 4:
			Print(&q);
			break;
		case 5:
			printf("�˻��� ������ : "); scanf_s("%d", &x);
			idx = Search(&q, x); //	if ((idx = Search(&que, x)) == -1)
			if (idx == -1) puts("�˻� ����"); 
			else printf("�˻��� ������ %d�� que[%d]�� �ֽ��ϴ�!", x, idx);
			break;
		case 6:
			printf("ť�� %s.", IsEmpty(&q) ? "������ϴ�!" : "ť�� ������ �ֽ��ϴ�!");
			break;
		case 7:
			printf("ť�� %s.", IsFull(&q) ? "�����Դϴ�!" : "���� ������ �ֽ��ϴ�.");
			break;
		case 8:
			printf("�˻��� ������ : "); scanf_s("%d", &x);
			if ((idx = Search2(&q, x)) == -1) puts("�˻� ����");
			else printf("�˻��� ������ %d�� front���� %d��° ��ġ�� �ֽ��ϴ�!", x, idx);
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