#include <stdio.h>

#define Swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

// 내가 생각한 방법 : temp 배열에 넣고 뒤집어서 d 배열에 넣어준다.
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

// 예시 답안
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

	puts("10진수 n 진수로 변환합니다.");
	do{
		printf("변환할 음이 아닌 정수 : ");
		scanf_s("%u", &num);

		do {
			printf("몇 진수로 변환할까요? (2 ~ 36) : ");
			scanf_s("%d", &n_convert,4);
		} while (n_convert < 2 || n_convert > 36);

		digits = convert_num3(num, n_convert, converted_str);

		printf("%d는 %d진수로 \n",num, n_convert);
		for (int i = digits - 1; i >= 0; i--) printf("%c", converted_str[i]);
		printf("입니다.\n");
		printf("한번 더 하려면 1을 입력해주세요 : ");
		scanf_s("%d", &retry);
	} while (retry);
}