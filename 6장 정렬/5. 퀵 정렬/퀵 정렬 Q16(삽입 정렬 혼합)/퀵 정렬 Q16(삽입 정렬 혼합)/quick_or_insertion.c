#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do {type t = x;x = y; y = t;} while(0)

void insertion(int a[], int n)
{
	int i, j;

	for (i = 1; i < n; i++) {
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--) {
			a[j] = a[j - 1];
		}
		a[j] = tmp;
	}
}

void quick_insertion(int a[], int left, int right)
{
	if (right - left < 9) {
		insertion(a + left, right - left + 1);
		return;
	}

	int pl = left; // 왼쪽 커서
	int pr = right; // 오른쪽 커서 
	int pivot = a[(pl + pr) / 2]; // 가운데 요소를 피벗으로 설정

	do {
		while (a[pl] < pivot) pl++; // 피벗보다 큰 요소를 찾으면 멈춤 
		while (a[pr] > pivot) pr--; // 피벗보다 작은 요소를 찾으면 멈춤

		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	if (left < pr && pr - left > 8) quick_insertion(a, left, pr);
	else insertion(a, pr - left + 1);

	if (pl < right && right - pl > 8) quick_insertion(a, pl, right);
	else insertion(a + pl, right - pl + 1);
}

//void quick(int a[], int left, int right)
//{
//	if (right - left < 9)
//		insertion(&a[left], right - left + 1);
//	else {
//		int pl = left;				
//		int pr = right;				
//		int x = a[(pl + pr) / 2];	
//
//		do {
//			while (a[pl] < x) pl++;
//			while (a[pr] > x) pr--;
//			if (pl <= pr) {
//				swap(int, a[pl], a[pr]);
//				pl++;
//				pr--;
//			}
//		} while (pl <= pr);
//
//		if (pr - left < right - pl) {
//			swap(int, pl, left);
//			swap(int, pr, right);
//		}
//		if (left < pr)  quick(a, left, pr);
//		if (pl < right) quick(a, pl, right);
//	}
//}

//연습문제 Q17 : 임의로 선택한 3요소의 중앙값으로 피벗으로 하는 함수
int med(int a, int b, int c)
{
	if (a >= b) {
		if (b >= c) return b; // a >= b >= c
		else if (c >= a)return a; // c >= a >= b
		else return c; // a > c >= b
	}
	// a < b
	else if (a > c) return a;
	else if (b > c) return c; // a <= c < b
	else return b;
}

void quick_Q17(int a[], int left, int right)
{
	if (right - left < 9)
		insertion(&a[left], right - left + 1);
	else {
		int pl = left;				
		int pr = right;				
		int x = a[med(a[left],a[(left + right)/2],a[right])];	

		do {
		    while (a[pl] < x) pl++;
			while (a[pr] > x) pr--;
			if (pl <= pr) {
				swap(int, a[pl], a[pr]);
				pl++;
				pr--;
			}
	    } while (pl <= pr);

		if (pr - left < right - pl) {
			swap(int, pl, left);
			swap(int, pr, right);
		}
		if (left < pr) quick_Q17(a, left, pr);
	    if (pl < right) quick_Q17(a, pl, right);
	}
}

//연습문제 Q18
int sort3elem(int x[], int a, int b, int c)
{
	if (x[b] < x[a]) swap(int, x[b], x[a]);
	if (x[c] < x[b]) swap(int, x[c], x[b]);
	if (x[b] < x[a]) swap(int, x[b], x[a]);
	return b;
}

void quick_Q18(int a[], int left, int right)
{
	if (right - left < 9)
		insertion(&a[left], right - left + 1);
	else {
		int pl = left;
		int pr = right;
		int m = sort3elem(a, left, (left + right) / 2, right);
		int x = a[m];
		swap(int, a[m], a[right - 1]);
		pl++;
		pr -= 2;

		do {
			while (a[pl] < x) pl++;
			while (a[pr] > x) pr--;
			if (pl <= pr) {
				swap(int, a[pl], a[pr]);
				pl++;
				pr--;
			}
		} while (pl <= pr);

		if (pr - left < right - pl) {
			swap(int, pl, left);
			swap(int, pr, right);
		}
		if (left < pr) quick_Q18(a, left, pr);
		if (pl < right) quick_Q18(a, pl, right);
	}
}

void main()
{
	int i, nx;

	puts("배열을 나눕니다.");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));
	srand((unsigned int)time(NULL));

	for (i = 0; i < nx; i++) {
		x[i] = rand() % 30 + 1;
		printf("x[%d] = %d\n", i, x[i]);
	}

	quick_insertion(x, 0, nx - 1);
	//quick_Q17(x, 0, nx - 1);
	//quick_Q18(x, 0, nx - 1);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);
}

