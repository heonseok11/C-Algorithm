#include <stdio.h>

void recur(int n)
{
	if (n > 0) {
		recur(n - 1);
		printf("%d\n", n);
		recur(n - 2);
	}
}

// ���� ��͸� ����
void recur1(int n)
{
Top:
	if (n > 0) {
		recur(n - 1);
		printf("%d\n", n);
		n = n - 2; // ����Լ��� ������� ǥ��
		goto Top;
	}
}

void main()
{
	int x;
	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &x);
	recur(x);
}