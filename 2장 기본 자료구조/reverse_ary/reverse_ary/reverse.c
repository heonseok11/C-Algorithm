#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Swap(type, x, y) do{type t = x; x = y; y = t;} while(0)
// �����ݷ� ���������� do while ���� ����ؾ� �Ѵ�. ġȯ�� if(ture) {}; ���Ǹ� if���� ��� if���� ���ܹ����� else������ �Ѿ�� �ʱ� �����̴�. 

void reverse(int a[], int n)
{
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n; j++) printf("%d ", a[j]);
		printf("\na[%d]�� a[%d]�� ��ȯ�մϴ�.\n",i,n-i-1);
		Swap(int, a[i], a[n - i - 1]);
	}
}

void main()
{
	int i, n;

	printf("��� ���� : "); scanf_s("%d", &n);
	int* p = (int*)calloc(n, sizeof(int));
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		p[i] = rand() % 9 + 1; 
		printf("p[%d] = %d\n", i, *(p + i));
	}
	
	reverse(p, n);
	for (i = 0; i < n; i++) {
		printf("%d ", p[i]);
	}
	printf("\n���� ���� �Ϸ�\n");
	free(p);

}