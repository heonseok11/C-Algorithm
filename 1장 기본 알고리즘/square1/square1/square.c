#include <stdio.h>

void main()
{
	int n;
	printf("사각형을 출력합니다.\n");
	printf("입력할 수 : "); scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("*");
		}
		printf("\n");
	}

}