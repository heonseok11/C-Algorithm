#include <stdio.h>
#include <stdlib.h>

void* searchx(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*))
{
	char* x = (char*)base;
	int first = 0;
	int last = nmemb - 1;
	int cen;

	do {
		cen = (first + last) / 2;
		int com = compar(key, (const void*)&x[cen * size]);

		if (!com) {
			while (cen > first && x[cen * size] == x[(cen - 1) * size]) cen--;
			return &x[cen * size];
		}
		else if (com < 0) last = cen - 1;
		else first = cen + 1;

	} while (first <= last);

	return NULL;
}

// �������� ���ĵ� ������ ���ϴ� �Լ�
int int_cmp(const int* key, const int* b)
{
	if (*key < *b) return -1;
	else if (*key > *b) return 1;
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
		do {
			printf("x[%d] : ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}
	printf("�˻��� : ");
	scanf_s("%d", &key);

	p = searchx(&key, // �˻����� ���� ������
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