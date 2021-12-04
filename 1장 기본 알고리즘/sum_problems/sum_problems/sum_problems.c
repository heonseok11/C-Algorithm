#include <stdio.h>

void sum(int n)
{
	int sum = 0, i;

	printf("\n");
	for (i = 1; i <= n; i++) {
		printf("%d", i);
		if (i < n) printf(" + ");
		else printf(" = ");
		sum += i;
	}
	printf("%d", sum);
}

void Gauss(int n)
{
	int sum = (1 + n) * (n / 2);
	if (n % 2 != 0) sum += (n + 1) / 2;
	//	sum = (n + 1) * (n / 2) + (n % 2 == 1 ? (n + 1) / 2 : 0);

	printf("sum = %d", sum);
}

void main()
{
	int n;
	printf("1부터 n까지의 합을 구합니다. n의 값을 입력해주세요 : ");
	scanf_s("%d", &n);
	//sum(n);
	Gauss(n);




}