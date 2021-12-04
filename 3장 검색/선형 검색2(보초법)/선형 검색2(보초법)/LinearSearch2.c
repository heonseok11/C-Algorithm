#include <stdio.h>
#include <malloc.h>

int search(int* p, int n, int key)
{
	int i = 0;
	p[n] = key; // ���ʸ� key ������ ����
	while (1) {
		if (p[i] == key) break;
		i++;
	}
	return i == n ? -1 : i;

}

int search2(int* p, int n, int key)
{
	int i = 0;
	p[n] = key; // ���ʸ� key ������ ����
	for (i = 0; i < n; i++) {
		if (p[i] == key) break;
	}

	return i == n ? -1 : i;

}

void main()
{
	int nx, key, index;
	puts("���� �˻�(���ʹ�)");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	int* p = (int*)calloc(nx + 1, sizeof(int)); // ���ʸ� ���� �� ������ ������ �߰� ����

	for (int i = 0; i < nx; i++) {
		printf("p[%d] = ", i);
		scanf_s("%d", p + i);
	}
	printf("�˻� �� : ");
	scanf_s("%d", &key);
	index = search2(p, nx, key);
	if (index == -1) puts("�˻� ����");
	else printf("%d�� p[%d]�� �ֽ��ϴ�.\n", key, index);

	free(p);
}