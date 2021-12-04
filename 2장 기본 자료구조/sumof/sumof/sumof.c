#include <stdio.h>

int sumof(const int a[], int n)
{
	int i, sum = 0;
	for (i = 0; i < n; i++) {
		sum += a[i];
	}

	return sum;
}

double aveof(const int a[], int n)
{
	int i; 
	double sum = 0;

	for (i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum/n;
}


void main()
{
	int i, num;
	printf("사람수: "); scanf_s("%d", &num);
	int* height = (int*)calloc(num, sizeof(int));
	printf("%d 사람의 키를 입력하세요\n", num);
	for (i = 0; i < num; i++) {
		printf("height[%d] = ",i);
		scanf_s("%d", &height[i]);
	}
	//printf("키의 합계는 %d 입니다.", sumof(height, num));
	printf("키의 합계는 %f 입니다.", aveof(height, num));
	free(height);
}