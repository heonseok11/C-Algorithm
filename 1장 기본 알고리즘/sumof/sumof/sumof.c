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

	printf("���� a,b�� ������ �� ������ ��� ������ ���� ���մϴ�.\n");
	printf("a�� �� : "); scanf_s("%d", &a);
	printf("b�� �� : "); scanf_s("%d", &b);

	sumof(a, b);


}