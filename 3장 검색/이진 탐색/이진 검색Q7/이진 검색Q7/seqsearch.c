#include <stdio.h>
#include <stdlib.h>

void* seqsearch(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*))
{
	char* x = (char*)base; // 1����Ʈ ������ �ɰ��� size�� ���� �� ��ŭ �ּҸ� �����̸鼭 �Ǵ�

	for (size_t i = 0; i < nmemb; i++) {
		if (!compar((const void*)&x[i * size], key)) return (&x[i * size]);
	}

	return NULL;
}

int cmp(const int* a, const int* b)
{
	if (*a > *b) return 1;
	else if (*a < *b) return -1;
	else return 0;
}

void main()
{
	int nx, key;
	puts("���� �˻� bsearch �Լ��� ���� ����");
	printf("��� �� : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	printf("Ű �Է� : ");
	scanf_s("%d", &key);

	int* p = seqsearch(&key, x, nx, sizeof(int), (int(*)(const void*, const void*))cmp);
	if (NULL == p) puts("Ž�� ����");
	else printf("%d�� x[%d]�� �ֽ��ϴ�.", key, (int)(p - x));
	free(x);
}