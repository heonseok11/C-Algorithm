#include <stdio.h>

void swap_str(char* x, char* y)
{
	char* tmp;
	while (*x && *y) {
		char t = *x;
		*x++ = *y;
		*y++ = t;
	}
	if (*x) { // x가 y보다 길 경우
		tmp = x;
		while (*x) { *y++ = *x++; } // x의 나머지를 y로 복사
		*tmp = *y = '\0';
	}
	else if (*y) {
		tmp = y;
		while (*y) { *x++ = *y++; } // y의 나머지를 x로 복사
		*tmp = *x = '\0';
	}
	else {
		*x = *y = '\0';
	}
}

void main()
{
	char s1[128];
	char s2[128];

	printf("s1 : "); scanf_s("%s", s1, 128);
	printf("s2 : "); scanf_s("%s", s2, 128);

	swap_str(s1, s2);

	printf("s1 : %s\n", s1);
	printf("s2 : %s\n", s2);
}