#include <stdio.h>

void move(int n, int x, int y)
{
	if (n > 1)
		move(n - 1, x, 6 - x - y); // 그룹을 시작 기둥에서 중간 기둥으로
	printf("원반[%d]를 %d 기둥에서 %d 기둥으로 옮김\n", n, x, y); // 바닥 원반을 목표 기능으로
	
	if (n > 1)
		move(n - 1, 6 - x - y, y); // 그룹을 중간 기둥에서 목표 기둥으로
}

void move2(int n, int x, int y)
{
	if (n > 1)
		move2(n - 1, x, 6 - x - y); // 그룹을 시작 기둥에서 중간 기둥으로
	printf("원반[%d]를 %c 기둥에서 %c 기둥으로 옮김\n", n, x + 64, y + 64); // 바닥 원반을 목표 기능으로

	if (n > 1)
		move2(n - 1, 6 - x - y, y); // 그룹을 중간 기둥에서 목표 기둥으로
}

//void move(int no, int x, int y)
//{
//	char *name[] = { "Ａ기둥", "Ｂ기둥", "Ｃ기둥" }; 포인터 배열을 이용함
//
//	if (no > 1)
//		move(no - 1, x, 6 - x - y);		/* 그룹을 시작 기둥에서 중간 기둥으로 */
//
//	printf("원반[%d]를 %s에서 %s로 이동\n", no, name[x - 1], name[y - 1]);	/* 바닥을 목적 기둥으로 */
//
//	if (no > 1)
//		move(no - 1, 6 - x - y, y);		/* 그룹을 중간 기둥에서 목표 기둥으로 */
//}
//

void main()
{
	int n;
	printf("하노이의 탑\n원반 개수 : ");
	scanf_s("%d", &n);
	move(n, 1, 3);
	move2(n, 1, 3);
}