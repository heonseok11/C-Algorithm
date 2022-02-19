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

	printf("������ s1�� \"%s\"�� ����ŵ�ϴ�.\n", s1);
	printf("������ s2�� \"%s\"�� ����ŵ�ϴ�.\n", s2);

	//swap_ptr(&s1, &s2);
	swap(char*, s1, s2);

	printf("������ s1�� \"%s\"�� ����ŵ�ϴ�.\n", s1);
	printf("������ s2�� \"%s\"�� ����ŵ�ϴ�.\n", s2);
}