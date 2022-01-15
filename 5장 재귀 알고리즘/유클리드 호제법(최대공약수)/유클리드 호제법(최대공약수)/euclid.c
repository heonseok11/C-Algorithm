#include <stdio.h>

int gcd(int x, int y)
{
	if (y == 0) return x;
	// 처음에 x < y 여도 상관없다. 어짜피 gcd를 한번 호출하면 큰수 작은수로 바뀐다. 
	else return gcd(y, x % y); 
}

//재귀함수호출 사용X
int gcd2(int x, int y)
{
	int euc_x;
	while (y) {
		euc_x = x;
		x = y;
		y = euc_x % y;
	}
	
	return x;
}

void main()
{
	int x, y;
	puts("두 수의 최대공약수를 구합니다.");
	printf("두 정수를 입력하세요 : ");
	scanf_s("%d %d", &x, &y);
	printf("최대공약수는 %d입니다.\n", gcd(x, y));
	printf("최대공약수는 %d입니다.\n", gcd2(x, y));
}