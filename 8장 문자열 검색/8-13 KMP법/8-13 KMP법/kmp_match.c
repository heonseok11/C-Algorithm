#include <stdio.h>
#include <string.h>

int kmp_match(const char txt[], const char pat[])
{
	int pt = 1; // txt 커서  
	int pp = 0; // pat 커서
	int skip[1024] = {0,}; // 건너뛰기 표

	// 표 만들기
	skip[pt] = 0; 
	// pat의 pt번째 라고 생각하자. 
	while (pat[pt] != '\0') {
		if (pat[pt] == pat[pp])
			skip[++pt] = ++pp;
		else if (pp == 0) // 시작부터 일치하는 부분 없음 
			skip[++pt] = pp;
		else              // 시작 이후에 일치하는 부분 없음 
			pp = skip[pp];
	}

	pt = pp = 0;
	while (txt[pt] != '\0' && pat[pp] != '\0') {
		if (txt[pt] == pat[pp]) {
			pt++;
			pp++;
		}
		else if (pp == 0) // 패턴의 0부터 틀린경우 pt만 하나 증가하고 진행
			pt++;
		else 
			pp = skip[pp]; // 패턴이 pp번째까지 같으면 pat[skip[pp]]부터 비교해라.
	}
	if (pat[pp] == '\0') return pt - pp;

	return -1;
}

// Q11 과정 출력
int kmp_match_print(const char txt[], const char pat[])
{
	int pt = 1; // txt 커서  
	int pp = 0; // pat 커서
	int skip[1024] = { 0, }; // 건너뛰기 표

	// 표 만들기
	skip[pt] = 0;
	while (pat[pt] != '\0') {
		if (pat[pt] == pat[pp])
			skip[++pt] = ++pp;
		else if (pp == 0) // 시작부터 일치하는 부분 없음 
			skip[++pt] = pp;
		else              // 시작 이후에 일치하는 부분 없음 
			pp = skip[pp];
	}


	int count = 0;
	pt = pp = 0;
	while (txt[pt] != '\0' && pat[pp] != '\0') {
	
		if (!pp) printf("%d %s\n", count++, txt);
		else printf("  %s\n", txt);

		printf("%*s", 2 + pt, "");

		int tmp = pt - pp;

		if (txt[pt] == pat[pp]) {
			pt++;
			pp++;
			putchar('+');
		}
		else if (pp == 0) {
			pt++;
			putchar('|');
		}
		else {
			pp = skip[pp];
			putchar('|');
		}
		putchar('\n');
		printf("%*s%s\n", 2 + tmp, "",pat);
	}
	if (pat[pp] == '\0') return pt - pp;

	return -1;
}


void main()
{
	int idx;
	char s1[256];
	char s2[256];
	puts("KMP법");
	printf("텍스트 : "); scanf("%s", s1);
	printf("패턴 : "); scanf("%s", s2);

	idx = kmp_match_print(s1, s2);
	if (idx == -1) puts("텍스트에 패턴이 없습니다.");
	else printf("%d번째 문자부터 match 합니다.\n", idx + 1);
}