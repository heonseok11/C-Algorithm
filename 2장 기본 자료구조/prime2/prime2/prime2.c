#include <stdio.h>

void main()
{
	int i, n;
	int prime[500]; // �Ҽ��� �����ϴ� �迭
	int ptr = 0; // �̹� ���� �Ҽ��� ����
	unsigned long counter = 0;
	prime[ptr++] = 2; // 2�� ù��° �Ҽ��̴�. 

	for (n = 3; n <= 1000; n += 2) { // ¦���� �Ҽ��� �ƴϹǷ� Ȧ������ ������� �Ѵ�. 
		for (i = 1; i < ptr; i++) { // �̹� ���� �Ҽ��� ���� 
			counter++;
			if (n % prime[i] == 0) break; // �Ҽ��� ������ �������� �Ҽ��� �ƴϴ�. 
		}
		if (ptr == i) // �ѹ��� ������ �������� �ʾ� �Ҽ��� ������ i�� ���� ����.  
			prime[ptr++] = n;
	}

	for (i = 0; i < ptr; i++) {
		printf("%d\n", prime[i]);
	}
	printf("�������� ������ Ƚ�� : %lu\n", counter);
}