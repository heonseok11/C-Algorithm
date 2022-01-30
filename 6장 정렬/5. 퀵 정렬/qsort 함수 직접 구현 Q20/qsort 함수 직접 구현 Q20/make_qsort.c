#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int int_cmp(const int* a,const int* b)
{
	return *a < *b ? -1 : *a > *b ? 1 : 0;
}

/*--- x, y가 가리키는 n 바이트의 메모리 영역을 교환 ---*/
static void memswap(void *x, void *y, size_t n)
{
	unsigned char *a = (unsigned char *)x;
	unsigned char *b = (unsigned char *)y;

	for (; n--; a++, b++) {
		unsigned char c = *a;
		*a = *b;
		*b = c;
	}
}

void q_sort(void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*))
{
	size_t pl = 0;					/* 왼쪽 커서 */
	size_t pr = nmemb - 1;			/* 오른쪽 커서 */
	size_t pv = nmemb;				/* 피벗 */
	size_t pt = (pl + pr) / 2;		/* 피벗 업데이트 */
	char *a = (char *)base;			/* 첫 번째 요소에 대한 포인터 */
	char *pivot = &a[(pv = pt) * size];					/* 피벗에 대한 포인터 */

	do {
		if (pv != pt) pivot = &a[(pv = pt) * size];
		while (compar(&a[pl * size], pivot) < 0) pl++;
		while (compar(&a[pr * size], pivot) > 0) pr--;
		if (pl <= pr) {
			memswap(&a[pl * size], &a[pr * size], size);
			pl++;
			if (pr == 0) goto QuickRight;	/* 부호가 없는 정수 0부터 1씩 감소를 피함 ==> 중요 : 없으면 터짐 */
			pr--;
		};
	} while (pl <= pr);

	if (0 < pr) q_sort(&a[0], pr + 1, size, compar);
QuickRight:
	if (pl < nmemb - 1) q_sort(&a[pl * size], nmemb - pl, size, compar);
}

void main()
{

	int i, nx;
	printf("내가 구현한 qsort에 의한 정렬\n");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));

	srand((unsigned int)time(NULL));
	for (i = 0; i < nx; i++) {
		x[i] = rand() % 15 + 1;
		printf("x[%d] = %d\n", i, x[i]);
	}

	q_sort(x, nx, sizeof(int), (int(*)(const void*, const void*))int_cmp);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

}