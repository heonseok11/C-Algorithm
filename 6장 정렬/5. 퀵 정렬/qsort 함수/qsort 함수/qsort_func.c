#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int int_cmp(const int* a, const int* b)
{
	if (*a < *b) return -1;
	else if (*a > *b) return 1;
	else return 0;
}

void main()
{
	int i, nx;
	printf("qsort�� ���� ����\n");
	printf("��� ���� : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));
	
	srand((unsigned int)time(NULL));
	for (i = 0; i < nx; i++){
		x[i] = rand() % 15 + 1;
		printf("x[%d] = %d\n", i, x[i]);
	}

	qsort(x,
		  nx,
		  sizeof(int),
		  (int(*)(const void*, const void*))int_cmp
	);
	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}
}