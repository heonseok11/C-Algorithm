#include <stdio.h>
#include <string.h>

void main()
{
	char s1[256];
	char s2[256];
	puts("strstr 함수");
	printf("텍스트 : "); scanf("%s", s1);
	printf("패턴 : "); scanf("%s", s2);

	char* p = strstr(s1, s2);
	if (p == NULL)
		puts("텍스트에 패턴이 없습니다.");
	else {
		int offset = p - s1;
		printf("\n%s\n", s1);
		printf("\n%*s|\n", offset,"");
		printf("\n%*s%s\n", offset,"",s2);
	}
}