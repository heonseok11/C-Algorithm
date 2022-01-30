#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(const int a[], int na, const int b[], int nb, int c[])
{
	int pa = 0;
	int pb = 0;
	int pc = 0;

	while(pa < na && pb < nb) 
		c[pc++] = (a[pa] <= b[pb]) ? a[pa++] : b[pb++];

	//아직 남아있는 a 또는 b 배열의 요소를 c로 복사
	while (pa < na) c[pc++] = a[pa++];
	while (pb < nb) c[pc++] = b[pb++];

}

// 이미 정렬된 배열을 병합
void main()
{
	int i, na, nb;
	printf("a의 요소 개수 : "); scanf_s("%d", &na);
	printf("b의 요소 개수 : "); scanf_s("%d", &nb);

	int* a = (int*)calloc(na, sizeof(int));
	int* b = (int*)calloc(nb, sizeof(int));
	int* c = (int*)calloc(na + nb, sizeof(int));

	srand((unsigned int)time(NULL));

	printf("a[0] : "); scanf_s("%d", &a[0]);
	for (i = 1; i < na; i++) {
		do {
			a[i] = rand() % 30 + 1;
			printf("a[%d] : %d\n", i, a[i]);
		} while (a[i] < a[i - 1]);
	}

	printf("b[0] : "); scanf_s("%d", &b[0]);
	for (i = 1; i < nb; i++) {
		do {
			b[i] = rand() % 30 + 1;
			printf("b[%d] : %d\n", i, b[i]);
		} while (b[i] < b[i - 1]);
	}

	merge(a, na, b, nb, c);
	puts("배열 a와 배열 b를 병합하여 배열 c에 저장했습니다.");
	for (i = 0; i < na + nb; i++) {
		printf("c[%2d] : %2d\n", i, c[i]);
	}

	free(a); free(b); free(c);

}