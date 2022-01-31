#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50
#define MIN 10

void fsort(int a[], int n, int min, int max)
{
	int i;
	int* f = (int*)calloc(max - min + 2, sizeof(int));		// 누적 도수
	int* b = (int*)calloc(n, sizeof(int));					// 작업용 배열

	for (i = 0; i < n; i++) f[a[i] - min]++;				// 0 ~ min - 1 까지의 수가 없으므로 앞으로 min 만큼 땡겨서 저장
	for (i = 1; i <= max - min + 1; i++) f[i] += f[i - 1];
	for (i = n - 1; i >= 0; i--) b[--f[a[i] - min]] = a[i];
	for (i = 0; i < n; i++) a[i] = b[i];


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
		x[i] = rand() % (MAX - MIN + 1) + MIN; // MIN ~ MAX 까지의 정수
		printf("x[%d] = %d\n", i, x[i]);
	}


	fsort(x, nx, MIN, MAX);
	puts("오름차순 정렬 되었습니다.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);
}