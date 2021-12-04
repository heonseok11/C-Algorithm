#include <stdio.h>

int minof(const int a[], int n)
{
	int min = a[0];
	for (int i = 1; i < n; i++) {
		if (min > a[i]) min = a[i];
	}

	return min;
}



void main()
{
	int i, num;

	printf("사람 수 : ");
	scanf_s("%d", &num);
	int* height = (int*)calloc(num, sizeof(int));
	printf("%d 사람의 키를 입력하세요.\n",num);
	for (i = 0; i < num; i++) {
		printf("height[%d] : ", i);
		scanf_s("%d", &height[i]);
	}
	printf("최솟값은 %d 입니다.\n", minof(height, num));

	free(height);
}