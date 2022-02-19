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
//		if (*s == '\0')				/* 발견되지 않으면 */
//			return NULL;
//		s++;
//	}
//	return (char *)s;
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

	if ((idx = str_chr(str, ch)) == NULL) printf("문자 %c가 문자열에 없습니다.\n", ch);
	else printf("문자 %c는 문자열의 %d번째에 있습니다.\n", ch, (int)(idx - str + 1));

}