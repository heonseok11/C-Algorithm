#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int move;

// �� ���� �Լ� ���� : h = ...,13,4,1
void shell(int a[], int n)
{
	int i, j, h;

	for (h = 1; h < n / 9; h = h * 3 + 1); // h�� �ʱ갪�� �ʹ� ũ�� ȿ���� ���� ������ �迭�� ��� ���� n�� 9�� ���� ���� ���� �ʵ��� ���ؾ� ��. 

	//�ʱⰪ�� ������ ����
	for (; h > 0; h /= 3) {
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