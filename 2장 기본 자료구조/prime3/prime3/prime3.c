#include <stdio.h>
/*

어떤 수 n이 1과 자신이 아닌 두 수의 곱으로 되어 있다고 생각해봅시다. (즉, 소수가 아님)

n = a*b 이고 n' 은 n 의 제곱근이라고 표현합시다.

여기서 만약,

a >= n' 이면, a*b = n = n'*n' 이므로 b<=n' 가 됩니다.

따라서 n' 까지만 검사를 하면 합성수를 이루는 a, b 중 작은 수(위에서는 b)까지는 충분히 체크할 수 있고, 합성수가 존재하지 않으면 소수라고 할 수 있습니다.

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
	printf("곱셈과 나눗셈을 실행한 횟수 : %lu\n", counter);

}