#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do {type t = x;x = y; y = t;} while(0)

void quick(int a[], int left, int right)
{
	int i;
	int pl = left; // ���� Ŀ��
	int pr = right; // ������ Ŀ�� 
	int pivot = a[(pl + pr) / 2]; // ��� ��Ҹ� �ǹ����� ����

	do {
		while (a[pl] < pivot) pl++; // �ǹ����� ū ��Ҹ� ã���� ���� 
		while (a[pr] > pivot) pr--; // �ǹ����� ���� ��Ҹ� ã���� ����

		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	if (left < pr) quick(a, left, pr);
	if (pl < right) quick(a, pl, right);
} 

void show_quick(int a[], int left, int right)
{
	int i;
	int pl = left; // ���� Ŀ��
	int pr = right; // ������ Ŀ�� 
	int pivot = a[(pl + pr) / 2]; // ��� ��Ҹ� �ǹ����� ����

	printf("a[%d] ~ a[%d] : {", left, right);
	for (i = left; i < right; i++) printf("%d, ", a[i]);
	printf("%d}\n", a[right]);

	do {
		while (a[pl] < pivot) pl++; // �ǹ����� ū ��Ҹ� ã���� ���� 
		while (a[pr] > pivot) pr--; // �ǹ����� ���� ��Ҹ� ã���� ����

		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	if (left < pr) show_quick(a, left, pr);
	if (pl < right) show_quick(a, pl, right);
}

//�������� Q13 : �����͸� ����ؼ� �����غ�
void quick_sort(int a[], int n)
{
	int i;
	int* pl = a;
	int* pr = a + n - 1;
	int pivot = a[n/2];

	do {
		while (*pl < pivot) pl++; // �ǹ����� ū ��Ҹ� ã���� ���� 
		while (*pr > pivot) pr--; // �ǹ����� ���� ��Ҹ� ã���� ����
		
		if (pl <= pr) {
			swap(int, *pl, *pr);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	
	if (a < pr) quick_sort(a, (pr - a) + 1); 
	if (pl < a + n - 1) quick_sort(pl, (a + n - 1 - pl) + 1);
}
//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=tipsware&logNo=221192754086
//�����Ͱ��� ������ �� �ּ� ���̿� ����� �� �� �ִ����� ����ϴ� ���̱� ������ �Ϲ� ��� ����� �ٸ���. 

//void quick_sort(int a[], int n)
//{
//	quick(a, 0, n - 1);
//}

//�������� Q15 : ����� ������ ���� �׷��� ���� ������ �Լ�
void quick_Q15(int a[], int left, int right)
{
	int i;
	int pl = left; // ���� Ŀ��
	int pr = right; // ������ Ŀ�� 
	int pivot = a[(pl + pr) / 2]; // ��� ��Ҹ� �ǹ����� ����

	do {
		while (a[pl] < pivot) pl++; // �ǹ����� ū ��Ҹ� ã���� ���� 
		while (a[pr] > pivot) pr--; // �ǹ����� ���� ��Ҹ� ã���� ����

		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	if (pr - left > right - pl) {
		if (left < pr) quick(a, left, pr);
		if (pl < right) quick(a, pl, right);
	}
	else {
		if (pl < right) quick(a, pl, right);
		if (left < pr) quick(a, left, pr);
	}

//	if (pr - left < right - pl) {
//		swap(int, pl, left);
//		swap(int, pr, right);
//	}
//	if (left < pr)  quick(a, left, pr);
//	if (pl < right) quick(a, pl, right);

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

	//show_quick(x, 0, nx - 1);
	//quick_sort(x, nx);
	quick_Q15(x, 0, nx - 1);

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);
}

