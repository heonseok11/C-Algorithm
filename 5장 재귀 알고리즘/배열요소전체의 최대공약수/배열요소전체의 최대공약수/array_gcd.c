#include <stdio.h>
#include <malloc.h>

int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}

int gcd_array(const int a[], int n)
{
	int x = a[0];
	for (int i = 0; i < n - 1; i++) {
		x = gcd(x, a[i + 1]);
	}
	return x;
}
///*--- ��ڼ� n�� �迭 a�� ��� ����� �ִ� ������� ���մϴ�. ---*/
//int gcd_array(const int a[], int n)
//{
//	if (n == 1)
//		return a[0];
//	else if (n == 2)
//		return gcd(a[0], a[1]);
//	else
//		return gcd(a[0], gcd_array(&a[1], n - 1));
//}

void main()
{
	int n;
	printf("�迭�� ������ �Է��ϼ��� : ");
	scanf_s("%d", &n);

	int* a = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		printf("a[%d] : ", i);
		scanf_s("%d", &a[i]);
	}

	printf("�迭 a�� �ִ������� %d �Դϴ�.\n", gcd_array(a, n));

}