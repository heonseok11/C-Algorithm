#include <stdio.h>

void main()
{
	int no;
	printf("2�ڸ� ������ �Է��ϼ���.\n");
	do {
		printf("���� : ");
		scanf_s("%d", &no);
	} while (no < 10 || no > 99); // !(no >= 10 && no <= 99)
	printf("���� no�� ���� %d�� �Ǿ���\n",no);

}