#include <stdio.h>
#include <stdlib.h> // 내부적으로 malloc.h 를 include 하고 있다. 

void main()
{
	int i, na;
	printf("요소 개수 :");
	scanf_s("%d", &na);

	int* p = (int*)calloc(na,sizeof(int));

	if (NULL != p) {
		printf("%d개의 정수를 입력하세요\n", na);
		for (i = 0; i < na; i++) {
			printf("a[%d] :", i);
			scanf_s("%d", &p[i]);

		}
		printf("각 요솟값은 아래와 같습니다.\n");
		for (i = 0; i < na; i++) {
			printf("a[%d] = %d\n", i, p[i]);
		}
		free(p);
	}
	else puts("메모리 할당 실패");
	
}