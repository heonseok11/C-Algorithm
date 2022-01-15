#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

void bubble1(int x[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) { // 맨 뒤요소부터 앞으로 가면서 오름차순 정렬
			if (x[j - 1] > x[j]) swap(int, x[j - 1], x[j]);
		}
	}
}

//연습 문제 Q1
void bubble2(int x[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) { // 맨 앞요소부터 뒤로 가면서 오름차순 정렬
			if (x[j] > x[j + 1]) swap(int, x[j], x[j + 1]);
		}
	}
}

//void bubble(int a[], int n)
//{
//	int i, j;
//
//	for (i = n - 1; i > 0; i--) {
//		for (j = 0; j < i; j++)
//			if (a[j] > a[j + 1])
//				swap(int, a[j], a[j + 1]);
//	}
//}
//

//연습 문제 Q2
void bubble3(int x[], int n)
{
	int check = 0;
	int count[2] = { 0, };

	for (int i = 0; i < n - 1; i++) {
		printf("패스%d:\n", i + 1);
		for (int j = n - 1; j > i; j--) { // 맨 뒤요소부터 앞으로 가면서 오름차순 정렬
			check = 0;
			count[0]++; // 비교횟수
			if (x[j - 1] > x[j]) {
				count[1]++; // 교환횟수
				check = 1;
			}
			
			for (int k = 0; k < n; k++) {
				printf("%2d", x[k]);
				if (k == j - 1 && check) printf(" + ");
				else if (k == j - 1 && !check) printf(" - ");
				else printf("   ");
			}
//			for (k = 0; k < n - 1; k++)
//				printf("%3d %c", a[m], (m != j - 1) ? ' ' : (a[j - 1] > a[j]) ? '+' : '-');
// 
//			printf("%3d\n", a[n - 1]);


			if (check) swap(int, x[j - 1], x[j]);
			printf("\n");
		}
		for (int k = 0; k < n; k++) {
			printf("%2d   ", x[k]);
		}
		printf("\n");
	}
	printf("비교를 %d회 했습니다.\n", count[0]);
	printf("교환을 %d회 했습니다.\n", count[1]);
}

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

	bubble3(x, nx);

	puts("오름차순으로 정리했습니다.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);
}