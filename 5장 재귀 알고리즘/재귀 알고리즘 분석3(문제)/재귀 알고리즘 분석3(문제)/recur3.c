#include <stdio.h>
#include "IntStack.h"

void recur3(int n)
{
	int end = n;
	int step = 0;
	IntStack nstk, sstk;			/* ���� */

	Initialize(&nstk, 100);
	Initialize(&sstk, 100);

	while (1) {
		if (n > 0) {
			Push(&nstk, n);
			Push(&sstk, step);

			if(step == 0) 
				n = n - 1;
			else if (step == 1) {
				n = n - 2;
				step = 0;
			}
			continue;
		}
		do{
			Pop(&nstk, &n);
			Pop(&sstk, &step);
			step++;
			
			if (step == 2) {
				printf("%d ", n);
				if (IsEmpty(&nstk)) return;
			}
		} while (step == 2); // step == 2 �϶� �� �������� �ö󰡰� �Ѱ�. 
	}
	

	Terminate(&nstk);
	Terminate(&sstk);
}

void main()
{
	int x;
	printf("x�� �Է��ϼ���: ");
	scanf_s("%d", &x);
	recur3(x);
}