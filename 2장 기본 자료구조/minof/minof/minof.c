#include <stdio.h>

int minof(const int a[], int n)
{
	int min = a[0];
	for (int i = 1; i < n; i++) {
		if (min > a[i]) min = a[i];
	}

	return min;
}



void main()
{
	int i, num;

	printf("��� �� : ");
	scanf_s("%d", &num);
	int* height = (int*)calloc(num, sizeof(int));
	printf("%d ����� Ű�� �Է��ϼ���.\n",num);
	for (i = 0; i < num; i++) {
		printf("height[%d] : ", i);
		scanf_s("%d", &height[i]);
	}
	printf("�ּڰ��� %d �Դϴ�.\n", minof(height, num));

	free(height);
}