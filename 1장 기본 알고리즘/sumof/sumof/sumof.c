#include <stdio.h>


void sumof(int a, int b)
{
	int n = b - a;
	if (n < 0) n *= -1;
	n++;


	int sum = (a + b) * (n / 2) + ((n % 2 == 1) ? (n + 1) / 2 : 0);
	//	for (i = min; i <= max; i++)
    //		sum += i;

	printf("sum = %d", sum);

}

void main()
{
	int a, b;

	printf("정수 a,b를 포함한 그 사이의 모든 정수의 합을 구합니다.\n");
	printf("a의 값 : "); scanf_s("%d", &a);
	printf("b의 값 : "); scanf_s("%d", &b);

	sumof(a, b);


}