#include <stdio.h>

void spira(int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n - i; j++) printf(" ");
		for (int j = 0; j < 2*i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void nrpira(int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) printf(" ");
		for (int j = 1; j < 2 * (n - i); j++) printf("%d", i + 1);
		printf("\n");
	}

}


void main()
{
	int n;

	do {
		printf("nÀ» ÀÔ·Â : ");
		scanf_s("%d", &n);
	} while (n <= 0);
	
	//spira(n);
	nrpira(n);


}