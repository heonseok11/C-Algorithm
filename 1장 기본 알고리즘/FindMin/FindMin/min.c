#include <stdio.h>

int Min(int a, int b, int c, int d)
{
	int min = a;
	if (b < min) min = b;
	if (c < min) min = c;
	if (d < min) min = d;
	return min;
}


void main()
{
	int a, b, c, d;
	

	printf("값을 입력하면 최솟값을 찾습니다. \n");
	printf("a의 값: "); scanf_s("%d", &a);
	printf("b의 값: "); scanf_s("%d", &b);
	printf("c의 값: "); scanf_s("%d", &c);
	printf("d의 값: "); scanf_s("%d", &d);

	int min = Min(a, b, c, d);

	printf("최솟값은 %d 입니다.\n",min); //	printf("최솟값은 %d입니다.\n", min4(a, b, c, d));


}