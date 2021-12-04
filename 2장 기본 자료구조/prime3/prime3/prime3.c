#include <stdio.h>
/*

� �� n�� 1�� �ڽ��� �ƴ� �� ���� ������ �Ǿ� �ִٰ� �����غ��ô�. (��, �Ҽ��� �ƴ�)

n = a*b �̰� n' �� n �� �������̶�� ǥ���սô�.

���⼭ ����,

a >= n' �̸�, a*b = n = n'*n' �̹Ƿ� b<=n' �� �˴ϴ�.

���� n' ������ �˻縦 �ϸ� �ռ����� �̷�� a, b �� ���� ��(�������� b)������ ����� üũ�� �� �ְ�, �ռ����� �������� ������ �Ҽ���� �� �� �ֽ��ϴ�.

*/

void main()
{
	int i, n;
	int prime[500];
	int ptr = 0;
	unsigned long counter = 0;
	prime[ptr++] = 2;
	prime[ptr++] = 3;

	for (n = 5; n <= 1000; n +=2) {
		int flag = 0;
		for (i = 1; counter++, prime[i] * prime[i] <= n; i++) {
			counter++;
			if (n % prime[i] == 0) {
				flag = 1;
				break;
			}
		}
		if (!flag) prime[ptr++] = n;
	}

	for (i = 0; i < ptr; i++) {
		printf("%d\n", prime[i]);
	}
	printf("������ �������� ������ Ƚ�� : %lu\n", counter);

}