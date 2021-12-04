#include <stdio.h>
#include <stdlib.h>

int int_cmpr(const int* a, const int* b)
{
	if (*a < *b) return 1;
	else if (*a > *b) return -1;
	else return 0;
}

void main()
{
	int nx, key;
	puts("bsearch �Լ� ����Ͽ� �˻�");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	int* x = (int*)calloc(nx, sizeof(int));
	printf("������������ �Է��ϼ���\n");
	printf("x[0] : ");
	scanf_s("%d", &x[0]);
	for (int i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] > x[i - 1]);
		
	}
	printf("Ű�� : ");
	scanf_s("%d", &key);

	int* p = bsearch(&key, x, nx, sizeof(int), (int(*)(const void*, const void*))int_cmpr);

	if (NULL == p) puts("Ž�� ����");
	else printf("%d�� ���� x[%d]�� �־����ϴ�.", key, (int)(p - x));

	free(x);
}