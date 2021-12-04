#include <stdio.h>

void main()
{
	int num, n = 0;

	printf("숫자를 입력하세요 : ");
	scanf_s("%d", &num);
	
	while(num > 0) {
		num /= 10;
		n++;
	}


	printf("그 수는 %d 자리입니다.", n);
}