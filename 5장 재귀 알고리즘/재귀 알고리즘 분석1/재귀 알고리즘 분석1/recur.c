#include <stdio.h>

void recur(int n)
{
	if (n > 0) {
		recur(n - 1);
		printf("%d\n", n);
		recur(n - 2);
	}
}

// 꼬리 재귀를 제거
void recur1(int n)
{
Top:
	if (n > 0) {
		recur(n - 1);
		printf("%d\n", n);
		n = n - 2; // 재귀함수의 비재귀적 표현
		goto Top;
	}
}

void main()
{
	int x;
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &x);
	recur(x);
}