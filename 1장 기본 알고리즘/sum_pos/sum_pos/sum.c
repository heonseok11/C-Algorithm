#include <stdio.h>

void main()
{
	int i, n;
	int sum = 0;
	puts("1���� n������ ���� ���մϴ�. ");
	do {
		printf("n�� �� : ");
		scanf_s("%d", &n);
	} while (n <= 0);
	
	for (i = 0; i <= n; i++) {
		sum += i;
	}
	printf("sum = %d", sum);

}