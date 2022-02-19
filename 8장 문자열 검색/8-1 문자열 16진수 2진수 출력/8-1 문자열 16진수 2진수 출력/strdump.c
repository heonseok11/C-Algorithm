#include <stdio.h>
#include <limits.h> // �������� ��ȿ����


// ���ڿ� ���� ���ڸ� 16������ 2������ ����ϴ� �Լ�
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