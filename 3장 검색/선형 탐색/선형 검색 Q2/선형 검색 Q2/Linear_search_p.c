#include <stdio.h>
#include <malloc.h>

int search(int* x, int n, int key)
{
	int i, j;
	printf("   |");
	for (i = 0; i < n; i++) {
		printf("%3d", i);
	}
	printf("\n---+");
	for (i = 0; i < n; i++) {
		printf("---");
	}
	printf("\n");

	for (i = 0; i < n; i++) {
		printf("   |");
		printf("%*s", 3 * (i - 1) + 5, ""); // �̰� ���� �����̳�..?
		/*
		printf("%*s", parameter1, parameter2);
		���� ���� ���·� printf�� ���Ǵ� ��찡 �ִ�.
		parameter1���� ������ ���̸�ŭ parameter2 ���ڿ��� ����Ѵٴ� �ǹ��̴�.
		*/
		printf("*\n");
		printf("  %d|",i);
		for (j = 0; j < n; j++) {
			printf(" %2d", x[j]);
		}
		printf("\n   |\n");

		if (x[i] == key) break;
	}

	return i == n ? -1 : i;
}

void main()
{
	int nx, key, index;
	puts("���� Ž��");
	printf("��� ���� : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ",i);
		scanf_s("%d", x + i);
	}
	printf("Ű �Է� : ");
	scanf_s("%d", &key);
	index = search(x, nx, key);

	if (index == -1) puts("Ž�� ����");
	else printf("%d�� x[%d]�� �־����ϴ�.", key, index);
	free(x);
}