#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "IntStack.h"

#define swap(type, x, y) do {type t = x;x = y; y = t;} while(0)

void quick(int a[], int left, int right)
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

		do {
			while (a[pl] < pivot) pl++; // 피벗보다 큰 요소를 찾으면 멈춤 
			while (a[pr] > pivot) pr--; // 피벗보다 작은 요소를 찾으면 멈춤

			if (pl <= pr) {
				swap(int, a[pl], a[pr]);
				pl++;
				pr--;
			}
		} while (pl <= pr);

		if (left < pr) {
			Push(&lstack, left);
			Push(&rstack, pr);
		}
		if (pl < right) {
			Push(&lstack, pl);
			Push(&rstack, right);
		}
	}
	Terminate(&lstack);
	Terminate(&rstack);
}

//연습문제 Q14
void quick_Print(int a[], int left, int right)
{
	IntStack lstack; // 나눌 첫번째 요소의 인덱스를 저장하는 스택
	IntStack rstack; // 나눌 마지막 요소의 인덱스를 저장하는 스택

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	printf("\na[%d] ~ a[%d]를 스택에 푸시합니다.\n", left, right);
	printf("Lstack:");   Print(&lstack);
	printf("Rstack:");   Print(&rstack);

	while (!IsEmpty(&lstack)) {
		int pl = (Pop(&lstack, &left), left); // 왼쪽 커서
		// 콤마 연산자 사용, 사실 왜 쓰는지 모르겠다
		// int pl = Pop(&lstack, &left);
		// pl = left;
		int pr = (Pop(&rstack, &right), right); // 오른쪽 커서
		int pivot = a[(left + right) / 2]; // 가운데 요소를 피벗으로 설정

		printf("====================================================\n");
		printf("스택에서 꺼낸 배열의 범위는 a[%d] ~ a[%d]입니다.\n", left, right);
		printf("====================================================\n");

		do {
			while (a[pl] < pivot) pl++; // 피벗보다 큰 요소를 찾으면 멈춤 
			while (a[pr] > pivot) pr--; // 피벗보다 작은 요소를 찾으면 멈춤

			if (pl <= pr) {
				swap(int, a[pl], a[pr]);
				pl++;
				pr--;
			}
		} while (pl <= pr);

		if (left < pr) {
			Push(&lstack, left);
			Push(&rstack, pr);

			printf("\na[%d] ~ a[%d]를 스택에 푸시합니다.\n", left, pr);
			printf("Lstack:\n");   Print(&lstack);
			printf("Rstack:\n");   Print(&rstack);
		}
		if (pl < right) {
			Push(&lstack, pl);
			Push(&rstack, right);

			printf("\na[%d] ~ a[%d]를 스택에 푸시합니다.\n", pl, right);
			printf("Lstack:\n");   Print(&lstack);
			printf("Rstack:\n");   Print(&rstack);
		}
	}
	Terminate(&lstack);
	Terminate(&rstack);
}

//연습문제 Q15 : 요소의 개수가 적은 그룹을 먼저 나누는 함수
void quick_Q15(int a[], int left, int right)
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

	//quick(x, 0, nx - 1);
	//quick_Print(x, 0, nx - 1);
	quick_Q15(x, 0, nx - 1);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);
}

