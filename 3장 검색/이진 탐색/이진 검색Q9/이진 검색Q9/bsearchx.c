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

// 오름차순 정렬된 정수를 비교하는 함수
int int_cmp(const int* key, const int* b)
{
	if (*key < *b) return -1;
	else if (*key > *b) return 1;
	else return 0; // 같으면 0 반환
}

void main()
{
	int nx, key;
	int* p; // 이진 탐색후 key 값과 일치하는 요소에 대한 포인터
	puts("bsearch 함수를 이용하여 검색");
	printf("요소 개수 : "); scanf_s("%d", &nx);
	int* x = (int*)calloc(nx, sizeof(int));

	printf("오름차순으로 숫자 입력\n");
	printf("x[0] : "); scanf_s("%d", &x[0]);
	for (int i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}
	printf("검색값 : ");
	scanf_s("%d", &key);

	p = searchx(&key, // 검색값에 대한 포인터
		x,    // 배열
		nx,   // 요소의 개수
		sizeof(int), // 요소의 크기
		(int(*)(const void*, const void*))int_cmp // 비교함수
		//compare 함수의 리턴값이 양수일 경우 오른쪽, 음수일 경우 왼쪽을 탐색

	);

	if (p == NULL) puts("검색에 실패함");
	else printf("%d는 x[%d]에 있습니다.", key, (int)(p - x));
	free(x);
}