#include <stdio.h>

char* str_chr(const char* s, int c)
{
	int i = 0;
	c = (char)c;
	while (s[i] != c) {
		if (s[i] == '\0') return NULL;
		i++;
	}
	return s + i;
}

//char *str_chr(const char *s, int c)
//{
//	c = (char)c;
//	while (*s != c) {
//		if (*s == '\0')				/* �߰ߵ��� ������ */
//			return NULL;
//		s++;
//	}
//	return (char *)s;
//}

void main()
{
	char str[64];
	char tmp[64];

	printf("���ڿ� : ");
	scanf_s("%s", str, sizeof(str));

	printf("�˻��� ���� : ");
	scanf_s("%s", tmp, sizeof(tmp));
	int ch = tmp[0];
	char* idx;

	if ((idx = str_chr(str, ch)) == NULL) printf("���� %c�� ���ڿ��� �����ϴ�.\n", ch);
	else printf("���� %c�� ���ڿ��� %d��°�� �ֽ��ϴ�.\n", ch, (int)(idx - str + 1));

}