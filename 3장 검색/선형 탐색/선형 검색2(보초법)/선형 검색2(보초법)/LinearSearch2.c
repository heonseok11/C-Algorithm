#include <stdio.h>
#include <malloc.h>

int search(int* p, int n, int key)
{
	int i = 0;
	p[n] = key; // 보초를 key 값으로 설정
	while (1) {
		if (p[i] == key) break;
		i++;
	}
	return i == n ? -1 : i;

}

int search2(int* p, int n, int key)
{
	int i = 0;
	p[n] = key; // 보초를 key 값으로 설정
	for (i = 0; i < n; i++) {
		if (p[i] == key) break;
	}

	return i == n ? -1 : i;

}

void main()
{
	int nx, key, index;
	puts("선형 검색(보초법)");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	int* p = (int*)calloc(nx + 1, sizeof(int)); // 보초를 위해 맨 마지막 공간을 추가 생성

	for (int i = 0; i < nx; i++) {
		printf("p[%d] = ", i);
		scanf_s("%d", p + i);
	}
	printf("검색 값 : ");
	scanf_s("%d", &key);
	index = search2(p, nx, key);
	if (index == -1) puts("검색 실패");
	else printf("%d는 p[%d]에 있습니다.\n", key, index);

	free(p);
}