#include <stdio.h>

int pos[8]; // �� ������ ���� ��ġ 

void Print()
{
	int i;
	for (i = 0; i < 8; i++) {
		printf("%2d", pos[i]);
	}
	putchar('\n');
}

set(int i)
{
	int j;
	for (j = 0; j < 8; j++) {
		pos[i] = j;
		if (i == 7) Print(); // ��� ���� ��ġ �Ϸ�
		else set(i + 1);
	}
}

void main()
{
	set(0);
}