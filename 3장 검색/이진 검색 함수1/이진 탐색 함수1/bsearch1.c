#include <stdio.h>
#include <stdlib.h>

// �������� ���ĵ� ������ ���ϴ� �Լ�
int int_cmp(const int* a, const int* b)
{
	if (*a < *b) return -1;		// ���� ���� ���� ������ ������ ���� ��ȯ
	else if (*a > *b) return 1; // ���� ���� ���� ������ ũ�� ��� ��ȯ
	else return 0; // ������ 0 ��ȯ
}

void main()
{
	int nx, key;
	int* p; // ���� Ž���� key ���� ��ġ�ϴ� ��ҿ� ���� ������
	puts("bsearch �Լ��� �̿��Ͽ� �˻�");
	printf("��� ���� : "); scanf_s("%d", &nx);
	int* x = (int*)calloc(nx, sizeof(int));

	printf("������������ ���� �Է�\n");
	printf("x[0] : "); scanf_s("%d", &x[0]);
	for (int i = 1; i < nx; i++) {
		do{
			printf("x[%d] : ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}
	printf("�˻��� : ");
	scanf_s("%d", &key);

	p = bsearch(&key, // �˻����� ���� ������
				x,    // �迭
				nx,   // ����� ����
				sizeof(int), // ����� ũ��
				(int(*)(const void*, const void*))int_cmp // ���Լ�
				//compare �Լ��� ���ϰ��� ����� ��� ������, ������ ��� ������ Ž��

	);

	if (p == NULL) puts("�˻��� ������");
	else printf("%d�� x[%d]�� �ֽ��ϴ�.", key, (int)(p - x));
	free(x);
}