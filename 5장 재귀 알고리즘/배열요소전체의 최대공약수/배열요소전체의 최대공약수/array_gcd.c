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
///*--- 요솟수 n인 배열 a의 모든 요소의 최대 공약수를 구합니다. ---*/
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
	printf("배열의 개수를 입력하세요 : ");
	scanf_s("%d", &n);

	int* a = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		printf("a[%d] : ", i);
		scanf_s("%d", &a[i]);
	}

	printf("배열 a의 최대공약수는 %d 입니다.\n", gcd_array(a, n));

}