#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"


// 스택 초기화
int Initialize(IntStack* s, int max)
{
	s->ptr = 0;
	if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) { 
		// 배열 생성 실패
		s->max = 0;
		return -1;
	}
	else {
		s->max = max;
		return 0;
	}
}

// 스택에 데이터 X 푸시
int Push(IntStack* s, int x)
{
	if (s->ptr >= s->max) return -1; // 스택이 가득 참

	s->stk[s->ptr++] = x; 
	return 0; // 푸시 성공
}

// 스택에서 데이터를 팝하고 그 데이터를 포인터 X가 가리키는 곳에 저장
int Pop(IntStack* s, int* x)
{
	if (s->ptr <= 0) return -1; // 스택이 비어있음

	*x = s->stk[--s->ptr];
	return 0; // 팝 성공
}

// 스택에서 데이터를 피크
int Peek(const IntStack* s, int* x)
{
	if (s->ptr <= 0) return -1; // 스택이 비어있음

	*x = s->stk[s->ptr - 1]; // 스택 데이터 꼭대기를 엿봄
	return 0;
}

// 스택 비우기
void Clear(IntStack* s)
{
	s->ptr = 0;
}

// 스택 용량
int getCapacity(const IntStack* s)
{
	return s->max;
}

// 스택에 쌓여있는 데이터 수
int getSize(const IntStack* s)
{
	return s->ptr;
}

// 스택이 비어 있는가?
int IsEmpty(const IntStack* s)
{
	return s->ptr <= 0; // 스택이 비어있으면 1을 반환 아니면 0을 반환
}

// 스택이 가득 차 있는가?
int IsFull(const IntStack* s)
{
	return s->ptr >= s->max;
}

// 스택에서 검색
int Search(const IntStack* s, int x)
{
	for (int i = s->ptr - 1; i >= 0; i--) {
		if (s->stk[i] == x) return i;
	}
	return -1;
}

// 모든 데이터 출력
void Print(const IntStack* s)
{
	for (int i = 0; i < s->ptr; i++) printf("stk[%d] = %d\n",i, s->stk[i]);
	
}

// 스택 종료
void Terminate(IntStack* s)
{
	if (s->stk != NULL) free(s->stk); // 배열 삭제
	s->max = s->ptr = 0;
}