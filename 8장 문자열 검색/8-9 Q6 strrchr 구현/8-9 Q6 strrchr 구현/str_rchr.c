#include <stdio.h>
#include <string.h>

char* str_rchr(const char* s, int c)
{
	c = (char)c;
	char* p = s + strlen(s);
	while (*p != c) {
		if (p == s) return NULL;
		p--;
	}
	return p;
}

//char *str_rchr(const char *s, int c)
//{
//	const char *p = NULL;			
//
//	c = (char)c;
//	while (1) {
//		if (*s == c)				
//			p = s;
//		if (*s == '\0')				
//			break;
//		s++;
//	}
//	return (char *)p;
// 
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

	if ((idx = str_rchr(str, ch)) == NULL) printf("���� %c�� ���ڿ��� �����ϴ�.\n", ch);
	else printf("���� %c�� ���ڿ��� %d��°�� �ֽ��ϴ�.\n", ch, (int)(idx - str + 1));

}