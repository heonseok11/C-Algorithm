#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void binary_insertion(int a[], int n)
{
	int i, j;
	
	for (i = 1; i < n; i++) {
		int tmp = a[i];
		int first = 0;
		int last = i - 1;

		if (a[i - 1] > tmp) { // tmp가 a[i-1]보다 크다면 정렬을 진행할 필요 X
			do {
				int mid = (first + last) / 2;

				if (a[mid] == tmp) {
					first = mid;
					break;
				}
				else if (tmp < a[mid]) last = mid - 1;
				else if (tmp > a[mid]) first = mid + 1;
			} while (first <= last);
			// 반복문을 빠져나오면 first 가 tmp 가 들어갈 자리가 됨

			for (j = i; j > first; j--) { 
				a[j] = a[j - 1];
			}
			a[first] = tmp;
		}
	}
}

//void bin_insertion(int a[], int n)
//{
//	int i, j;
//
//	for (i = 1; i < n; i++) {
//		int key = a[i];
//		int pl = 0;		/* 검색 범위의 첫 인덱스 */
//		int pr = i - 1;	/* 검색 범위의 끝 인덱스 */
//		int pc;			/* 검색 범위의 가운데 인덱스 */
//		int pd;			/* 삽입하는 위치의 인덱스 */
//
//		do {
//			pc = (pl + pr) / 2;
//			if (a[pc] == key)		/* 검색 성공 */
//				break;
//			else if (a[pc] < key)
//				pl = pc + 1;
//			else
//				pr = pc - 1;
//		} while (pl <= pr);
//		pd = (pl <= pr) ? pc + 1 : pr + 1;
//
//		for (j = i; j > pd; j--)
//			a[j] = a[j - 1];
//		a[pd] = key;
//	}
//}
//


//연습 문제 Q11
void binary_insertion2(int a[], int n)
{
	int i, j;

	for (i = 1; i < n; i++) {
		int tmp = a[i];
		int first = 0;
		int last = i - 1;

		if (a[i - 1] > tmp) { // tmp가 a[i-1]보다 크다면 정렬을 진행할 필요 X
			do {
				int mid = (first + last) / 2;

				if (a[mid] == tmp) {
					first = mid;
					break;
				}
				else if (tmp < a[mid]) last = mid - 1;
				else if (tmp > a[mid]) first = mid + 1;
			} while (first <= last);
			// 반복문을 빠져나오면 first 가 tmp 가 들어갈 자리가 됨

			memmove(&a[first + 1], &a[first], sizeof(int)*(i - first));
			//		memmove(&a[pd + 1], &a[pd], (i - pd) * sizeof(int));
			//		a[pd] = key;
			// 답지 예시 이용시
			
			a[first] = tmp;
		}
	}

}

void main()
{
	int nx, i;
	puts("단순 삽입 정렬");

	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	int* x = (int*)calloc(nx, sizeof(int));

	srand((unsigned int)time(NULL));

	for (i = 0; i < nx; i++) {
		x[i] = rand() % 15 + 1;
		printf("x[%d] = %d\n", i, x[i]);
	}

	binary_insertion2(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);


}