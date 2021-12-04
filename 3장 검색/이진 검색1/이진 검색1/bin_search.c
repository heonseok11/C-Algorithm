#include <stdio.h>
#include <malloc.h>

int search(int* x, int n, int key)
{
	int first = 0; // �˻����� �� ���� �ε���
	int last = n - 1; // �˻����� �� ���� �ε���
	int cen; // �˻� ���� �� ����� �ε���
	do {
		cen = (first + last) / 2;
		if (x[cen] == key) return cen; // �˻� ����
		else if (x[cen] < key) first = cen + 1;
		else last = cen - 1;
	} while (first <= last);

	return -1;
}

void main()
{
	int nx, key, idx;
	puts("���� Ž��");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	int* x = (int*)calloc(nx, sizeof(int));

	puts("������������ �Է��ϼ���.");
	printf("x[0] : ");
	scanf_s("%d", &x[0]);
	for (int i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf_s("%d", x + i);
		} while (x[i - 1] > x[i]); // ������������ �ۼ��ؾ� �ϹǷ� ���� �׺��� ���� ���ڸ� �Է��ϸ� �ٽ� �Է�
	}

	printf("�˻� �� : ");
	scanf_s("%d", &key);
	idx = search(x, nx, key);

	if (idx == -1) puts("�˻� ����");
	else printf("%d�� x[%d]�� �־����ϴ�.\n", key, idx);

	free(x);

}