#include <stdio.h>

#define N 10

void main()
{
	int i, retry, count = 0;
	int a[N];
	puts("���� �Է�");
	do{
		printf("%d��° ���� : ", count + 1);
		scanf_s("%d", &a[count++ % N]); // 10���� ������ ó������ �����ͺ��� ���
		printf("����Ϸ��� 1, �ƴϸ� 0�� �����ּ��� : ");
		scanf_s("%d", &retry);
	} while (retry);
	i = count - N;
	if (i < 0) i = 0;
	for (i; i < count; i++)
		printf("%2d��° ���� = %d\n", i + 1, a[i % N]);

}