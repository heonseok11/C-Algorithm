#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50
#define MIN 10

void fsort(int a[], int n, int min, int max)
{
	int i;
	int* f = (int*)calloc(max - min + 2, sizeof(int));		// ���� ����
	int* b = (int*)calloc(n, sizeof(int));					// �۾��� �迭

	for (i = 0; i < n; i++) f[a[i] - min]++;				// 0 ~ min - 1 ������ ���� �����Ƿ� ������ min ��ŭ ���ܼ� ����
	for (i = 1; i <= max - min + 1; i++) f[i] += f[i - 1];
	for (i = n - 1; i >= 0; i--) b[--f[a[i] - min]] = a[i];
	for (i = 0; i < n; i++) a[i] = b[i];


	free(f);
	free(b);
}


void main()
{
	int i, nx;
	puts("���� ����");
	printf("��� ���� : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));

	srand((unsigned int)time(NULL));
	for (i = 0; i < nx; i++) {
		x[i] = rand() % (MAX - MIN + 1) + MIN; // MIN ~ MAX ������ ����
		printf("x[%d] = %d\n", i, x[i]);
	}


	fsort(x, nx, MIN, MAX);
	puts("�������� ���� �Ǿ����ϴ�.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);
}