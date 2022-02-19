#include <stdio.h>

int str_ncmp(const char* s1, const char* s2, size_t n)
{
	while (n && *s1 && *s2) {
		if (*s1 != *s2) return (unsigned char)*s1 - (unsigned char)*s2;
		s1++;
		s2++;
		n--;
	}
	if (!n) return 0; // n이 0이 되어서 루프에서 빠져나온 경우 ==> n까지 문자열 동일
	if (*s1) return 1; // n이 0이 아니고 s1이 남았는데 s2의 문자열이 끝나버린 경우 s1 > s2
	return -1; // s1 < s2;
}

//int str_ncmp(const char *s1, const char *s2, size_t n)
//{
//	while (n && *s1 && *s2) {
//		if (*s1 != *s2)			
//			return (unsigned char)*s1 - (unsigned char)*s2;
//		s1++;
//		s2++;
//		n--;
//	}
//	if (!n)  return 0;
//	if (*s1) return 1;
//	return -1;
//}

void main()
{
	char str[128];
	puts("\"STRING\"의 처음 3개 문자와 비교합니다.");
	puts("\"XXXX\"면 종료합니다.");
	while (1) {
		printf("문자열 str : ");
		scanf("%s", str);
		if (str_ncmp("XXXX", str, 3) == 0) break;
		printf("str_cmp(\"STRING\", str) = %d\n", str_ncmp("STRING", str, 3));
	}
}