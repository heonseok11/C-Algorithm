#include <stdio.h>

int med(int a, int b, int c)
{
	if (a >= b) {
		if (b >= c) return b;
		// �Ʒ��� b�� c���� ���� ��� c > b
		else if (c >= a) return a;
		else return c; // a>c>b


	}
	// b�� a���� ŭ
	else if (a > c) return a;
	else if (b > c) return c; // c�� a���� ũ�ų� ������ b���� ���� ���
	else return b; // c�� b���ٵ� Ŀ�� b�� �߰��� 


}

void main()
{
	int a, b, c;

	printf("�� ������ �߾Ӱ��� ���մϴ�.\n");
	
	printf("a�� ��: "); scanf_s("%d", &a);
	printf("b�� ��: "); scanf_s("%d", &b);
	printf("c�� ��: "); scanf_s("%d", &c);

	printf("�߾Ӱ��� %d�Դϴ�.\n",med(a,b,c));

}