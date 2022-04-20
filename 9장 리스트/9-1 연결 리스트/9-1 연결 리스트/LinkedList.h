#ifndef ___LinkedList
#define ___LinkedList

#include "Member.h"

typedef struct __node {
	Member data;
	struct __node* p_next;
}Node;

typedef struct {
	Node* head; // head 노드 포인터
	Node* crnt; // 선택한 노드의 포인터
}List;

void Initialize(List* list);

// 함수 compare로 x와 같은 노드를 검색
Node* search(List* list, const Member* x, int compare(const Member* x, const Member* y));

// 머리에 노드 삽입
void InsertFront(List* list, const Member* x);

// 꼬리에 노드 삽입
void InsertRear(List* list, const Member* x);

// 머리 노드 삭제
void RemoveFront(List* list);

// 꼬리 노드 삭제
void RemoveRear(List* list);

// 선택한 노드를 삭제
void RemoveCurrent(List* list);

// 모든 노드 삭제
void Clear(List* list);

// 선택한 노드의 데이터 출력
void PrintCurrent(const List* list);

// 선택한 노드의 데이터 출력 (줄바꿈 문자 포함)
void PrintLnCurrent(const List* list);

// 모든 노드의 데이터를 리스트 순서대로 출력
void Print(const List* list);

int MemberCompare(const Member* x, const Member* y);

// 중복 노드 삭제
void Purge(List* list, int compare(const Member* x, const Member* y));

// 머리부터 n개 뒤의 노드에 대한 포인터 반환
Node* Retrieve(List* list, int n);

void Terminate(List* list);

#endif