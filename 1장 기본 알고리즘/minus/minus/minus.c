#include <stdio.h>

void main()
{
	int a, b;

	printf("a의 값 : "); 
	scanf_s("%d", &a);
	do {
		printf("b의 값 : ");
		scanf_s("%d", &b);
		if (b <= a) printf("a보다 큰 값을 입력하세요!\n");
	} while (b <= a);

//	while (1) {
//		printf("b 값 : ");
//		scanf("%d", &b);
//		if (b > a) break;
//		printf("a보다 큰 값을 입력하세요!\n");
//	}

	printf("b - a 는 %d입니다.", b - a);

}