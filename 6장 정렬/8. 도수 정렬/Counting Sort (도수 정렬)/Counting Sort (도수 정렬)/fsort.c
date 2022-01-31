#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

void fsort(int a[], int n, int max)
{
	int i;
	int* f = (int*)calloc(max + 1, sizeof(int));		// ���� ����
	int* b = (int*)calloc(n, sizeof(int));				// �۾��� �迭

	for (i = 0; i < n; i++) f[a[i]] ++;					// a[1]�� 4 �̸� f[4]++
	for (i = 1; i <= max; i++) f[i] += f[i - 1];		// f[5]�� ���� 7 �̸� 0~5���� ���� 7����� ���̴� ==> 5�� ������ �ּ� 7��° ��� ��
	for (i = n - 1; i >= 0; i--) b[--f[a[i]]] = a[i];	// a[1]�� 4 �̸� f[4]�� ����Ǿ� �ִ� 0 ~ 4 ������ ������ Ȯ���ϰ� ���� - 1 �� �ε����� a[i] ���� ����ִ´�
	for (i = 0; i < n; i++) a[i] = b[i];


	free(f); 
	free(b);
}

// ���� ���� Q23
void fsort_print(int a[], int n, int max)
{
	int i, j;
	int* f = (int*)calloc(max + 1, sizeof(int));		// ���� ����
	int* b = (int*)calloc(n, sizeof(int));				// �۾��� �迭

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
	puts("���� ����");
	printf("��� ���� : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));

	srand((unsigned int)time(NULL));
	for (i = 0; i < nx; i++) {
		x[i] = rand() % MAX + 1; // 0 ~ MAX ������ ����
		printf("x[%d] = %d\n", i, x[i]);
	}


	//fsort(x, nx, MAX);
	fsort_print(x, nx, MAX);
	puts("�������� ���� �Ǿ����ϴ�.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);
}