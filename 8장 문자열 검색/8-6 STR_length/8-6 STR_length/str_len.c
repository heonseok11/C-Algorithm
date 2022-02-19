#include <stdio.h>

int str_len(const char *str)
{
	int len = 0;
	while (str[len]) len++; // 널문자의 인덱스는 문자열의 길이와 같다. 
	return len;
}

int str_len2(const char* str)
{
	int len = 0;
	while (*str++) len++; 
	return len;
}

int str_len3(const char* str)
{
	const char* p = str;
	while (*str) str++; 
	return str - p;
}

void main()
{
	char str[256];
	printf("문자열 : ");
	scanf_s("%s", str, sizeof(str));
	printf("이 문자열의 길이는 %d입니다.\n", str_len(str));
}