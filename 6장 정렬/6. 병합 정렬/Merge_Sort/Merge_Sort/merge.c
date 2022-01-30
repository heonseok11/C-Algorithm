#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int* buff; // 작업용 배열

static void __mergesort(int a[], int left, int right)
{
	if (left < right) {
		int i;
		int center = (left + right) / 2;
		int p = 0;
		int j = 0;
		int k = left;

		__mergesort(a, left, center);		//앞부분에 대한 병합 정렬
		__mergesort(a, center + 1, right);  //뒷부분에 대한 병합 정렬

		for (i = left; i <= center; i++)
			buff[p++] = a[i]; //a배열에서 옮겨진 요소의 개수 + 1 저장
		while (i <= right && j < p)
			a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
		while (j < p) a[k++] = buff[j++];
	}
}

int mergesort(int a[], int n)
{
	if (NULL == (buff = (int*)calloc(n, sizeof(n)))) return -1;
	__mergesort(a, 0, n - 1);
	free(buff);
	return 0;
}

void main()
{
	int i, nx;
	puts("병합 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));

	srand((unsigned int)time(NULL));
	for (i = 0; i < nx; i++) {
		x[i] = rand() % 15 + 1;
		printf("x[%d] : %d\n", i, x[i]);
	}

	mergesort(x, nx);

	puts("정렬 완료");
	for (i = 0; i < nx; i++) {
		printf("x[%d] : %d\n", i, x[i]);
	}

	free(x);
}