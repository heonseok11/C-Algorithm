#include <stdio.h>

int Min(int a, int b, int c, int d)
{
	int min = a;
	if (b < min) min = b;
	if (c < min) min = c;
	if (d < min) min = d;
	return min;
}


void main()
{
	int a, b, c, d;
	

	printf("���� �Է��ϸ� �ּڰ��� ã���ϴ�. \n");
	printf("a�� ��: "); scanf_s("%d", &a);
	printf("b�� ��: "); scanf_s("%d", &b);
	printf("c�� ��: "); scanf_s("%d", &c);
	printf("d�� ��: "); scanf_s("%d", &d);

	int min = Min(a, b, c, d);

	printf("�ּڰ��� %d �Դϴ�.\n",min); //	printf("�ּڰ��� %d�Դϴ�.\n", min4(a, b, c, d));


}