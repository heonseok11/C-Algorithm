#include <stdio.h>

void main()
{
	int i;
	int a[5] = { 1,2,3,4,5 };
	int na = sizeof(a) / sizeof(a[0]);
	printf("�迭 a�� ��� ������ %d�Դϴ�.\n", na);

	for (i = 0; i < na; i++) {

		printf("a[%d] = %d\n", i, a[i]);

	}
}