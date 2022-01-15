#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

void bubble1(int x[], int n)
{
	int k = 0;
	while (k < n - 1) {
		int last = n - 1; // 마지막으로 교환을 수행한 위치 저장
		for (int i = n - 1; i > k; i--) {
			if (x[i - 1] > x[i]) {
				swap(int, x[i - 1], x[i]);
				last = i;
			}
		}
		k = last;
	}
}


//연습 문제 Q5
void bubble2(int x[], int n)
{
	int pass = 0;
	int count[2] = { 0, };

	int k = 0;
	while (k < n - 1) {
		int last = n - 1; // 마지막으로 교환을 수행한 위치 저장
		printf("패스%d:\n", ++pass);
		for (int i = n - 1; i > k; i--) {

			for (int j = 0; j < n - 1; j++) {
				printf("%3d %c", x[j], (j != i - 1) ? ' ' : ((x[i - 1] > x[i]) ? '+' : '-'));
			}
			printf("%3d\n", x[n - 1]);

			count[0]++; // 비교횟수
			if (x[i - 1] > x[i]) {
				count[1]++; // 교환횟수
				swap(int, x[i - 1], x[i]);
				last = i;
			}
		}
		for (int j = 0; j < n; j++) printf("%3d  ", x[j]);
		printf("\n");
		k = last;
	}
	printf("비교를 %d회 했습니다.\n", count[0]);
	printf("교환을 %d회 했습니다.\n", count[1]);
}

void main()
{
	int i, nx;

	puts("버블정렬");
	printf("요소 개수 : "); scanf_s("%d", &nx);
	int* x = (int*)calloc(nx, sizeof(int));

	srand((unsigned int)time(NULL));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		x[i] = rand() % 20 + 1;
		printf("%d\n", x[i]);
	}

	bubble2(x, nx);
	
	printf("오름차순으로 정리했습니다.\n");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);
}