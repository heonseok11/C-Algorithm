#include <stdio.h>
#include "IntStack.h"

int main()
{
	IntStack s;
	if (Initialize(&s, 64) == -1) {
		puts("���� ���� ����");
		return 1;
	}

	while (1) {
		int menu, x;
		printf("���� ������ �� : %d / %d\n", getSize(&s), getCapacity(&s));
		printf("(1)Ǫ�� (2)�� (3)��ũ (4)��� (5)�˻�\n"); 
		printf("(6)Full? (7)Empty? (8)���� Ŭ���� (0)���� : ");
		scanf_s("%d", &menu);


		if (menu == 0) break;
		switch (menu) {
		case 1: // Ǫ��
			printf("������ : ");
			scanf_s("%d", &x);
			if (Push(&s, x) == -1) puts("\a���� : Ǫ�� ����"); // \a : �����
			break;
		case 2: // ��
			if(Pop(&s,&x) == -1) puts("\a���� : �� ����");
			else printf("�� �����ʹ� %d�Դϴ�.\n",x);
			break;
		case 3: // ��ũ
			if(Peek(&s,&x) == -1) puts("\a���� : ��ũ ����");
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
			else printf("�˻��� ������ %d�� stk[%d]�� �־����ϴ�.\n", x, s.stk[num]);
			break;
		case 6:
			if (IsFull(&s)) puts("������ ���� á���ϴ�.");
			else puts("���� �������� �ʾҽ��ϴ�.");
			break;
		case 7:
			if (IsEmpty(&s)) puts("������ ������ϴ�.");
			else puts("���ÿ� push�� �����Ͱ� �ֽ��ϴ�.");
			break;
			/*--- �� ���� / ���� �� ���� ---*/
			// printf("������ ��� %s.\n", IsEmpty(&s) ? "�ֽ��ϴ�" : "���� �ʽ��ϴ�");
			// printf("������ ���� %s.\n", IsFull(&s) ? "á���ϴ�" : "���� �ʾҽ��ϴ�");
			// break;
		case 8:
			Clear(&s);
			puts("������ Ŭ���� �Ǿ����ϴ�.");
			break;
		}
		printf("\n");
	}

	Terminate(&s);
	return 0;

}