#include <stdio.h>

#define swap(type, x, y) do{type tmp = x; x = y; y = tmp;} while(0)

void swap_ptr(char** x, char** y)
{
	char* tmp = *x;
	*x = *y;
	*y = tmp;
}

void main()
{
	char* s1 = "ABCD";
	char* s2 = "EFGH";

	printf("포인터 s1은 \"%s\"를 가리킵니다.\n", s1);
	printf("포인터 s2은 \"%s\"를 가리킵니다.\n", s2);

	//swap_ptr(&s1, &s2);
	swap(char*, s1, s2);

	printf("포인터 s1은 \"%s\"를 가리킵니다.\n", s1);
	printf("포인터 s2은 \"%s\"를 가리킵니다.\n", s2);
}