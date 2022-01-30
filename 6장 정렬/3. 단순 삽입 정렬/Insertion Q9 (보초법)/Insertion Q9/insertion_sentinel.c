#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion(int a[], int n)
{
	int i, j;
	for (i = 1; i < n; i++) {
		int tmp = a[0] = a[i]; // 현재 값을 보초값으로 설정
		for (j = i; a[j - 1] > tmp; j--) { // 애초에 tmp 값을 가지고 비교를 하기 때문에 a[0] == tmp 라서 j가 0 아래로 내려갈 일이 없다. 
			a[j] = a[j - 1];
		}
		a[j] = tmp;
	}
}



void main()
{
	int nx, i;
	puts("단순 삽입 정렬");

	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	int* x = (int*)calloc(nx + 1, sizeof(int)); // a[0] 보초를 위해 하나 더 자리를 생성

	srand((unsigned int)time(NULL));

	for (i = 1; i < nx + 1; i++) {
		x[i] = rand() % 15 + 1;
		printf("x[%d] = %d\n", i, x[i]);
	}

	insertion(x, nx + 1);

	puts("오름차순으로 정렬했습니다.");
	for (i = 1; i < nx + 1; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);


}