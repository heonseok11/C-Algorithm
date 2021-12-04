#include <stdio.h>

#define Swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

// ���� ������ ��� : temp �迭�� �ְ� ����� d �迭�� �־��ش�.
int convert_num1(unsigned int num, int n_convert, char d[])
{
	int i, digits = 0;
	char str[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char temp[100] = { 0, };

	if (num == 0) 
		temp[digits++] = str[0];
	else 
		while (num) {
			temp[digits++] = str[num % n_convert];
			num /= n_convert;
		}
	
	for (i = 0; i < digits; i++) {
		d[i] = temp[digits - i - 1];
	}

	return digits;
}

// ���� ���
int convert_num2(unsigned int num, int n_convert, char d[])
{
	int i, digits = 0;
	char str[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if (num == 0)
		d[digits++] = str[0];
	else
		while (num) {
			d[digits++] = str[num % n_convert];
			num /= n_convert;
		}

	for (i = 0; i < digits / 2; i++) {
		Swap(char, d[i], d[digits - i - 1]);
	}

	return digits;
}

int convert_num3(unsigned int num, int n_convert, char d[])
{
	int i, digits = 0;
	char str[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if (num == 0)
		d[digits++] = str[0];
	else
		while (num) {
			d[digits++] = str[num % n_convert];
			printf("%2d|     %2d ... %c\n", n_convert, num, str[num % n_convert]);
			printf("  + ------\n");
			num /= n_convert;
		}
	printf("        %d\n",num);

	return digits;
}

void main()
{
	unsigned int num;
	int n_convert, digits, retry = 0;
	char converted_str[100];

	puts("10���� n ������ ��ȯ�մϴ�.");
	do{
		printf("��ȯ�� ���� �ƴ� ���� : ");
		scanf_s("%u", &num);

		do {
			printf("�� ������ ��ȯ�ұ��? (2 ~ 36) : ");
			scanf_s("%d", &n_convert,4);
		} while (n_convert < 2 || n_convert > 36);

		digits = convert_num3(num, n_convert, converted_str);

		printf("%d�� %d������ \n",num, n_convert);
		for (int i = digits - 1; i >= 0; i--) printf("%c", converted_str[i]);
		printf("�Դϴ�.\n");
		printf("�ѹ� �� �Ϸ��� 1�� �Է����ּ��� : ");
		scanf_s("%d", &retry);
	} while (retry);
}