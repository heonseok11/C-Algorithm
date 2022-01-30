#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "IntStack.h"

#define swap(type, x, y) do {type t = x;x = y; y = t;} while(0)

void quick(int a[], int left, int right)
{
	IntStack lstack; // ���� ù��° ����� �ε����� �����ϴ� ����
	IntStack rstack; // ���� ������ ����� �ε����� �����ϴ� ����

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	while (!IsEmpty(&lstack)) {
		int pl = (Pop(&lstack, &left), left); // ���� Ŀ��
		// �޸� ������ ���, ��� �� ������ �𸣰ڴ�
		// int pl = Pop(&lstack, &left);
		// pl = left;
		int pr = (Pop(&rstack, &right), right); // ������ Ŀ��
		int pivot = a[(left + right) / 2]; // ��� ��Ҹ� �ǹ����� ����

		do {
			while (a[pl] < pivot) pl++; // �ǹ����� ū ��Ҹ� ã���� ���� 
			while (a[pr] > pivot) pr--; // �ǹ����� ���� ��Ҹ� ã���� ����

			if (pl <= pr) {
				swap(int, a[pl], a[pr]);
				pl++;
				pr--;
			}
		} while (pl <= pr);

		if (left < pr) {
			Push(&lstack, left);
			Push(&rstack, pr);
		}
		if (pl < right) {
			Push(&lstack, pl);
			Push(&rstack, right);
		}
	}
	Terminate(&lstack);
	Terminate(&rstack);
}

//�������� Q14
void quick_Print(int a[], int left, int right)
{
	IntStack lstack; // ���� ù��° ����� �ε����� �����ϴ� ����
	IntStack rstack; // ���� ������ ����� �ε����� �����ϴ� ����

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	printf("\na[%d] ~ a[%d]�� ���ÿ� Ǫ���մϴ�.\n", left, right);
	printf("Lstack:");   Print(&lstack);
	printf("Rstack:");   Print(&rstack);

	while (!IsEmpty(&lstack)) {
		int pl = (Pop(&lstack, &left), left); // ���� Ŀ��
		// �޸� ������ ���, ��� �� ������ �𸣰ڴ�
		// int pl = Pop(&lstack, &left);
		// pl = left;
		int pr = (Pop(&rstack, &right), right); // ������ Ŀ��
		int pivot = a[(left + right) / 2]; // ��� ��Ҹ� �ǹ����� ����

		printf("====================================================\n");
		printf("���ÿ��� ���� �迭�� ������ a[%d] ~ a[%d]�Դϴ�.\n", left, right);
		printf("====================================================\n");

		do {
			while (a[pl] < pivot) pl++; // �ǹ����� ū ��Ҹ� ã���� ���� 
			while (a[pr] > pivot) pr--; // �ǹ����� ���� ��Ҹ� ã���� ����

			if (pl <= pr) {
				swap(int, a[pl], a[pr]);
				pl++;
				pr--;
			}
		} while (pl <= pr);

		if (left < pr) {
			Push(&lstack, left);
			Push(&rstack, pr);

			printf("\na[%d] ~ a[%d]�� ���ÿ� Ǫ���մϴ�.\n", left, pr);
			printf("Lstack:\n");   Print(&lstack);
			printf("Rstack:\n");   Print(&rstack);
		}
		if (pl < right) {
			Push(&lstack, pl);
			Push(&rstack, right);

			printf("\na[%d] ~ a[%d]�� ���ÿ� Ǫ���մϴ�.\n", pl, right);
			printf("Lstack:\n");   Print(&lstack);
			printf("Rstack:\n");   Print(&rstack);
		}
	}
	Terminate(&lstack);
	Terminate(&rstack);
}

//�������� Q15 : ����� ������ ���� �׷��� ���� ������ �Լ�
void quick_Q15(int a[], int left, int right)
{
	IntStack lstack; // ���� ù��° ����� �ε����� �����ϴ� ����
	IntStack rstack; // ���� ������ ����� �ε����� �����ϴ� ����

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	while (!IsEmpty(&lstack)) {
		int pl = (Pop(&lstack, &left), left); // ���� Ŀ��
		// �޸� ������ ���, ��� �� ������ �𸣰ڴ�
		// int pl = Pop(&lstack, &left);
		// pl = left;
		int pr = (Pop(&rstack, &right), right); // ������ Ŀ��
		int pivot = a[(left + right) / 2]; // ��� ��Ҹ� �ǹ����� ����

		do {
			while (a[pl] < pivot) pl++; // �ǹ����� ū ��Ҹ� ã���� ���� 
			while (a[pr] > pivot) pr--; // �ǹ����� ���� ��Ҹ� ã���� ����

			if (pl <= pr) {
				swap(int, a[pl], a[pr]);
				pl++;
				pr--;
			}
		} while (pl <= pr);

		if (pr - left < right - pl) {
			swap(int, left, pl);
			swap(int, pr, right);
		}

		if (left < pr) {
			Push(&lstack, left);
			Push(&rstack, pr);
		}
		if (pl < right) {
			Push(&lstack, pl);
			Push(&rstack, right);
		}
	}
	Terminate(&lstack);
	Terminate(&rstack);
}

void main()
{
	int i, nx;

	puts("�迭�� �����ϴ�.");
	printf("��� ���� : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));
	srand((unsigned int)time(NULL));

	for (i = 0; i < nx; i++) {
		x[i] = rand() % 20 + 1;
		printf("x[%d] = %d\n", i, x[i]);
	}

	//quick(x, 0, nx - 1);
	//quick_Print(x, 0, nx - 1);
	quick_Q15(x, 0, nx - 1);

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);
}

