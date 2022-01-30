#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "IntStack.h"

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
	
	IntStack lstack; // 나눌 첫번째 요소의 인덱스를 저장하는 스택
	IntStack rstack; // 나눌 마지막 요소의 인덱스를 저장하는 스택

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	while (!IsEmpty(&lstack)) {
		int pl = (Pop(&lstack, &left), left); // 왼쪽 커서
		// 콤마 연산자 사용, 사실 왜 쓰는지 모르겠다
		// int pl = Pop(&lstack, &left);
		// pl = left;
		int pr = (Pop(&rstack, &right), right); // 오른쪽 커서
		int pivot = a[(left + right) / 2]; // 가운데 요소를 피벗으로 설정

		if (right - left < 9) insertion(a + left, right - left + 1);
		else {
			do {
				while (a[pl] < pivot) pl++; // 피벗보다 큰 요소를 찾으면 멈춤 
				while (a[pr] > pivot) pr--; // 피벗보다 작은 요소를 찾으면 멈춤

				if (pl <= pr) {
					swap(int, a[pl], a[pr]);
					pl++;
					pr--;
				}
			} while (pl <= pr);

			if (pr - left < right - pl) {
				swap(int, left, pl);
				swap(int, pr, right);
			}

			if (left < pr) {
				Push(&lstack, left);
				Push(&rstack, pr);
			}
			if (pl < right) {
				Push(&lstack, pl);
				Push(&rstack, right);
			}
		}
	}
	Terminate(&lstack);
	Terminate(&rstack);
}

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

	IntStack lstack; // 나눌 첫번째 요소의 인덱스를 저장하는 스택
	IntStack rstack; // 나눌 마지막 요소의 인덱스를 저장하는 스택

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	while (!IsEmpty(&lstack)) {
		int pl = (Pop(&lstack, &left), left); // 왼쪽 커서
		int pr = (Pop(&rstack, &right), right); // 오른쪽 커서
		int pivot = a[med(a[left],a[(left + right)/2],a[right])]; // 가운데 요소를 피벗으로 설정

		if (right - left < 9) insertion(a + left, right - left + 1);
		else {
			do {
				while (a[pl] < pivot) pl++; // 피벗보다 큰 요소를 찾으면 멈춤 
				while (a[pr] > pivot) pr--; // 피벗보다 작은 요소를 찾으면 멈춤

				if (pl <= pr) {
					swap(int, a[pl], a[pr]);
					pl++;
					pr--;
				}
			} while (pl <= pr);

			if (pr - left < right - pl) {
				swap(int, left, pl);
				swap(int, pr, right);
			}

			if (left < pr) {
				Push(&lstack, left);
				Push(&rstack, pr);
			}
			if (pl < right) {
				Push(&lstack, pl);
				Push(&rstack, right);
			}
		}
	}
	Terminate(&lstack);
	Terminate(&rstack);
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

	IntStack lstack; // 나눌 첫번째 요소의 인덱스를 저장하는 스택
	IntStack rstack; // 나눌 마지막 요소의 인덱스를 저장하는 스택

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	while (!IsEmpty(&lstack)) {
		int pl = (Pop(&lstack, &left), left); // 왼쪽 커서
		int pr = (Pop(&rstack, &right), right); // 오른쪽 커서

		if (right - left < 9) insertion(a + left, right - left + 1);
		else {
			int m = sort3elem(a, left, (left + right) / 2, right);
			int pivot = a[m]; // 가운데 요소를 피벗으로 설정
			swap(int, a[m], a[right - 1]);
			pl++;
			pr -= 2;

			do {
				while (a[pl] < pivot) pl++; // 피벗보다 큰 요소를 찾으면 멈춤 
				while (a[pr] > pivot) pr--; // 피벗보다 작은 요소를 찾으면 멈춤

				if (pl <= pr) {
					swap(int, a[pl], a[pr]);
					pl++;
					pr--;
				}
			} while (pl <= pr);

			if (pr - left < right - pl) {
				swap(int, left, pl);
				swap(int, pr, right);
			}

			if (left < pr) {
				Push(&lstack, left);
				Push(&rstack, pr);
			}
			if (pl < right) {
				Push(&lstack, pl);
				Push(&rstack, right);
			}
		}
	}
	Terminate(&lstack);
	Terminate(&rstack);
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
		x[i] = rand() % 20 + 1;
		printf("x[%d] = %d\n", i, x[i]);
	}

	//quick_insertion(x, 0, nx - 1);
	//quick_Q17(x, 0, nx - 1);
	quick_Q18(x, 0, nx - 1);
	
	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);
}

