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

	//���� �����ִ� a �Ǵ� b �迭�� ��Ҹ� c�� ����
	while (pa < na) c[pc++] = a[pa++];
	while (pb < nb) c[pc++] = b[pb++];

}

// �̹� ���ĵ� �迭�� ����
void main()
{
	int i, na, nb;
	printf("a�� ��� ���� : "); scanf_s("%d", &na);
	printf("b�� ��� ���� : "); scanf_s("%d", &nb);

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
	puts("�迭 a�� �迭 b�� �����Ͽ� �迭 c�� �����߽��ϴ�.");
	for (i = 0; i < na + nb; i++) {
		printf("c[%2d] : %2d\n", i, c[i]);
	}

	free(a); free(b); free(c);

}