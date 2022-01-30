#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion(int a[], int n)
{
	int i, j;
	for (i = 1; i < n; i++) {
		int tmp = a[0] = a[i]; // ���� ���� ���ʰ����� ����
		for (j = i; a[j - 1] > tmp; j--) { // ���ʿ� tmp ���� ������ �񱳸� �ϱ� ������ a[0] == tmp �� j�� 0 �Ʒ��� ������ ���� ����. 
			a[j] = a[j - 1];
		}
		a[j] = tmp;
	}
}



void main()
{
	int nx, i;
	puts("�ܼ� ���� ����");

	printf("��� ���� : ");
	scanf_s("%d", &nx);
	int* x = (int*)calloc(nx + 1, sizeof(int)); // a[0] ���ʸ� ���� �ϳ� �� �ڸ��� ����

	srand((unsigned int)time(NULL));

	for (i = 1; i < nx + 1; i++) {
		x[i] = rand() % 15 + 1;
		printf("x[%d] = %d\n", i, x[i]);
	}

	insertion(x, nx + 1);

	puts("������������ �����߽��ϴ�.");
	for (i = 1; i < nx + 1; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);


}