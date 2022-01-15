#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

void bubble(int x[], int n)
{
	int first = 0, last = n - 1;
	int compar_f = 0, compar_l = n - 1;
	int cnt = 0;

	do {
		cnt = 0;
		for (int i = last; i > first; i--) {
			if (x[i - 1] > x[i]) {
				swap(int, x[i - 1], x[i]);
				compar_f = i;
				cnt++;
			}
		}
		first = compar_f;

		for (int i = first; i < last; i++) {
			if (x[i] > x[i + 1]) {
				swap(int, x[i], x[i + 1]);
				compar_l = i;
				cnt++;
			}
		}
		last = compar_l;
	} while (cnt);
}

///*--- 양방향 버블 정렬(셰이커 정렬) ---*/
//void shaker(int a[], int n)
//{
//	int left = 0;
//	int right = n - 1;
//	int last = right;
//
//	while (left < right) {
//		int j;
//		for (j = right; j > left; j--) {
//			if (a[j - 1] > a[j]) {
//				swap(int, a[j - 1], a[j]);
//				last = j;
//			}
//		}
//		left = last;
//
//		for (j = left; j < right; j++) {
//			if (a[j] > a[j + 1]) {
//				swap(int, a[j], a[j + 1]);
//				last = j;
//			}
//		}
//		right = last;
//	}
//}
//

void main()
{
	int i, nx;

	puts("버블정렬");
	printf("요소 개수 : "); scanf_s("%d", &nx);
	int* x = (int*)calloc(nx, sizeof(int));

	srand((unsigned int)time(NULL));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		x[i] = rand() % 20 + 1;
		printf("%d\n", x[i]);
	}

	bubble(x, nx);

	printf("오름차순으로 정리했습니다.\n");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);
}