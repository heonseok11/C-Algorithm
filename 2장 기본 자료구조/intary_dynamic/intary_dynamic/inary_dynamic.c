#include <stdio.h>
#include <stdlib.h> // ���������� malloc.h �� include �ϰ� �ִ�. 

void main()
{
	int i, na;
	printf("��� ���� :");
	scanf_s("%d", &na);

	int* p = (int*)calloc(na,sizeof(int));

	if (NULL != p) {
		printf("%d���� ������ �Է��ϼ���\n", na);
		for (i = 0; i < na; i++) {
			printf("a[%d] :", i);
			scanf_s("%d", &p[i]);

		}
		printf("�� ��ڰ��� �Ʒ��� �����ϴ�.\n");
		for (i = 0; i < na; i++) {
			printf("a[%d] = %d\n", i, p[i]);
		}
		free(p);
	}
	else puts("�޸� �Ҵ� ����");
	
}