#include <stdio.h>
#include <stdlib.h>

void main()
{
	int* p = (int*)calloc(1, sizeof(int));
	if (p != NULL) {
		*p = 57;
		printf("*p = %d\n", *p);
		free(p);
	}
	else puts("메모리 할당에 실패했습니다. \n");


}