#include <stdio.h>

void triangleLB(int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void triangleLU(int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void trianlgeRU(int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			printf(" ");
		}
		for (int j = 0; j < n - i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void trianlgeRB(int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			printf(" ");
		}
		for (int j = 0; j < i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}

}

void main()
{
	int n;
	do {
		printf("삼각형의 변의 길이 입력 : ");
		scanf_s("%d", &n);
	} while (n <= 0);
	
	triangleLB(n);
	triangleLU(n);
	trianlgeRU(n);
	trianlgeRB(n);



}