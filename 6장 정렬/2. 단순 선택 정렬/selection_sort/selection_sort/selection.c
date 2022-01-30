#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

void selection(int a[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min]) min = j;
		}
		swap(int, a[i], a[min]);
	}
}


void selection2(int a[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min]) min = j;
		}

		for (int k = 0; k < n; k++) {
			printf("%2c ", (i == k) ? '*' : (k == min ? '+' : ' '));
//			printf((k == i) ? "  * " : (k == min) ? "  + " : "    ");
		}
		putchar('\n');
		for (int k = 0; k < n; k++) {
			printf("%2d ", a[k]);
		}
		swap(int, a[i], a[min]);
		putchar('\n');
	}
	putchar('\n');
	for (int k = 0; k < n; k++) {
		printf("%2d ", a[k]);
	}
	putchar('\n');
}

void main()
{
	int i, nx;

	puts("��������");
	printf("��� ���� : "); scanf_s("%d", &nx);
	int* x = (int*)calloc(nx, sizeof(int));

	srand((unsigned int)time(NULL));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		x[i] = rand() % 20 + 1;
		printf("%d\n", x[i]);
	}

	selection2(x, nx);

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);
}