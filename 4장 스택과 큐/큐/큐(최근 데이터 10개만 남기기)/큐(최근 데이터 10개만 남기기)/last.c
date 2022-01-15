#include <stdio.h>

#define N 10

void main()
{
	int i, retry, count = 0;
	int a[N];
	puts("정수 입력");
	do{
		printf("%d번째 정수 : ", count + 1);
		scanf_s("%d", &a[count++ % N]); // 10개가 지나면 처음썻던 데이터부터 덮어씀
		printf("계속하려면 1, 아니면 0을 눌러주세요 : ");
		scanf_s("%d", &retry);
	} while (retry);
	i = count - N;
	if (i < 0) i = 0;
	for (i; i < count; i++)
		printf("%2d번째 정수 = %d\n", i + 1, a[i % N]);

}