#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maxof(int num, const int p[]) // int *p
{
	int max = p[0];
	for (int i = 0; i < num; i++) {
		if (p[i] > max) max = p[i];
	}

	return max;
}

void main()
{
	int i, num;
	printf("사람 수 : "); scanf_s("%d", &num);
	int* height = (int*)calloc(num, sizeof(int)); 
	printf("%d명의 키를 입력하세요\n",num);
	srand(time(NULL));
	for (i = 0; i < num; i++) {
		height[i] = 100 + rand() % 90; // 100 ~ 189까지의 난수생성
		printf("height[%d] = %d\n",i ,height[i]); 
	}

	printf("가장 큰 사람은 키가 %d 입니다.", maxof(num, height));
	free(height);
}