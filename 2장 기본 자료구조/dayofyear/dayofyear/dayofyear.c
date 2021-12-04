#include <stdio.h>

int mdays[][12] = { {31,28,31,30,31,30,31,31,30,31,30,31},
					{31,29,31,30,31,30,31,31,30,31,30,31} };

//1을 반환 하면 윤년, 아니면 평년
int isleap(int year)
{
	
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	// 윤년이려면 4의 배수 가운데 100의 배수를 제외하고, 제외한 100의 배수가운데 400의 배수를 포함시키면 된다. 
}

int dayofyear1(int year, int month, int day)
{
	int i;
	int days = day;
	for (i = 1; i < month; i++) {
		days += mdays[isleap(year)][i-1];
	}

	return days;
}

int dayofyear2(int year, int month, int day)
{

	while (month--) {
		day += mdays[isleap(year)][month - 1];
	}

	return day;
}

void main()
{
	int year, month, day;
	int retry;
	do {
		printf("년 : "); scanf_s("%d", &year);
		printf("월 : "); scanf_s("%d", &month);
		printf("일 : "); scanf_s("%d", &day);
		printf("%d년의 %d일째 입니다.\n", year, dayofyear2(year, month, day));
		printf("다시할까요? (1...예/0...아니오) : ");
		scanf_s("%d",&retry);
	} while (retry);
}