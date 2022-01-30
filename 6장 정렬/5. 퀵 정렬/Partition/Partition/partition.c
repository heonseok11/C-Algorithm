#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do {type t = x;x = y; y = t;} while(0)

void partition(int a[], int n)
{
	int i;
	int left = 0;
	int right = n - 1;
	int pivot = a[n / 2]; // 가운데 요소를 피벗으로 설정

	do {
		while (a[left] < pivot) left++; // 피벗보다 큰 요소를 찾으면 멈춤 
		while (a[right] > pivot) right--; // 피벗보다 작은 요소를 찾으면 멈춤

		if (left <= right) {
			swap(int, a[left], a[right]);
			left++;
			right--;
		}
	} while (left <= right);

	printf("피벗의 값은 %d입니다.\n", pivot);
	printf("피벗 이하의 그룹\n");
	for (i = 0; i <= left - 1; i++) 
		printf("%d ", a[i]);
	putchar('\n');

	if (left > right + 1) {
		printf("피벗과 일치하는 그룹\n");
		for (i = right + 1; i <= left - 1; i++)
			printf("%d ", a[i]);
		putchar('\n');
	}
	printf("피벗 이상의 그룹\n");
	for (i = right + 1; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
}

void main()
{
	int i, nx;

	puts("배열을 나눕니다.");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));
	srand((unsigned int)time(NULL));

	for (i = 0; i < nx; i++) {
		x[i] = rand() % 15 + 1;
		printf("x[%d] = %d\n", i,x[i]);
	}

	partition(x, nx);
	free(x);


}

