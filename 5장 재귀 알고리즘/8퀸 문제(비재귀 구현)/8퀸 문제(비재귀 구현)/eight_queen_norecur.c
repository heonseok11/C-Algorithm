#include <stdio.h>
#include "IntStack.h"

int flag_a[8];  // �� �࿡ ���� ��ġ�ߴ��� üũ
int flag_b[15]; // �밢�� /�� ���� ��ġ�ߴ��� üũ�ϴ� �迭
int flag_c[15]; // �밢�� \�� ���� ��ġ�ߴ��� üũ�ϴ� �迭
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
						Push(&qstk, j); // i ��° ���� j ���� Ǫ��
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