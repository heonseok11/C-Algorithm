#include <stdio.h>
#include <stdlib.h>

void* seqsearch(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*))
{
	char* x = (char*)base; // 1바이트 단위로 쪼개서 size를 곱해 그 만큼 주소를 움직이면서 판단

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
	puts("선형 검색 bsearch 함수로 만들어서 구현");
	printf("요소 수 : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	printf("키 입력 : ");
	scanf_s("%d", &key);

	int* p = seqsearch(&key, x, nx, sizeof(int), (int(*)(const void*, const void*))cmp);
	if (NULL == p) puts("탐색 실패");
	else printf("%d는 x[%d]에 있습니다.", key, (int)(p - x));
	free(x);
}