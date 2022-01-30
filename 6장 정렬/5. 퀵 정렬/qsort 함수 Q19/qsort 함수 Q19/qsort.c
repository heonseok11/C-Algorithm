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

/*--- x, y�� ����Ű�� ���ڿ� �� �Լ� ---*/
static int pstrcmp(const void *x, const void *y)
{
	return strcmp(*(const char **)x, *(const char **)y);
}

void main()
{
	char a[][7] = { "LISP", "C", "Ada", "Pascal" };
	char *p[] = { "LISP", "C", "Ada", "Pascal" };

	int num_a = sizeof(a) / sizeof(a[0]);
	puts("a�迭 ������");
	Print1(a, num_a);

	puts("a�迭 ������");
	qsort(a, num_a, sizeof(a[0]), (int(*)(const void*, const void*))strcmp); // ���ڿ��� ���ϴ� strcmp �Լ��� �����Ƿ� �״�� �̿�
	Print1(a, num_a);

	puts("\n\np �����͹迭 ������");
	Print2(p,4);

	puts("p �����͹迭 ������");
	qsort(p, 4, sizeof(char *), (int(*)(const void*, const void*))pstrcmp);
	Print2(p, 4);

	
}