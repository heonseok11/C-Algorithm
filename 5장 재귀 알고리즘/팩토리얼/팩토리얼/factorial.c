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
	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &x);
	printf("%d�� ���丮�� ���� %d�Դϴ�.\n", x, factorial(x));
	printf("%d�� ���丮�� ���� %d�Դϴ�.\n", x, NotFactorial(x));
}