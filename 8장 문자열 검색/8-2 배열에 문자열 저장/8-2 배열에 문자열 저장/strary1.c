#include <stdio.h>

void main()
{
	char st[10];
	st[0] = 'A';
	st[1] = 'B';
	st[2] = 'C';
	st[3] = 'D';
	st[4] = '\0'; // ��������� ���ڿ��� �ν�
	st[5] = 'E';
	printf("���ڿ� st���� \"%s\"�� ��� �ֽ��ϴ�.\n", st);
}