#include <stdio.h>
#include <malloc.h>

int search_idx(const int a[], int n, int key, int idx[])
{
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] == key) idx[count++] = i;
	}

	return count;
}

void main()
{
	int i, nx, key;
	puts("���� Ž��");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	int* a = (int*)calloc(nx, sizeof(int));
	int* index = (int*)calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("a[%d] : ", i);
		scanf_s("%d", &a[i]);
	}
	printf("Ű �Է� : ");
	scanf_s("%d", &key);
	int count = search_idx(a, nx, key, index);
	if (count == -1) puts("�˻� ����");
	else {
		printf("�迭���� %d�� ��ġ�� ", key);
		for (i = 0; i < count; i++) {
			printf(" %d", index[i]);
		}
	}
	

	free(a);
	free(index);
}