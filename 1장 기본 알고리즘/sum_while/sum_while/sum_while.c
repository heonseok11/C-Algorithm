#include <stdio.h>

void main()
{
	int i, n;
	int sum;
	puts("1���� n������ ���� ���մϴ�.");
	printf("n�� �� : ");
	scanf_s("%d", &n);
	sum = 0;
	i = 1;
	while (i <= n) {
		sum += i;
		i++;
	}
	printf("i�� ���� %d + 1 �� %d�̰�\n", n, i);
	printf("1���� %d������ ���� %d�Դϴ�.\n", n, sum);

}