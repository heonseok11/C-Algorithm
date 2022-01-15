#include <stdio.h>
#include "IntStack.h"

int flag_a[8];  // 각 행에 퀸을 배치했는지 체크
int flag_b[15]; // 대각선 /에 퀸을 배치했는지 체크하는 배열
int flag_c[15]; // 대각선 \에 퀸을 배치했는지 체크하는 배열
int pos[8];

void Print1()
{
	for (int i = 0; i < 8; i++) printf("%2d", pos[i]);
	putchar('\n');
}

void set(int i)
{
	int j;
	IntStack qstk;
	Initialize(&qstk, 8);

Start:
	while (1) {
		j = 0;
		while (1) {
			while (j < 8) {
				if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7]) {
					pos[i] = j;
					if (i == 7)
						Print1();
					else {
						flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
						i++;
						Push(&qstk, j); // i 번째 열의 j 행을 푸시
						goto Start;
					}
				}
				j++;
			}
			if (--i == -1) return;
			Pop(&qstk, &j);
			flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
			j++;
		}
	}

	Terminate(&qstk);
}

void main()
{
	set(0);
}