#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

void bubble1(int x[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		int exchg = 0;
		for (int j = n - 1; j > i; j--) { // 맨 뒤요소부터 앞으로 가면서 오름차순 정렬
			if (x[j - 1] > x[j]) {
				swap(int, x[j - 1], x[j]);
				exchg++;
			}
		}
		if (exchg == 0) break; // 교환이 수행되지 않았다면 정렬이 완료된 것이므로 종료
	}
}


//연습 문제 Q4
void bubble2(int x[], int n)
{
	int check = 0;
	int count[2] = { 0, };

	for (int i = 0; i < n - 1; i++) {
		int exchg = 0;

		printf("패스%d:\n", i + 1);
		for (int j = n - 1; j > i; j--) { // 맨 뒤요소부터 앞으로 가면서 오름차순 정렬
			check = 0;
			count[0]++; // 비교횟수
			if (x[j - 1] > x[j]) {
				count[1]++; // 교환횟수
				check = 1;
				exchg++;
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
		if (exchg == 0) break;
	}
	printf("비교를 %d회 했습니다.\n", count[0]);
	printf("교환을 %d회 했습니다.\n", count[1]);
}

//연습 문제 Q3
int is_sorted(const int x[], int n)
{
	for (int i = n - 1 ; i > 0; i--) {
		if (x[i - 1] > x[i]) return 0;
	}
	return 1;
}

void main()
{
	int i, nx, sorted;

	puts("버블정렬");
	printf("요소 개수 : "); scanf_s("%d", &nx);
	int* x = (int*)calloc(nx, sizeof(int));

	srand((unsigned int)time(NULL));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		x[i] = rand() % 20 + 1;
		printf("%d\n", x[i]);
	}

	bubble2(x, nx);
	sorted = is_sorted(x, nx);


	printf("오름차순으로 정리했습니다. 상태 : %d\n", sorted);
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);
}