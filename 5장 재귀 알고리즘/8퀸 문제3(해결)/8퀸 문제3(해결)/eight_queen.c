#include <stdio.h>
#include <string.h>

int flag_a[8];  // 각 행에 퀸을 배치했는지 체크
int flag_b[15]; // 대각선 /에 퀸을 배치했는지 체크하는 배열
int flag_c[15]; // 대각선 \에 퀸을 배치했는지 체크하는 배열
int pos[8];
int board[8][8];

void Print()
{
	for (int i = 0; i < 8; i++) printf("%2d", pos[i]);
	putchar('\n');
}

void Print2()
{
	int i, j;
	for (i = 0; i < 8; i++) {
		board[i][pos[i]] = 1;
	}
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (board[i][j]) printf("□");
			else printf("■");
		}
		printf("\n");
	}
	printf("\n");
	memset(board, 0, 64 * sizeof(int));

}

//void print(void)
//{
//	int	 i, j;
//
//	for (i = 0; i < 8; i++) {
//		for (j = 0; j < 8; j++)
//			printf("%s", j == pos[i] ? "■" : "□");
//		putchar('\n');
//	}
//	putchar('\n');
//}
//

void set(int i)
{
	for (int j = 0; j < 8; j++) {
		if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7]) {
			pos[i] = j;
			if (i == 7) {
				Print2();
			}
			else {
				flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
				set(i + 1);
				flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
			}
		}
	}
}

void main()
{
	set(0);
}