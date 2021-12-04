#include <stdio.h>
#include <stdlib.h>

int cmp(const long* a, const long* b)
{
	if (*a > *b) return -1;
	else if (*a < *b) return 1;
	else return 0;

}

void main()
{
	int nx;
	long key, * x, * p;
	puts("�������� long�� �迭 bsearch�� Ž��");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = (long*)calloc(nx, sizeof(long));
	printf("x[0] : ");
	scanf_s("%ld", &x[0]);
	for (int i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf_s("%ld", &x[i]);
		} while (x[i] > x[i - 1]);
	}
	printf("Ű �Է� : ");
	scanf_s("%ld", &key);

	p = bsearch(&key, x, nx, sizeof(long), (int(*)(const void*, const void*))cmp);
	if (NULL == p) puts("�˻� ����");
	else printf("%d�� x[%d]�� �ֽ��ϴ�.", key, (int)(p - x));
	free(x);

}