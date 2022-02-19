#include <stdio.h>

int str_len(const char *str)
{
	int len = 0;
	while (str[len]) len++; // �ι����� �ε����� ���ڿ��� ���̿� ����. 
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
	printf("���ڿ� : ");
	scanf_s("%s", str, sizeof(str));
	printf("�� ���ڿ��� ���̴� %d�Դϴ�.\n", str_len(str));
}