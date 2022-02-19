#include <stdio.h>

int bf_match(const char txt[], const char pat[])
{
	int pt = 0; // txt Ŀ��
	int pp = 0; // pat Ŀ��

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

// Q9 ���Ʈ-������ ���� ���
int bf_match_print(const char txt[], const char pat[])
{
	int pt = 0; // txt Ŀ��
	int pp = 0; // pat Ŀ��
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
	printf("�񱳸� %dȸ �õ��մϴ�.",count);
	if (pat[pp] == '\0') return pt - pp;
	return -1;
}

void main()
{
	int idx;
	char s1[256];
	char s2[256];
	puts("���Ʈ-������");
	printf("�ؽ�Ʈ : "); scanf("%s", s1);
	printf("���� : "); scanf("%s", s2);

	//idx = bf_match(s1, s2);
	idx = bf_match_print(s1, s2);
	if (idx == -1) puts("�ؽ�Ʈ�� ������ �����ϴ�.");
	else printf("%d��° ���ں��� match �մϴ�.\n", idx + 1);
}