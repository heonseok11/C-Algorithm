#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int int_cmp(const int* a,const int* b)
{
	return *a < *b ? -1 : *a > *b ? 1 : 0;
}

/*--- x, y�� ����Ű�� n ����Ʈ�� �޸� ������ ��ȯ ---*/
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
	size_t pl = 0;					/* ���� Ŀ�� */
	size_t pr = nmemb - 1;			/* ������ Ŀ�� */
	size_t pv = nmemb;				/* �ǹ� */
	size_t pt = (pl + pr) / 2;		/* �ǹ� ������Ʈ */
	char *a = (char *)base;			/* ù ��° ��ҿ� ���� ������ */
	char *pivot = &a[(pv = pt) * size];					/* �ǹ��� ���� ������ */

	do {
		if (pv != pt) pivot = &a[(pv = pt) * size];
		while (compar(&a[pl * size], pivot) < 0) pl++;
		while (compar(&a[pr * size], pivot) > 0) pr--;
		if (pl <= pr) {
			memswap(&a[pl * size], &a[pr * size], size);
			pl++;
			if (pr == 0) goto QuickRight;	/* ��ȣ�� ���� ���� 0���� 1�� ���Ҹ� ���� ==> �߿� : ������ ���� */
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
	printf("���� ������ qsort�� ���� ����\n");
	printf("��� ���� : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));

	srand((unsigned int)time(NULL));
	for (i = 0; i < nx; i++) {
		x[i] = rand() % 15 + 1;
		printf("x[%d] = %d\n", i, x[i]);
	}

	q_sort(x, nx, sizeof(int), (int(*)(const void*, const void*))int_cmp);

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

}