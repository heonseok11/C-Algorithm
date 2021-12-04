#include <stdio.h>

int sumof(const int a[], int n)
{
	int i, sum = 0;
	for (i = 0; i < n; i++) {
		sum += a[i];
	}

	return sum;
}

double aveof(const int a[], int n)
{
	int i; 
	double sum = 0;

	for (i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum/n;
}


void main()
{
	int i, num;
	printf("�����: "); scanf_s("%d", &num);
	int* height = (int*)calloc(num, sizeof(int));
	printf("%d ����� Ű�� �Է��ϼ���\n", num);
	for (i = 0; i < num; i++) {
		printf("height[%d] = ",i);
		scanf_s("%d", &height[i]);
	}
	//printf("Ű�� �հ�� %d �Դϴ�.", sumof(height, num));
	printf("Ű�� �հ�� %f �Դϴ�.", aveof(height, num));
	free(height);
}