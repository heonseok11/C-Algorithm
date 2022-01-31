#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

void fsort(int a[], int n, int max)
{
	int i;
	int* f = (int*)calloc(max + 1, sizeof(int));		// 누적 도수
	int* b = (int*)calloc(n, sizeof(int));				// 작업용 배열

	for (i = 0; i < n; i++) f[a[i]] ++;					// a[1]이 4 이면 f[4]++
	for (i = 1; i <= max; i++) f[i] += f[i - 1];		// f[5]의 값이 7 이면 0~5까지 값이 7개라는 뜻이다 ==> 5의 순서가 최소 7번째 라는 뜻
	for (i = n - 1; i >= 0; i--) b[--f[a[i]]] = a[i];	// a[1]이 4 이면 f[4]에 저장되어 있는 0 ~ 4 까지의 개수를 확인하고 개수 - 1 의 인덱스에 a[i] 값을 집어넣는다
	for (i = 0; i < n; i++) a[i] = b[i];


	free(f); 
	free(b);
}

// 연습 문제 Q23
void fsort_print(int a[], int n, int max)
{
	int i, j;
	int* f = (int*)calloc(max + 1, sizeof(int));		// 누적 도수
	int* b = (int*)calloc(n, sizeof(int));				// 작업용 배열

	puts("step 1");
	for (i = 0; i < n; i++) {
		f[a[i]] ++;
		for (j = 0; j <= max; j++) printf("%2d ", f[j]);
		putchar('\n');
	}
	puts("step 2");
	for (i = 1; i <= max; i++) {
		f[i] += f[i - 1];
		for (j = 0; j <= max; j++) printf("%2d ", f[j]);
		putchar('\n');
	}
	puts("step 3");
	for (i = n - 1; i >= 0; i--) {
		b[--f[a[i]]] = a[i];
		for (j = 0; j < n; j++) printf("%2d ", b[j]);
		putchar('\n');
	}
	puts("step 4");
	for (i = 0; i < n; i++) {
		a[i] = b[i];
		for (j = 0; j < n; j++) printf("%2d ", a[j]);
		putchar('\n');
	}


	free(f);
	free(b);
}


void main()
{
	int i, nx;
	puts("도수 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));

	srand((unsigned int)time(NULL));
	for (i = 0; i < nx; i++) {
		x[i] = rand() % MAX + 1; // 0 ~ MAX 까지의 정수
		printf("x[%d] = %d\n", i, x[i]);
	}


	//fsort(x, nx, MAX);
	fsort_print(x, nx, MAX);
	puts("오름차순 정렬 되었습니다.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);
}