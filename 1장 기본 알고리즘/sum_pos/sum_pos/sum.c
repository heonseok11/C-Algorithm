#include <stdio.h>

void main()
{
	int i, n;
	int sum = 0;
	puts("1부터 n까지의 합을 구합니다. ");
	do {
		printf("n의 값 : ");
		scanf_s("%d", &n);
	} while (n <= 0);
	
	for (i = 0; i <= n; i++) {
		sum += i;
	}
	printf("sum = %d", sum);

}