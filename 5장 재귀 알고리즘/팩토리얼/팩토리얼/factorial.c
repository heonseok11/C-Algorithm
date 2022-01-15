#include <stdio.h>

int factorial(int n)
{
	if (n > 0) return n * factorial(n - 1);
	else return 1;
}

int NotFactorial(int n)
{
	int fact = n;
	while (--n > 0) {
		fact = fact * n;
	}
	return fact;
}

void main()
{
	int x;
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &x);
	printf("%d의 팩토리얼 값은 %d입니다.\n", x, factorial(x));
	printf("%d의 팩토리얼 값은 %d입니다.\n", x, NotFactorial(x));
}