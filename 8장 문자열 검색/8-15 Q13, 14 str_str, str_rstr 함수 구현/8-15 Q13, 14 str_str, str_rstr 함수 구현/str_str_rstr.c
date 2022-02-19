#include <stdio.h>
#include <string.h>

// Q13
char* str_str(const char* s1, const char* s2)
{
	int pt = 0;
	int pp = 0;

	while (s1[pt] != '\0' && s2[pp] != '\0') {
		if (s1[pt] == s2[pp]) {
			pt++;
			pp++;
		}
		else {
			pt = pt - pp + 1;
			pp = 0;
		}
	}
	if (s2[pp] == '\0') return s1 + pt - pp;

	return NULL;
}

// Q14
char* str_rstr(const char* s1, const char* s2)
{
	int txt_len = strlen(s1);
	int pat_len = strlen(s2);
	int pt = txt_len - 1;
	int pp = pat_len - 1;

	while (pt >= 0) {
		if (s1[pt] == s2[pp]) {
			if (pp == 0) return s1 + pt;
			pt--;
			pp--;
		}
		else {
			pt = pt - pp;
			pp = pat_len - 1;
		}
	}
	
	return NULL;
}

void main()
{
	char s1[256];
	char s2[256];
	puts("strstr �Լ�����");
	printf("�ؽ�Ʈ : "); scanf("%s", s1);
	printf("���� : "); scanf("%s", s2);

	//char* p = str_str(s1, s2);
	char* p = str_rstr(s1, s2);
	if (p == NULL)
		puts("�ؽ�Ʈ�� ������ �����ϴ�.");
	else {
		int offset = p - s1;
		printf("\n%s\n", s1);
		printf("\n%*s|\n", offset, "");
		printf("\n%*s%s\n", offset, "", s2);
	}
}