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
		printf("%*s", 3 * (i - 1) + 5, ""); // 이거 등차 수열이네..?
		/*
		printf("%*s", parameter1, parameter2);
		위와 같은 형태로 printf가 사용되는 경우가 있다.
		parameter1으로 지정한 길이만큼 parameter2 문자열을 출력한다는 의미이다.
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
	puts("선형 탐색");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ",i);
		scanf_s("%d", x + i);
	}
	printf("키 입력 : ");
	scanf_s("%d", &key);
	index = search(x, nx, key);

	if (index == -1) puts("탐색 실패");
	else printf("%d는 x[%d]에 있었습니다.", key, index);
	free(x);
}