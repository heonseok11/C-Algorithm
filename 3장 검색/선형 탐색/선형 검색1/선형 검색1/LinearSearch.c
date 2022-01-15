#include <stdio.h>
#include <malloc.h>

int search1(const int p[], int n, int key)
{
	int i = 0;
	while (1) {
		if (i == n) return -1; // 검색실패
		else if (p[i] == key) return i; // 검색성공
		i++;
	}
}

int search2(int* p, int n, int key)
{
	for (int i = 0; i < n; i++) {
		if (p[i] == key) return i;
	}
	return -1;
}

void main()
{
	int nx, key, index;
	puts("선형검색");
	printf("요소개수 : "); scanf_s("%d", &nx);
	int* p = (int*)calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++) {
		printf("p[%d] : ", i);
		scanf_s("%d", &p[i]);
	}

	printf("검색할 값 : "); scanf_s("%d", &key);
	index = search1(p, nx, key);

	if (index == -1) puts("검색 실패");
	else printf("%d는 p[%d]에 있습니다. \n", key, index);
	
	free(p);
	
}