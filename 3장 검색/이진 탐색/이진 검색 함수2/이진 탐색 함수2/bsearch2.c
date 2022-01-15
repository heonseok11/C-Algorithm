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
	puts("bsearch 함수 사용하여 검색");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	int* x = (int*)calloc(nx, sizeof(int));
	printf("내림차순으로 입력하세요\n");
	printf("x[0] : ");
	scanf_s("%d", &x[0]);
	for (int i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] > x[i - 1]);
		
	}
	printf("키값 : ");
	scanf_s("%d", &key);

	int* p = bsearch(&key, x, nx, sizeof(int), (int(*)(const void*, const void*))int_cmpr);

	if (NULL == p) puts("탐색 실패");
	else printf("%d의 값은 x[%d]에 있었습니다.", key, (int)(p - x));

	free(x);
}