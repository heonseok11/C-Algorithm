#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void binary_insertion(int a[], int n)
{
	int i, j;
	
	for (i = 1; i < n; i++) {
		int tmp = a[i];
		int first = 0;
		int last = i - 1;

		if (a[i - 1] > tmp) { // tmp�� a[i-1]���� ũ�ٸ� ������ ������ �ʿ� X
			do {
				int mid = (first + last) / 2;

				if (a[mid] == tmp) {
					first = mid;
					break;
				}
				else if (tmp < a[mid]) last = mid - 1;
				else if (tmp > a[mid]) first = mid + 1;
			} while (first <= last);
			// �ݺ����� ���������� first �� tmp �� �� �ڸ��� ��

			for (j = i; j > first; j--) { 
				a[j] = a[j - 1];
			}
			a[first] = tmp;
		}
	}
}

//void bin_insertion(int a[], int n)
//{
//	int i, j;
//
//	for (i = 1; i < n; i++) {
//		int key = a[i];
//		int pl = 0;		/* �˻� ������ ù �ε��� */
//		int pr = i - 1;	/* �˻� ������ �� �ε��� */
//		int pc;			/* �˻� ������ ��� �ε��� */
//		int pd;			/* �����ϴ� ��ġ�� �ε��� */
//
//		do {
//			pc = (pl + pr) / 2;
//			if (a[pc] == key)		/* �˻� ���� */
//				break;
//			else if (a[pc] < key)
//				pl = pc + 1;
//			else
//				pr = pc - 1;
//		} while (pl <= pr);
//		pd = (pl <= pr) ? pc + 1 : pr + 1;
//
//		for (j = i; j > pd; j--)
//			a[j] = a[j - 1];
//		a[pd] = key;
//	}
//}
//


//���� ���� Q11
void binary_insertion2(int a[], int n)
{
	int i, j;

	for (i = 1; i < n; i++) {
		int tmp = a[i];
		int first = 0;
		int last = i - 1;

		if (a[i - 1] > tmp) { // tmp�� a[i-1]���� ũ�ٸ� ������ ������ �ʿ� X
			do {
				int mid = (first + last) / 2;

				if (a[mid] == tmp) {
					first = mid;
					break;
				}
				else if (tmp < a[mid]) last = mid - 1;
				else if (tmp > a[mid]) first = mid + 1;
			} while (first <= last);
			// �ݺ����� ���������� first �� tmp �� �� �ڸ��� ��

			memmove(&a[first + 1], &a[first], sizeof(int)*(i - first));
			//		memmove(&a[pd + 1], &a[pd], (i - pd) * sizeof(int));
			//		a[pd] = key;
			// ���� ���� �̿��
			
			a[first] = tmp;
		}
	}

}

void main()
{
	int nx, i;
	puts("�ܼ� ���� ����");

	printf("��� ���� : ");
	scanf_s("%d", &nx);
	int* x = (int*)calloc(nx, sizeof(int));

	srand((unsigned int)time(NULL));

	for (i = 0; i < nx; i++) {
		x[i] = rand() % 15 + 1;
		printf("x[%d] = %d\n", i, x[i]);
	}

	binary_insertion2(x, nx);

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);


}