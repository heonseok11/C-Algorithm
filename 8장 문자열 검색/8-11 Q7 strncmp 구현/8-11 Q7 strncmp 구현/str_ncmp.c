#include <stdio.h>

int str_ncmp(const char* s1, const char* s2, size_t n)
{
	while (n && *s1 && *s2) {
		if (*s1 != *s2) return (unsigned char)*s1 - (unsigned char)*s2;
		s1++;
		s2++;
		n--;
	}
	if (!n) return 0; // n�� 0�� �Ǿ �������� �������� ��� ==> n���� ���ڿ� ����
	if (*s1) return 1; // n�� 0�� �ƴϰ� s1�� ���Ҵµ� s2�� ���ڿ��� �������� ��� s1 > s2
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
	puts("\"STRING\"�� ó�� 3�� ���ڿ� ���մϴ�.");
	puts("\"XXXX\"�� �����մϴ�.");
	while (1) {
		printf("���ڿ� str : ");
		scanf("%s", str);
		if (str_ncmp("XXXX", str, 3) == 0) break;
		printf("str_cmp(\"STRING\", str) = %d\n", str_ncmp("STRING", str, 3));
	}
}