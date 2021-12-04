#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maxof(const int a[], int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max) max = a[i];
	}

	return max;
}

void main()
{
	srand(time(NULL));
	int i, num;
	num = rand() % 16 + 5; // 5 ~ 20 사이의 난수 생성
	printf("사람수는 %d명 입니다.\n", num);
	int* height = (int*)calloc(num, sizeof(int));

	for (i = 0; i < num; i++) {
		height[i] = rand() % 90 + 100; // 100 ~ 189사이의 난수 생성
		printf("height[%d] = %d\n", i, height[i]);
	}

	printf("최댓값은 %d입니다.\n", maxof(height, num));
	free(height);
}