#include <stdio.h>

void main()
{
	int num, n = 0;

	printf("���ڸ� �Է��ϼ��� : ");
	scanf_s("%d", &num);
	
	while(num > 0) {
		num /= 10;
		n++;
	}


	printf("�� ���� %d �ڸ��Դϴ�.", n);
}