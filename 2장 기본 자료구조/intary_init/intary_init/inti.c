#include <stdio.h>

void main()
{
	int i;
	int a[5] = { 1,2,3,4,5 };
	int na = sizeof(a) / sizeof(a[0]);
	printf("배열 a의 요소 개수는 %d입니다.\n", na);

	for (i = 0; i < na; i++) {

		printf("a[%d] = %d\n", i, a[i]);

	}
}