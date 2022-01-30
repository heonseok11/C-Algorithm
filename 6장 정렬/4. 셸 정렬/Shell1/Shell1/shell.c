#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int move;

void shell(int a[], int n)
{
	int i, j, h;
	for (h = n / 2; h > 0; h /= 2) {
		for (i = h; i < n; i++) {
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
				a[j + h] = a[j];
				move++;
			}
			a[j + h] = tmp;
			move++;
		}
	}
}


void main()
{
	int nx, i;
	puts("�� ����");

	printf("��� ���� : ");
	scanf_s("%d", &nx);
	int* x = (int*)calloc(nx, sizeof(int));

	srand((unsigned int)time(NULL));

	for (i = 0; i < nx; i++) {
		x[i] = rand() % 15 + 1;
		printf("x[%d] = %d\n", i, x[i]);
	}

	shell(x, nx);

	puts("������������ �����߽��ϴ�.");
	printf("�̵�Ƚ���� ������ �����ϴ� : %d\n", move);
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);


}