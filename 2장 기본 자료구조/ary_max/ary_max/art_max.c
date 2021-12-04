#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maxof(int num, const int p[]) // int *p
{
	int max = p[0];
	for (int i = 0; i < num; i++) {
		if (p[i] > max) max = p[i];
	}

	return max;
}

void main()
{
	int i, num;
	printf("��� �� : "); scanf_s("%d", &num);
	int* height = (int*)calloc(num, sizeof(int)); 
	printf("%d���� Ű�� �Է��ϼ���\n",num);
	srand(time(NULL));
	for (i = 0; i < num; i++) {
		height[i] = 100 + rand() % 90; // 100 ~ 189������ ��������
		printf("height[%d] = %d\n",i ,height[i]); 
	}

	printf("���� ū ����� Ű�� %d �Դϴ�.", maxof(num, height));
	free(height);
}