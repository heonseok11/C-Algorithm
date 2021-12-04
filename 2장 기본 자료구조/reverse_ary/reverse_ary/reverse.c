#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Swap(type, x, y) do{type t = x; x = y; y = t;} while(0)
// 세미콜론 문제때문에 do while 문을 사용해야 한다. 치환시 if(ture) {}; 가되면 if문일 경우 if문이 끊겨버리고 else문으로 넘어가지 않기 때문이다. 

void reverse(int a[], int n)
{
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n; j++) printf("%d ", a[j]);
		printf("\na[%d]와 a[%d]를 교환합니다.\n",i,n-i-1);
		Swap(int, a[i], a[n - i - 1]);
	}
}

void main()
{
	int i, n;

	printf("요소 개수 : "); scanf_s("%d", &n);
	int* p = (int*)calloc(n, sizeof(int));
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		p[i] = rand() % 9 + 1; 
		printf("p[%d] = %d\n", i, *(p + i));
	}
	
	reverse(p, n);
	for (i = 0; i < n; i++) {
		printf("%d ", p[i]);
	}
	printf("\n역순 정렬 완료\n");
	free(p);

}