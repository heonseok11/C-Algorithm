#include <stdio.h>

typedef struct {
	int y;
	int m;
	int d;
}Date;

int mdays[2][12] = {
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },	/* 평년 */
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }	/* 윤년 */
};

int isleap(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

Date Dateof(int y, int m, int d)
{
	Date today;
	today.y = y;
	today.m = m;
	today.d = d;

	return today;
}

Date After(Date x, int n)
{
	x.d += n;

	while (x.d > mdays[isleap(x.y)][x.m - 1]) {
		x.d -= mdays[isleap(x.y)][x.m - 1];
		if (++x.m > 12) {
			x.y++;
			x.m = 1;
		}
	}
	return x;
}

Date Before(Date x, int n)
{
	x.d -= n;
	while (x.d < 1) { 
		if (--x.m < 1) {
			x.y--;
			x.m = 12;
		}
		x.d += mdays[isleap(x.y)][x.m - 1];
	}
	return x;
}

void Print(Date x)
{
	int y = x.y;
	int m = x.m;
	int d = x.d;
	printf("%04d년 %02d월 %02d일\n", x.y, x.m, x.d);
}

void main()
{
	int y, m, d, n;
	printf("년도 입력 : "); scanf_s("%d", &y);
	printf("월 입력 : "); scanf_s("%d", &m);
	printf("일 입력 : "); scanf_s(" %d", &d);
	
	Date day = Dateof(y, m, d);
	printf("%d년 %d월 %d일로부터 n일 뒤의 날짜를 구합니다. n을 입력해주세요 : ", day.y, day.m, day.d);
	scanf_s("%d", &n);
	printf("%d년 %d월 %d일로부터 %d일 뒤의 날짜는 다음과 같습니다.\n",day.y,day.m,day.d, n);
	Print(After(day, n));
	
	printf("\n%d년 %d월 %d일로부터 n일 앞의 날짜를 구합니다.n을 입력해주세요 : ", day.y, day.m, day.d);
	scanf_s("%d", &n);
	printf("%d년 %d월 %d일로부터 %d일 앞의 날짜는 다음과 같습니다.\n", day.y, day.m, day.d, n);
	Print(Before(day, n));

}