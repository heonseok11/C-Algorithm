#include <stdio.h>

void main()
{
	int i, n;
	int sum;
	puts("1부터 n까지의 합을 구합니다.");
	printf("n의 값 : ");
	scanf_s("%d", &n);
	sum = 0;
	i = 1;
	while (i <= n) {
		sum += i;
		i++;
	}
	printf("i의 값은 %d + 1 인 %d이고\n", n, i);
	printf("1부터 %d까지의 합은 %d입니다.\n", n, sum);

}