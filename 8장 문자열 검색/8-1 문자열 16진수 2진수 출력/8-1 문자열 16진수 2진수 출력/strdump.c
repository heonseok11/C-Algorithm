#include <stdio.h>
#include <limits.h> // 정수형의 유효범위


// 문자열 안의 문자를 16진수와 2진수로 출력하는 함수
void str_dump(const char* s)
{
	do {
		printf("%c %0*X ", *s, (CHAR_BIT + 3) / 4, *s);
		for (int i = CHAR_BIT - 1; i >= 0; i--)
			putchar(((*s >> i) & 1U) ? '1' : '0');
		putchar('\n');
	} while (*s++ != '\0');
}

void main()
{
	str_dump("STRING");
}