#include <stdio.h>
#include <stdlib.h>
#include "double_stack.h"

int initialize(STACK* s, int max)
{
	s->ptrA = 0; // �Ʒ��� ���� ����
	if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) {
		s->max = 0;
		s->ptrB = 0; 
		return -1;

	}
	else {
		s->max = max;
		s->ptrB = max - 1; // ������ ���� �Ʒ���
		return 0;
	}
}

int PushA(STACK* s, int x)
{
	if (s->ptrA >= s->ptrB + 1) return -1; // ������ �̹� ������
	s->stk[s->ptrA++] = x;
	return 0;
}

int PushB(STACK* s, int x)
{
	if (s->ptrA >= s->ptrB + 1) return -1; // ������ �̹� ������
	s->stk[s->ptrB--] = x;
	return 0;
}

int PopA(STACK* s, int* x)
{
	if (s->ptrA <= 0) return -1; // ���ÿ� ������ ����
	*x = s->stk[--s->ptrA];
	return 0;
}

int PopB(STACK* s, int* x)
{
	if (s->ptrB >= s->max) return -1; // ���ÿ� ������ ����
	*x = s->stk[++s->ptrA];
	return 0;
}

int PeekA(const STACK* s, int* x)
{
	if (s->ptrA <= 0) return -1; // ���ÿ� ������ ����
	*x = s->stk[s->ptrA - 1];
	return 0;
}

int PeekB(const STACK* s, int* x)
{
	if (s->ptrB >= s->max) return -1; // ���ÿ� ������ ����
	*x = s->stk[s->ptrA  + 1];
	return 0;
}

void Print(const STACK* s)
{
	for (int i = 0; i < s->ptrA; i++) printf("stc_A[%d] = %d\n", i, s->stk[i]);
	printf("\n\n");
	for (int i = s->max - 1; i > s->ptrB; i--) printf("stc_B[%d] = %d\n", i, s->stk[i]);

}

void Clear(STACK* s)
{
	s->ptrA = 0;
	s->ptrB = s->max - 1;
}

void Delete(STACK* s)
{
	if (NULL != s->stk) free(s->stk);
	s->max = 0;
	s->ptrA = 0;
	s->ptrB = s->max - 1;
}

int getCapacity(const STACK* s)
{
	return s->max;
}

// ���ÿ� �׿��ִ� ������ ��
int getSizeA(const STACK* s)
{
	return s->ptrA;
}

int getSizeB(const STACK* s)
{
	return s->max - s->ptrB - 1;
}

int Search(const STACK* s, int x)
{
	for (int i = 0; i < s->max; i++) {
		if (s->stk[i] == x) return i;
	}
	return -1;

}