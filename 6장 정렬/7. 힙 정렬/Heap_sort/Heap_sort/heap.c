#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type , x , y) do {type t = x; x = y; y = t;} while(0)

// �迭 a���� a[left] ~ a[right]�� ��Ҹ� ������ ����� �Լ� 
void downheap(int a[], int left, int right)
{
	int root = a[left];
	int child, parent;
	for (parent = left; parent < (right + 1) / 2; parent = child) { // �����Ŀ��� �θ𺸴� ū ��Ҹ� ������ child�� �ε����� parent�� ���Ե�
		int child_left = parent * 2 + 1;
		int child_right = child_left + 1;
		child = (child_right <= right && a[child_right] > a[child_left]) ? child_right : child_left; // �� ū �ڽ��� ����
		if (root >= a[child]) break;
		a[parent] = a[child]; // �θ𺸴� ū �ڽ��� �θ�� �ڸ��� �ٲ�
	}
	a[parent] = root;
}

void heapsort(int a[], int n)
{
	int i;
	for (i = (n - 1) / 2; i >= 0; i--) downheap(a, i, n - 1);
	for (i = n - 1; i > 0; i--) {
		swap(int, a[0], a[i]); // ��Ʈ�� �ִ� ���� ū ���� ���� �迭�� �ǵ��� ��ҿ� �ٲ�
		downheap(a, 0, i - 1);
	}

}

void main()
{
	int i, nx;
	puts("�� ����");
	printf("��� ���� : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));
	srand((unsigned int)time(NULL));

	for (i = 0; i < nx; i++) {
		x[i] = rand() % 15 + 1;
		printf("x[%d] : %d\n", i, x[i]);
	}

	heapsort(x, nx);

	puts("�� ���� �Ϸ�");
	for (i = 0; i < nx; i++) {
		printf("x[%d] : %d\n", i, x[i]);
	}

	free(x);

}