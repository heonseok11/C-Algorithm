#include <stdio.h>

int bf_match(const char txt[], const char pat[])
{
	int pt = 0; // txt 커서
	int pp = 0; // pat 커서

	while (txt[pt] != '\0' && pat[pp] != '\0') {
		if (txt[pt] == pat[pp]) {
			pt++;
			pp++;
		}
		else {
			pt = pt - pp + 1; 
			pp = 0;
		}
	}
	if (pat[pp] == '\0') return pt - pp;
	return -1;
}

// Q9 브루트-포스법 과정 출력
int bf_match_print(const char txt[], const char pat[])
{
	int pt = 0; // txt 커서
	int pp = 0; // pat 커서
	int count = 0;
	int pat_pos;

	while (txt[pt] != '\0' && pat[pp] != '\0') {
		if (!pp) {
			printf("%d %s\n", pt, txt);
			pat_pos = pt;
		} else printf("  %s\n", txt);

		char cmp = (txt[pt] == pat[pp]) ? '+' : '|';
		printf("%*s%c\n", 2 + pt, "", cmp);
		printf("%*s%s\n", 2 + pat_pos, "", pat);

		if (txt[pt] == pat[pp]) {
			pt++;
			pp++;
		}
		else {
			pt = pt - pp + 1;
			pp = 0;
		}
		count++;
	}
	printf("비교를 %d회 시도합니다.",count);
	if (pat[pp] == '\0') return pt - pp;
	return -1;
}

void main()
{
	int idx;
	char s1[256];
	char s2[256];
	puts("브루트-포스법");
	printf("텍스트 : "); scanf("%s", s1);
	printf("패턴 : "); scanf("%s", s2);

	//idx = bf_match(s1, s2);
	idx = bf_match_print(s1, s2);
	if (idx == -1) puts("텍스트에 패턴이 없습니다.");
	else printf("%d번째 문자부터 match 합니다.\n", idx + 1);
}