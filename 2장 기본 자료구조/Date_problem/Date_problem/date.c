#include <stdio.h>

typedef struct {
	int y;
	int m;
	int d;
}Date;

int mdays[2][12] = {
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },	/* ��� */
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }	/* ���� */
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
	printf("%04d�� %02d�� %02d��\n", x.y, x.m, x.d);
}

void main()
{
	int y, m, d, n;
	printf("�⵵ �Է� : "); scanf_s("%d", &y);
	printf("�� �Է� : "); scanf_s("%d", &m);
	printf("�� �Է� : "); scanf_s(" %d", &d);
	
	Date day = Dateof(y, m, d);
	printf("%d�� %d�� %d�Ϸκ��� n�� ���� ��¥�� ���մϴ�. n�� �Է����ּ��� : ", day.y, day.m, day.d);
	scanf_s("%d", &n);
	printf("%d�� %d�� %d�Ϸκ��� %d�� ���� ��¥�� ������ �����ϴ�.\n",day.y,day.m,day.d, n);
	Print(After(day, n));
	
	printf("\n%d�� %d�� %d�Ϸκ��� n�� ���� ��¥�� ���մϴ�.n�� �Է����ּ��� : ", day.y, day.m, day.d);
	scanf_s("%d", &n);
	printf("%d�� %d�� %d�Ϸκ��� %d�� ���� ��¥�� ������ �����ϴ�.\n", day.y, day.m, day.d, n);
	Print(Before(day, n));

}