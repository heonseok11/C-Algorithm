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
	else puts("�޸� �Ҵ翡 �����߽��ϴ�. \n");


}