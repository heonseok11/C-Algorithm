#include <stdio.h>
#include <string.h>
#include <limits.h>

int count; 

int bm_match(const char txt[], const char pat[])
{
	int pt; // txt Ŀ��
	int pp; // pat Ŀ��
	int txt_len = strlen(txt);
	int pat_len = strlen(pat);
	int skip[UCHAR_MAX + 1]; // �ǳʶٱ� ǥ 255 + 1

	for (pt = 0; pt <= UCHAR_MAX; pt++)
		skip[pt] = pat_len;				  // ��� ������ ���̷� �ʱ�ȭ
	for (pt = 0; pt < pat_len - 1; pt++)  // pat���� ������ ������ skip ���� n�̹Ƿ� ��꿡�� ������
		skip[pat[pt]] = pat_len - pt - 1;

	// ���� pt == pat_len - 1

	while (pt < txt_len) {
		pp = pat_len - 1;			// pat�� ������ ���ں��� �˻� 
		while (txt[pt] == pat[pp]) {
			if (pp == 0) return pt; // ��� ��ġ
			pp--;
			pt--;
		}

		pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
/*
���� �ؽ�Ʈ: ABECBBDEABDE  ����: ABDE
������ ���ڸ� �����ϰ�, �� �������� �̹� �ؽ�Ʈ���� �ѹ� ������ ���� ���� ���ڰ� �� �ؽ�Ʈ���� �ٽ� ������ ���.
==>  ABECBBDEABDE
		 ABDE  ==> BBDE���� B�� �ѹ� �� ���� ���� skip[B] �� 2 ������ pat_len - pp ���� 4�� ����
������ skip �迭 ���� pat_len - pt - 1�� ������ �����Ǿ��ִµ� �װͺ��� pat_len - pp ���� �� ũ�� ������ �ȴٴ� ��, �ؽ�Ʈ���� ������ ���ڰ� �ٽ� �����ϰ� �Ǿ��ٴ� ��.
�̷��� ����� �ڷ� �Ȱ��� ������ ���� ���ش�. (�ڵ忡�� ��ġ������, �����ε��� + �̵��� �Ÿ� = �̵��� ������ ������ ���� ��ġ �̱� ������)
�� ������ ������ ������ �ߺ��� ���� ���� ó������ skip �迭 �ȿ� n���� �����Ͽ�, ���� �ε��� + n  = ���� �˻��� ������ ������ ���� ��ġ ��� ���� �����س��µ�,
������ ������ ���� �̿ܿ� �ٸ� ���ڵ��� �ѹ� �̻� �����ϰ� �Ǹ�, ���� �ε��� + x ��ġ�� ����� ������ ������ġ���� �ڷ� �� �� �ִ� ��찡 ������ ��찡 �����.
==>  ABECBBDEABDE
	   ABDE ==> pt�� 6�� �Ǿ� ������ ������ ������ ������
�װ� �����ϱ� ���� �ڵ��� �� ����.
���� ���ϴ� �������� �� ���ڰ� �ٸ���, �ؽ�Ʈ�� �ش��ϴ� ���ڰ� ���Ͽ� ��� �ִ� �����̱� �ѵ�,
���� �� ��ġ�� skip���� lastindex ��ġ�� ���ڰ� �ƴ� �̹� �� ���� ��ġ�� ������ ��ġ�� ���.
���� �� ����� �޶� skip �迭�� �����ߴ���, ���� �ȿ� �ִ� ���ھ�. �ٵ� �̹� �� lastindex��ġ�� �����Ա� ������ �� ���� �� �� ����(���� ���ڸ� �Ǵ� �ڷΰ�),
���� �ε������� ���� ũ��(pat_len - pp)�� ��� ���ؼ� ������ �̵��ϰԲ� ����.
*/

	}
	return -1;
}

void _print(const char txt[], const char pat[], int pt, int pp, char c)
{
	if (pp == strlen(pat) - 1) printf("%d %s\n", count++, txt);
	else printf("  %s\n", txt);
	printf("%*s", 2 + pt, "");
	printf("%c\n", c);
	printf("%*s%s\n", 2 + pt - pp, "", pat);
}

// Q12 �Լ� ���� ���
int bm_match_print(const char txt[], const char pat[])
{
	int pt; // txt Ŀ��
	int pp; // pat Ŀ��
	int txt_len = strlen(txt);
	int pat_len = strlen(pat);
	int skip[UCHAR_MAX + 1]; // �ǳʶٱ� ǥ 255 + 1

	for (pt = 0; pt <= UCHAR_MAX; pt++)
		skip[pt] = pat_len;				  // ��� ������ ���̷� �ʱ�ȭ
	for (pt = 0; pt < pat_len - 1; pt++)  // pat���� ������ ������ skip ���� n�̹Ƿ� ��꿡�� ������
		skip[pat[pt]] = pat_len - pt - 1;

	// ���� pt == pat_len - 1

	while (pt < txt_len) {
		pp = pat_len - 1;			

		while (txt[pt] == pat[pp]) {
			_print(txt, pat, pt, pp, '+');
			if (pp == 0) return pt; 
			pp--;
			pt--;
		}
		_print(txt, pat, pt, pp, '|');
		pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;

	}
	return -1;
}

void main()
{
	char s1[256];
	char s2[256];
	puts("Boyer-Moore��");
	printf("�ؽ�Ʈ : "); scanf("%s", s1);
	printf("���� : "); scanf("%s", s2);

	int idx = bm_match_print(s1, s2);
	//int idx = bm_match(s1, s2);
	if (idx == -1)
		puts("�ؽ�Ʈ�� ������ �����ϴ�.");
	else
		printf("%d��° ���ں��� match �մϴ�.\n", idx + 1);
}