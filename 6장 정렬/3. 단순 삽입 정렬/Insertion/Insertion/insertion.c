#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion(int a[], int n)
{
	int i, j;
	for (i = 1; i < n; i++) {
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--) { // j가 0보다 크고, 왼쪽에 있는 요소가 tmp보다 크면 계속 진행(왼쪽 요소가 tmp보다 작거나 같으면 종료)
			a[j] = a[j - 1];
		}
		a[j] = tmp;
	}
}

//연습 문제Q8
void insertion2(int a[], int n)
{
	int i, j, k;
	 
	for (i = 1; i < n; i++) {
		 
		int tmp = a[i];

		for (k = 0; k < n; k++) {
			printf("%3d ", a[k]);
		}
		putchar('\n');
		
		for (j = i; j > 0 && a[j - 1] > tmp; j--) {
			a[j] = a[j - 1];
		}
		a[j] = tmp;

		printf("%*s%s", 4 * j, "", (i != j) ? "^-" : "  ");

		for (k = 0; k < 4 * (i - j); k++) putchar('-');
		printf("+\n\n");
	}

	for (k = 0; k < n; k++) {
		printf("%3d ", a[k]);
	}
	putchar('\n');
}

void main() 
{
	int nx, i;
	puts("단순 삽입 정렬");

	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	int* x = (int*)calloc(nx, sizeof(int));

	srand((unsigned int)time(NULL));

	for (i = 0; i < nx; i++) {
		x[i] = rand() % 15 + 1;
		printf("x[%d] = %d\n", i, x[i]);
	}

	insertion2(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);


}