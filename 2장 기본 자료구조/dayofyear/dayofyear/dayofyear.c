#include <stdio.h>

int mdays[][12] = { {31,28,31,30,31,30,31,31,30,31,30,31},
					{31,29,31,30,31,30,31,31,30,31,30,31} };

//1�� ��ȯ �ϸ� ����, �ƴϸ� ���
int isleap(int year)
{
	
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	// �����̷��� 4�� ��� ��� 100�� ����� �����ϰ�, ������ 100�� ������ 400�� ����� ���Խ�Ű�� �ȴ�. 
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
		printf("�� : "); scanf_s("%d", &year);
		printf("�� : "); scanf_s("%d", &month);
		printf("�� : "); scanf_s("%d", &day);
		printf("%d���� %d��° �Դϴ�.\n", year, dayofyear2(year, month, day));
		printf("�ٽ��ұ��? (1...��/0...�ƴϿ�) : ");
		scanf_s("%d",&retry);
	} while (retry);
}