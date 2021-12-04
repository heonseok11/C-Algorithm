#include <stdio.h>
#include <malloc.h>

int search1(const int p[], int n, int key)
{
	int i = 0;
	while (1) {
		if (i == n) return -1; // �˻�����
		else if (p[i] == key) return i; // �˻�����
		i++;
	}
}

int search2(int* p, int n, int key)
{
	for (int i = 0; i < n; i++) {
		if (p[i] == key) return i;
	}
	return -1;
}

void main()
{
	int nx, key, index;
	puts("�����˻�");
	printf("��Ұ��� : "); scanf_s("%d", &nx);
	int* p = (int*)calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++) {
		printf("p[%d] : ", i);
		scanf_s("%d", &p[i]);
	}

	printf("�˻��� �� : "); scanf_s("%d", &key);
	index = search1(p, nx, key);

	if (index == -1) puts("�˻� ����");
	else printf("%d�� p[%d]�� �ֽ��ϴ�. \n", key, index);
	
	free(p);
	
}