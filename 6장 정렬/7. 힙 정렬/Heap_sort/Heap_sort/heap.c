#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type , x , y) do {type t = x; x = y; y = t;} while(0)

// 배열 a에서 a[left] ~ a[right]의 요소를 힙으로 만드는 함수 
void downheap(int a[], int left, int right)
{
	int root = a[left];
	int child, parent;
	for (parent = left; parent < (right + 1) / 2; parent = child) { // 증감식에서 부모보다 큰 요소를 가지는 child의 인덱스가 parent에 대입됨
		int child_left = parent * 2 + 1;
		int child_right = child_left + 1;
		child = (child_right <= right && a[child_right] > a[child_left]) ? child_right : child_left; // 더 큰 자식을 선택
		if (root >= a[child]) break;
		a[parent] = a[child]; // 부모보다 큰 자식이 부모와 자리를 바꿈
	}
	a[parent] = root;
}

void heapsort(int a[], int n)
{
	int i;
	for (i = (n - 1) / 2; i >= 0; i--) downheap(a, i, n - 1);
	for (i = n - 1; i > 0; i--) {
		swap(int, a[0], a[i]); // 루트에 있는 가장 큰 값을 빼서 배열의 맨뒤의 요소와 바꿈
		downheap(a, 0, i - 1);
	}

}

void main()
{
	int i, nx;
	puts("힙 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));
	srand((unsigned int)time(NULL));

	for (i = 0; i < nx; i++) {
		x[i] = rand() % 15 + 1;
		printf("x[%d] : %d\n", i, x[i]);
	}

	heapsort(x, nx);

	puts("힙 정렬 완료");
	for (i = 0; i < nx; i++) {
		printf("x[%d] : %d\n", i, x[i]);
	}

	free(x);

}