#include <stdio.h>
#include <string.h>

int kmp_match(const char txt[], const char pat[])
{
	int pt = 1; // txt Ŀ��  
	int pp = 0; // pat Ŀ��
	int skip[1024] = {0,}; // �ǳʶٱ� ǥ

	// ǥ �����
	skip[pt] = 0; 
	// pat�� pt��° ��� ��������. 
	while (pat[pt] != '\0') {
		if (pat[pt] == pat[pp])
			skip[++pt] = ++pp;
		else if (pp == 0) // ���ۺ��� ��ġ�ϴ� �κ� ���� 
			skip[++pt] = pp;
		else              // ���� ���Ŀ� ��ġ�ϴ� �κ� ���� 
			pp = skip[pp];
	}

	pt = pp = 0;
	while (txt[pt] != '\0' && pat[pp] != '\0') {
		if (txt[pt] == pat[pp]) {
			pt++;
			pp++;
		}
		else if (pp == 0) // ������ 0���� Ʋ����� pt�� �ϳ� �����ϰ� ����
			pt++;
		else 
			pp = skip[pp]; // ������ pp��°���� ������ pat[skip[pp]]���� ���ض�.
	}
	if (pat[pp] == '\0') return pt - pp;

	return -1;
}

// Q11 ���� ���
int kmp_match_print(const char txt[], const char pat[])
{
	int pt = 1; // txt Ŀ��  
	int pp = 0; // pat Ŀ��
	int skip[1024] = { 0, }; // �ǳʶٱ� ǥ

	// ǥ �����
	skip[pt] = 0;
	while (pat[pt] != '\0') {
		if (pat[pt] == pat[pp])
			skip[++pt] = ++pp;
		else if (pp == 0) // ���ۺ��� ��ġ�ϴ� �κ� ���� 
			skip[++pt] = pp;
		else              // ���� ���Ŀ� ��ġ�ϴ� �κ� ���� 
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
	puts("KMP��");
	printf("�ؽ�Ʈ : "); scanf("%s", s1);
	printf("���� : "); scanf("%s", s2);

	idx = kmp_match_print(s1, s2);
	if (idx == -1) puts("�ؽ�Ʈ�� ������ �����ϴ�.");
	else printf("%d��° ���ں��� match �մϴ�.\n", idx + 1);
}