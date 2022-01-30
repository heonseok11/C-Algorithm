#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Print1(char x[][7], int n)
{
	for (int i = 0; i < n; i++) printf("%s\n",x[i]);
}

void Print2(char *x[], int n)
{
	for (int i = 0; i < n; i++) printf("%s\n", x[i]);
}

/*--- x, y가 가리키는 문자열 비교 함수 ---*/
static int pstrcmp(const void *x, const void *y)
{
	return strcmp(*(const char **)x, *(const char **)y);
}

void main()
{
	char a[][7] = { "LISP", "C", "Ada", "Pascal" };
	char *p[] = { "LISP", "C", "Ada", "Pascal" };

	int num_a = sizeof(a) / sizeof(a[0]);
	puts("a배열 정렬전");
	Print1(a, num_a);

	puts("a배열 정렬후");
	qsort(a, num_a, sizeof(a[0]), (int(*)(const void*, const void*))strcmp); // 문자열을 비교하는 strcmp 함수가 있으므로 그대로 이용
	Print1(a, num_a);

	puts("\n\np 포인터배열 정렬전");
	Print2(p,4);

	puts("p 포인터배열 정렬후");
	qsort(p, 4, sizeof(char *), (int(*)(const void*, const void*))pstrcmp);
	Print2(p, 4);

	
}