#include <stdio.h>
#include <string.h>

void main()
{
	char s1[256];
	char s2[256];
	puts("strstr �Լ�");
	printf("�ؽ�Ʈ : "); scanf("%s", s1);
	printf("���� : "); scanf("%s", s2);

	char* p = strstr(s1, s2);
	if (p == NULL)
		puts("�ؽ�Ʈ�� ������ �����ϴ�.");
	else {
		int offset = p - s1;
		printf("\n%s\n", s1);
		printf("\n%*s|\n", offset,"");
		printf("\n%*s%s\n", offset,"",s2);
	}
}