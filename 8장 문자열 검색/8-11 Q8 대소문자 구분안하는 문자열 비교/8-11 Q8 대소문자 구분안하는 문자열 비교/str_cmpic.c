#include <stdio.h>

int str_cmpic(const char* s1, const char* s2)
{
	int c = 'a' - 'A'; // 대소문자의 차이값
	char c1 = *s1, c2 = *s2;
	while (*s1 && *s2) {
		c1 = *s1;
		c2 = *s2;
		if (*s1 >= 'a') c1 = *s1 - c;
		if (*s2 >= 'a') c2 = *s2 - c;
		if (c1 != c2) return (unsigned char)*s1 - (unsigned char)*s2;
		s1++;
		s2++;
	}
	if (*s1) return 1;
	if (*s2) return -1;
	return 0;
}

int str_ncmpic(const char* s1, const char* s2, size_t n)
{
	int c = 'a' - 'A'; // 대소문자의 차이값
	char c1 = *s1, c2 = *s2;
	while (n && *s1 && *s2) {
		c1 = *s1;
		c2 = *s2;
		if (*s1 >= 'a') c1 = *s1 - c;
		if (*s2 >= 'a') c2 = *s2 - c;
		if (c1 != c2) return (unsigned char)*s1 - (unsigned char)*s2;
		s1++;
		s2++;
		n--;
	}
	if (!n) return 0;
	if (*s1) return 1;
	return -1;
}

//#include <ctype.h>의 toupper()함수 이용
//int str_cmpic(const char *s1, const char *s2)
//{
//	while (toupper(*s1) == toupper(*s2)) {
//		if (*s1 == '\0')			
//			return 0;
//		s1++;
//		s2++;
//	}
//	return (unsigned char)toupper(*s1) - (unsigned char)toupper(*s2);
//}
//
//int str_ncmpic(const char *s1, const char *s2, size_t n)
//{
//	while (n && *s1 && *s2) {
//		if (toupper(*s1) != toupper(*s2))			
//			return (unsigned char)toupper(*s1) - (unsigned char)toupper(*s2);
//		s1++;
//		s2++;
//		n--;
//	}
//	if (!n)  return 0;
//	if (*s1) return toupper(*s1);
//	return toupper(*s2);
//}
//

void main()
{
	char str[128];
	puts("\"STRING\"과 비교합니다.");
	puts("\"XXXX\"면 종료합니다.");
	while (1) {
		printf("문자열 str : ");
		scanf("%s", str);
		if (str_ncmpic("XXXX", str, 3) == 0) break;
		printf("str_ncmpic(\"STRING\", str) = %d\n", str_ncmpic("STRING", str, 3));
	}
}