#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

void bubble1(int x[], int n)
{
	int k = 0;
	while (k < n - 1) {
		int last = n - 1; // ���������� ��ȯ�� ������ ��ġ ����
		for (int i = n - 1; i > k; i--) {
			if (x[i - 1] > x[i]) {
				swap(int, x[i - 1], x[i]);
				last = i;
			}
		}
		k = last;
	}
}


//���� ���� Q5
void bubble2(int x[], int n)
{
	int pass = 0;
	int count[2] = { 0, };

	int k = 0;
	while (k < n - 1) {
		int last = n - 1; // ���������� ��ȯ�� ������ ��ġ ����
		printf("�н�%d:\n", ++pass);
		for (int i = n - 1; i > k; i--) {

			for (int j = 0; j < n - 1; j++) {
				printf("%3d %c", x[j], (j != i - 1) ? ' ' : ((x[i - 1] > x[i]) ? '+' : '-'));
			}
			printf("%3d\n", x[n - 1]);

			count[0]++; // ��Ƚ��
			if (x[i - 1] > x[i]) {
				count[1]++; // ��ȯȽ��
				swap(int, x[i - 1], x[i]);
				last = i;
			}
		}
		for (int j = 0; j < n; j++) printf("%3d  ", x[j]);
		printf("\n");
		k = last;
	}
	printf("�񱳸� %dȸ �߽��ϴ�.\n", count[0]);
	printf("��ȯ�� %dȸ �߽��ϴ�.\n", count[1]);
}

void main()
{
	int i, nx;

	puts("��������");
	printf("��� ���� : "); scanf_s("%d", &nx);
	int* x = (int*)calloc(nx, sizeof(int));

	srand((unsigned int)time(NULL));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		x[i] = rand() % 20 + 1;
		printf("%d\n", x[i]);
	}

	bubble2(x, nx);
	
	printf("������������ �����߽��ϴ�.\n");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);
}