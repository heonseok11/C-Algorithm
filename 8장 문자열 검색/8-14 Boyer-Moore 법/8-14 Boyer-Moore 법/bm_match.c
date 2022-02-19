#include <stdio.h>
#include <string.h>
#include <limits.h>

int count; 

int bm_match(const char txt[], const char pat[])
{
	int pt; // txt 커서
	int pp; // pat 커서
	int txt_len = strlen(txt);
	int pat_len = strlen(pat);
	int skip[UCHAR_MAX + 1]; // 건너뛰기 표 255 + 1

	for (pt = 0; pt <= UCHAR_MAX; pt++)
		skip[pt] = pat_len;				  // 모두 패턴의 길이로 초기화
	for (pt = 0; pt < pat_len - 1; pt++)  // pat에서 마지막 문자의 skip 값은 n이므로 계산에서 제외함
		skip[pat[pt]] = pat_len - pt - 1;

	// 현재 pt == pat_len - 1

	while (pt < txt_len) {
		pp = pat_len - 1;			// pat의 마지막 문자부터 검사 
		while (txt[pt] == pat[pp]) {
			if (pp == 0) return pt; // 모두 일치
			pp--;
			pt--;
		}

		pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
/*
예시 텍스트: ABECBBDEABDE  패턴: ABDE
마지막 문자를 제외하고, 비교 과정에서 이미 텍스트에서 한번 등장한 패턴 안의 문자가 또 텍스트에서 다시 등장한 경우.
==>  ABECBBDEABDE
		 ABDE  ==> BBDE에서 B가 한번 더 등장 원래 skip[B] 는 2 이지만 pat_len - pp 값은 4가 나옴
원래의 skip 배열 값은 pat_len - pt - 1의 값으로 지정되어있는데 그것보다 pat_len - pp 값이 더 크게 나오게 된다는 건, 텍스트에서 등장한 문자가 다시 등장하게 되었다는 것.
이렇게 해줘야 뒤로 안가고 앞으로 가게 해준다. (코드에서 위치지정은, 현재인덱스 + 이동할 거리 = 이동한 패턴의 마지막 문자 위치 이기 때문에)
즉 패턴의 마지막 문자의 중복에 대한 경우는 처음부터 skip 배열 안에 n으로 지정하여, 현재 인덱스 + n  = 다음 검사할 패턴의 마지막 문자 위치 라는 식을 도입해놨는데,
패턴의 마지막 문자 이외에 다른 문자들이 한번 이상 등장하게 되면, 현재 인덱스 + x 위치의 결과로 기존의 패턴위치보다 뒤로 갈 수 있는 경우가 리버스 경우가 생긴다.
==>  ABECBBDEABDE
	   ABDE ==> pt가 6이 되어 오히려 패턴이 앞으로 가버림
그걸 방지하기 위한 코드인 것 같다.
현재 비교하는 과정에서 두 문자가 다른데, 텍스트에 해당하는 문자가 패턴에 들어 있는 문자이긴 한데,
현재 비교 위치가 skip값인 lastindex 위치의 문자가 아닌 이미 그 문자 위치를 지나온 위치인 경우.
현재 비교 결과가 달라서 skip 배열을 참고했더니, 패턴 안에 있는 문자야. 근데 이미 그 lastindex위치를 지나왔기 때문에 그 값을 쓸 순 없고(쓰면 제자리 또는 뒤로감),
현재 인덱스에서 남은 크기(pat_len - pp)를 모두 더해서 앞으로 이동하게끔 해줌.
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

// Q12 함수 과정 출력
int bm_match_print(const char txt[], const char pat[])
{
	int pt; // txt 커서
	int pp; // pat 커서
	int txt_len = strlen(txt);
	int pat_len = strlen(pat);
	int skip[UCHAR_MAX + 1]; // 건너뛰기 표 255 + 1

	for (pt = 0; pt <= UCHAR_MAX; pt++)
		skip[pt] = pat_len;				  // 모두 패턴의 길이로 초기화
	for (pt = 0; pt < pat_len - 1; pt++)  // pat에서 마지막 문자의 skip 값은 n이므로 계산에서 제외함
		skip[pat[pt]] = pat_len - pt - 1;

	// 현재 pt == pat_len - 1

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
	puts("Boyer-Moore법");
	printf("텍스트 : "); scanf("%s", s1);
	printf("패턴 : "); scanf("%s", s2);

	int idx = bm_match_print(s1, s2);
	//int idx = bm_match(s1, s2);
	if (idx == -1)
		puts("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자부터 match 합니다.\n", idx + 1);
}