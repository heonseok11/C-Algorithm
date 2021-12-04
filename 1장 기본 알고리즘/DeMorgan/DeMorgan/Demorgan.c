#include <stdio.h>

void main()
{
	int no;
	printf("2자리 정수를 입력하세요.\n");
	do {
		printf("수는 : ");
		scanf_s("%d", &no);
	} while (no < 10 || no > 99); // !(no >= 10 && no <= 99)
	printf("변수 no의 값은 %d이 되었음\n",no);

}