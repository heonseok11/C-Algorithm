#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do {type t = x;x = y; y = t;} while(0)

void partition(int a[], int n)
{
	int i;
	int left = 0;
	int right = n - 1;
	int pivot = a[n / 2]; // ��� ��Ҹ� �ǹ����� ����

	do {
		while (a[left] < pivot) left++; // �ǹ����� ū ��Ҹ� ã���� ���� 
		while (a[right] > pivot) right--; // �ǹ����� ���� ��Ҹ� ã���� ����

		if (left <= right) {
			swap(int, a[left], a[right]);
			left++;
			right--;
		}
	} while (left <= right);

	printf("�ǹ��� ���� %d�Դϴ�.\n", pivot);
	printf("�ǹ� ������ �׷�\n");
	for (i = 0; i <= left - 1; i++) 
		printf("%d ", a[i]);
	putchar('\n');

	if (left > right + 1) {
		printf("�ǹ��� ��ġ�ϴ� �׷�\n");
		for (i = right + 1; i <= left - 1; i++)
			printf("%d ", a[i]);
		putchar('\n');
	}
	printf("�ǹ� �̻��� �׷�\n");
	for (i = right + 1; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
}

void main()
{
	int i, nx;

	puts("�迭�� �����ϴ�.");
	printf("��� ���� : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));
	srand((unsigned int)time(NULL));

	for (i = 0; i < nx; i++) {
		x[i] = rand() % 15 + 1;
		printf("x[%d] = %d\n", i,x[i]);
	}

	partition(x, nx);
	free(x);


}

