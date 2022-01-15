#include <stdio.h>

int gcd(int x, int y)
{
	if (y == 0) return x;
	// ó���� x < y ���� �������. ��¥�� gcd�� �ѹ� ȣ���ϸ� ū�� �������� �ٲ��. 
	else return gcd(y, x % y); 
}

//����Լ�ȣ�� ���X
int gcd2(int x, int y)
{
	int euc_x;
	while (y) {
		euc_x = x;
		x = y;
		y = euc_x % y;
	}
	
	return x;
}

void main()
{
	int x, y;
	puts("�� ���� �ִ������� ���մϴ�.");
	printf("�� ������ �Է��ϼ��� : ");
	scanf_s("%d %d", &x, &y);
	printf("�ִ������� %d�Դϴ�.\n", gcd(x, y));
	printf("�ִ������� %d�Դϴ�.\n", gcd2(x, y));
}