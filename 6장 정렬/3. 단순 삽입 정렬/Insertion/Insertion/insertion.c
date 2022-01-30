#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion(int a[], int n)
{
	int i, j;
	for (i = 1; i < n; i++) {
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--) { // j�� 0���� ũ��, ���ʿ� �ִ� ��Ұ� tmp���� ũ�� ��� ����(���� ��Ұ� tmp���� �۰ų� ������ ����)
			a[j] = a[j - 1];
		}
		a[j] = tmp;
	}
}

//���� ����Q8
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
	puts("�ܼ� ���� ����");

	printf("��� ���� : ");
	scanf_s("%d", &nx);
	int* x = (int*)calloc(nx, sizeof(int));

	srand((unsigned int)time(NULL));

	for (i = 0; i < nx; i++) {
		x[i] = rand() % 15 + 1;
		printf("x[%d] = %d\n", i, x[i]);
	}

	insertion2(x, nx);

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);


}