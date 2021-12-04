#include <stdio.h>

int med(int a, int b, int c)
{
	if (a >= b) {
		if (b >= c) return b;
		// 아래는 b가 c보다 작은 경우 c > b
		else if (c >= a) return a;
		else return c; // a>c>b


	}
	// b가 a보다 큼
	else if (a > c) return a;
	else if (b > c) return c; // c가 a보다 크거나 같은데 b보다 작은 경우
	else return b; // c가 b보다도 커서 b가 중간값 


}

void main()
{
	int a, b, c;

	printf("세 정수의 중앙값을 구합니다.\n");
	
	printf("a의 값: "); scanf_s("%d", &a);
	printf("b의 값: "); scanf_s("%d", &b);
	printf("c의 값: "); scanf_s("%d", &c);

	printf("중앙값은 %d입니다.\n",med(a,b,c));

}