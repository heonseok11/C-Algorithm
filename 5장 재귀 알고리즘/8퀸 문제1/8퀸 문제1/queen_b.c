#include <stdio.h>

int pos[8]; // 각 열에서 퀸의 위치 

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
		if (i == 7) Print(); // 모든 열에 배치 완료
		else set(i + 1);
	}
}

void main()
{
	set(0);
}