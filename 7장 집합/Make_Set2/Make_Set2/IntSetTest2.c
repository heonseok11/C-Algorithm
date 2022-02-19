#include <stdio.h>
#include "IntSet.h"

enum {ADD, RMV, SCH};

int scan_data(int sw) {
	int data;
	switch (sw) {
	case ADD: printf("�߰��� ������ : "); break;
	case RMV: printf("������ ������ : "); break;
	case SCH: printf("�˻��� ������ : "); break;
	}
	scanf_s("%d", &data);

	return data;
}

void main()
{
	IntSet s1, s2, temp;
	Initialize(&s1, 512); Initialize(&s2, 512); Initialize(&temp, 512);

	while (1) {
		int m, x, idx;

		printf("s1 = "); PrintLn(&s1);
		printf("s2 = "); PrintLn(&s2);

		printf("(1)s1�� �߰� (2)s1���� ���� (3)s1���� �˻� (4)s1<-s2 (5)���� ����\n");
		printf("(6)s2�� �߰� (2)s2���� ���� (3)s2���� �˻� (4)s2<-s1 (0)���� : ");
		scanf_s("%d", &m);
		if (!m) break;

		switch (m) {
		case 1: x = scan_data(ADD); Add(&s1, x); break;		// �߰�
		case 2: x = scan_data(RMV); Remove(&s1, x); break;  // ����
		case 3: x = scan_data(SCH); idx = IsMember(&s1, x); // �˻�
			printf("s1�� %d�� ��� ��%s.\n", x, idx >= 0 ? "���ϴ�" : "�� �ʽ��ϴ�"); 	break;
		case 4: Assign(&s1, &s2); break;
		case 5:
			printf("s1 == s2 : %s\n", Equal(&s1, &s2) ? "true" : "false");			// ������?
			printf("s1 & s2 : "); Intersection(&temp, &s1, &s2); PrintLn(&temp);	// ������
			printf("s1 | s2 : "); Union(&temp, &s1, &s2); PrintLn(&temp);			// ������
			printf("s1 - s2 : "); Difference(&temp, &s1, &s2); PrintLn(&temp);		// ������
			printf("s1�� s2�� �κ������� %s.\n", IsSubset(&s1, &s2) ? "�½��ϴ�" : "�ƴմϴ�");
			break;
		case 6: x = scan_data(ADD); Add(&s2, x); break;		// �߰�
		case 7: x = scan_data(RMV); Remove(&s2, x); break;  // ����
		case 8: x = scan_data(SCH); idx = IsMember(&s2, x); // �˻�
			printf("s2�� %d�� ��� ��%s.\n", x, idx >= 0 ? "���ϴ�" : "�� �ʽ��ϴ�"); 	break;
		case 9: Assign(&s2, &s1); break;
		}
		putchar('\n');

	}

	Terminate(&s1); Terminate(&s2); Terminate(&temp);
}