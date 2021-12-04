#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

void ary_copy(int a[], const int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = b[i];
	}
}

void ary_rcopy(int a[], const int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = b[n - i - 1];
	}
}

void shuffle(int a[], int n)
{
	srand(time(NULL));
	int num;
	for (int i = 0; i < n; i++) {
		num = rand() % n;
		if(i != num) swap(int, a[i], a[num]);
	}
	
	//	for (i = n - 1; i> 0; i--) {		/* 배열 a를 셔플 */
	//		int num = rand() % (i + 1);
	//		if (i != num)
	//			swap(int, a[i], a[j]);
	//	}
}

void main()
{
	int n;
	printf("요소의 개수를 입력하세요 : "); scanf_s("%d", &n);

	int* b = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		printf("b[%d] = ",i);
		scanf_s("%d", &b[i]);
	}
	int* a = (int*)calloc(n, sizeof(int));

	ary_copy(a, b, n);
	//ary_rcopy(a, b, n);
	shuffle(a, n);

	for (int i = 0; i < n; i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}

	free(a);
	free(b);
}