#include <stdio.h>
#include "double_stack.h"

int main()
{
	STACK s;
	if (initialize(&s, 32) == -1) {
		puts("���� ���� ����");
		return 1;
	}

	while (1) {
		int menu, x;
		printf("����A : %d / %d\n����B : %d / %d\n", getSizeA(&s), getCapacity(&s), getSizeB(&s), getCapacity(&s));
		printf("(1)Ǫ��A (2)��A (3)��ũA (4)��� (5)�˻�\n");
		printf("(6)Ǫ��B (7)��B (8)��ũB (9)Ŭ���� (0)���� : ");
		scanf_s("%d", &menu);


		if (menu == 0) break;
		switch (menu) {
		case 1: // Ǫ��
			printf("������ : ");
			scanf_s("%d", &x);
			if (PushA(&s, x) == -1) puts("\a���� : Ǫ�� ����"); // \a : �����
			break;
		case 2: // ��
			if (PopA(&s, &x) == -1) puts("\a���� : �� ����");
			else printf("�� �����ʹ� %d�Դϴ�.\n", x);
			break;
		case 3: // ��ũ
			if (PeekA(&s, &x) == -1) puts("\a���� : ��ũ ����");
			else printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			break;
		case 4: // ���� ���
			Print(&s);
			break;
		case 5: // �˻�
			printf("�˻��� ������ : ");
			scanf_s("%d", &x);
			int num = Search(&s, x);
			if (num == -1) puts("\a���� : �˻� ����");
			else if(num <= s.ptrA) printf("�˻��� ������ %d�� A_stk[%d]�� �־����ϴ�.\n", x, s.stk[num]);
			else printf("�˻��� ������ %d�� B_stk[%d]�� �־����ϴ�.\n", x, s.stk[num]);
			break;
		case 6:
			printf("������ : ");
			scanf_s("%d", &x);
			if (PushB(&s, x) == -1) puts("\a���� : Ǫ�� ����"); // \a : �����
			break;
		case 7:
			if (PopB(&s, &x) == -1) puts("\a���� : �� ����");
			else printf("�� �����ʹ� %d�Դϴ�.\n", x);
			break;
		case 8:
			if (PeekB(&s, &x) == -1) puts("\a���� : ��ũ ����");
			else printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
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