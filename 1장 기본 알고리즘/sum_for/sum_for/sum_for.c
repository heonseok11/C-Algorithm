#include <stdio.h>

void main()
{
	int i, n;
	int sum;
	puts("1���� n������ ���� ���մϴ�.");
	printf("n�� �� : "); scanf_s("%d", &n);

	sum = 0;
	for (i = 0; i <= n; i++) {
		sum += i;
	}

	printf("1���� %d������ ���� %d�Դϴ�. \n",n,sum);

}