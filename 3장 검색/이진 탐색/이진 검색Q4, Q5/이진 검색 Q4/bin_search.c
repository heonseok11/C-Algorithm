#include <stdio.h>
#include <malloc.h>

int search(int* p, int n, int key)
{
	int i, j;
	int cen;
	int first = 0;
	int last = n - 1;


	printf("   |");
	for (i = 0; i < n; i++) {
		printf("%4d", i);
	}
	printf("\n---+");
	for (i = 0; i < n; i++) {
		printf("----");
	}
	printf("\n");

	do {
		cen = (first + last) / 2;
		printf("   |");

		printf("%*s", 4 * first, "");
		printf(" <-");
		printf("%*s", 4 * (cen - first), "");
		printf("+");
		printf("%*s", 4 * (last - cen) - 2, "");
		printf("->");

		printf("\n  %d|", cen);
		for (j = 0; j < n; j++) {
			printf("%4d", p[j]);
		}
		printf("\n   |\n");

		
		if (p[cen] == key) return cen;
		else if (p[cen] < key) first = cen + 1;
		else last = cen - 1;


	} while (first <= last);

	return -1;

}

int bin_search2(const int a[], int n, int key) {
	int i;
	int cen;
	int first = 0;
	int last = n - 1;

	do {
		cen = (first + last) / 2;
		if (a[cen] == key) {
			while (cen > first && a[cen - 1] == key) cen--;
			return cen;
		}
		else if (a[cen] < key) first = cen + 1;
		else last = cen - 1;

	} while (first <= last);

	return - 1;
	/*
	int num;
	if (first > last) return -1;
	for (i = cen; i >= 0; i--) {
		if (a[i] == key) num = i;
	}
	return num;

	���� �°� ���������� '���� �ȿ���'��� ����Ž���� Ư���� ����ϸ� ���� �ʴ�. 
	*/
	

}

void main()
{
	int i, nx, key, index;

	puts("���� Ž��");
	printf("��� ���� : ");
	scanf_s("%d", &nx);

	int* p = (int*)calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) {
		do {
			printf("p[%d] : ", i);
			scanf_s("%d", p + i);
		} while (p[i] < p[i - 1]);
	}

	printf("Ű �Է� : ");
	scanf_s("%d", &key);
	index = bin_search2(p, nx, key);

	if (index == -1) puts("Ž�� ����");
	else printf("%d�� p[%d]�� �־����ϴ�.", key, index);

	free(p);

}