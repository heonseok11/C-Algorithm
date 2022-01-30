#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do {type t = x;x = y; y = t;} while(0)

void quick(int a[], int left, int right)
{
	int i;
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

	if (left < pr) quick(a, left, pr);
	if (pl < right) quick(a, pl, right);
} 

void show_quick(int a[], int left, int right)
{
	int i;
	int pl = left; // 왼쪽 커서
	int pr = right; // 오른쪽 커서 
	int pivot = a[(pl + pr) / 2]; // 가운데 요소를 피벗으로 설정

	printf("a[%d] ~ a[%d] : {", left, right);
	for (i = left; i < right; i++) printf("%d, ", a[i]);
	printf("%d}\n", a[right]);

	do {
		while (a[pl] < pivot) pl++; // 피벗보다 큰 요소를 찾으면 멈춤 
		while (a[pr] > pivot) pr--; // 피벗보다 작은 요소를 찾으면 멈춤

		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	if (left < pr) show_quick(a, left, pr);
	if (pl < right) show_quick(a, pl, right);
}

//연습문제 Q13 : 포인터를 사용해서 구현해봄
void quick_sort(int a[], int n)
{
	int i;
	int* pl = a;
	int* pr = a + n - 1;
	int pivot = a[n/2];

	do {
		while (*pl < pivot) pl++; // 피벗보다 큰 요소를 찾으면 멈춤 
		while (*pr > pivot) pr--; // 피벗보다 작은 요소를 찾으면 멈춤
		
		if (pl <= pr) {
			swap(int, *pl, *pr);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	
	if (a < pr) quick_sort(a, (pr - a) + 1); 
	if (pl < a + n - 1) quick_sort(pl, (a + n - 1 - pl) + 1);
}
//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=tipsware&logNo=221192754086
//포인터간의 뺄셈은 두 주소 사이에 대상이 몇 개 있는지를 계산하는 것이기 때문에 일반 산술 연산과 다르다. 

//void quick_sort(int a[], int n)
//{
//	quick(a, 0, n - 1);
//}

//연습문제 Q15 : 요소의 개수가 적은 그룹을 먼저 나누는 함수
void quick_Q15(int a[], int left, int right)
{
	int i;
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

	if (pr - left > right - pl) {
		if (left < pr) quick(a, left, pr);
		if (pl < right) quick(a, pl, right);
	}
	else {
		if (pl < right) quick(a, pl, right);
		if (left < pr) quick(a, left, pr);
	}

//	if (pr - left < right - pl) {
//		swap(int, pl, left);
//		swap(int, pr, right);
//	}
//	if (left < pr)  quick(a, left, pr);
//	if (pl < right) quick(a, pl, right);

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

	//show_quick(x, 0, nx - 1);
	//quick_sort(x, nx);
	quick_Q15(x, 0, nx - 1);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);
}

