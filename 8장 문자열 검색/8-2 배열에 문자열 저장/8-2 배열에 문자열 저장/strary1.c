#include <stdio.h>

void main()
{
	char st[10];
	st[0] = 'A';
	st[1] = 'B';
	st[2] = 'C';
	st[3] = 'D';
	st[4] = '\0'; // 여기까지만 문자열로 인식
	st[5] = 'E';
	printf("문자열 st에는 \"%s\"가 들어 있습니다.\n", st);
}