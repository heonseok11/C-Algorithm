#include <stdio.h>

void main()
{
	int i, n;
	int prime[500]; // 소수를 저장하는 배열
	int ptr = 0; // 이미 얻은 소수의 개수
	unsigned long counter = 0;
	prime[ptr++] = 2; // 2는 첫번째 소수이다. 

	for (n = 3; n <= 1000; n += 2) { // 짝수는 소수가 아니므로 홀수만을 대상으로 한다. 
		for (i = 1; i < ptr; i++) { // 이미 얻은 소수로 나눔 
			counter++;
			if (n % prime[i] == 0) break; // 소수로 나누어 떨어지면 소수가 아니다. 
		}
		if (ptr == i) // 한번도 나누어 떨어지지 않아 소수의 개수와 i의 값이 같다.  
			prime[ptr++] = n;
	}

	for (i = 0; i < ptr; i++) {
		printf("%d\n", prime[i]);
	}
	printf("나눗셈을 실행한 횟수 : %lu\n", counter);
}