#include <stdio.h>

void main()
{
	int i, n;
	unsigned long counter = 0;

	//1000 이하의 소수를 모두 구하는 식
	for (n = 2; n <= 1000; n++) {
		for (i = 2; i < n; i++) {
			counter++;
			if (n % i == 0) break;
		}
		if (n == i) printf("%d\n", n);
	}

	printf("나눗셈을 실행한 횟수 : %lu\n", counter);

}