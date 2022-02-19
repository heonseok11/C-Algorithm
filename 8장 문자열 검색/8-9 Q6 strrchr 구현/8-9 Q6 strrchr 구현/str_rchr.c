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

	printf("문자열 : ");
	scanf_s("%s", str, sizeof(str));

	printf("검색할 문자 : ");
	scanf_s("%s", tmp, sizeof(tmp));
	int ch = tmp[0];
	char* idx;

	if ((idx = str_rchr(str, ch)) == NULL) printf("문자 %c가 문자열에 없습니다.\n", ch);
	else printf("문자 %c는 문자열의 %d번째에 있습니다.\n", ch, (int)(idx - str + 1));

}