#include <stdio.h>
#include <malloc.h>

int search(int* x, int n, int key)
{
	int first = 0; // 검색범위 맨 앞의 인덱스
	int last = n - 1; // 검색범위 맨 뒤의 인덱스
	int cen; // 검색 범위 한 가운데의 인덱스
	do {
		cen = (first + last) / 2;
		if (x[cen] == key) return cen; // 검색 성공
		else if (x[cen] < key) first = cen + 1;
		else last = cen - 1;
	} while (first <= last);

	return -1;
}

void main()
{
	int nx, key, idx;
	puts("이진 탐색");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	int* x = (int*)calloc(nx, sizeof(int));

	puts("오름차순으로 입력하세요.");
	printf("x[0] : ");
	scanf_s("%d", &x[0]);
	for (int i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf_s("%d", x + i);
		} while (x[i - 1] > x[i]); // 오름차순으로 작성해야 하므로 이전 항보다 작은 숫자를 입력하면 다시 입력
	}

	printf("검색 값 : ");
	scanf_s("%d", &key);
	idx = search(x, nx, key);

	if (idx == -1) puts("검색 실패");
	else printf("%d는 x[%d]에 있었습니다.\n", key, idx);

	free(x);

}