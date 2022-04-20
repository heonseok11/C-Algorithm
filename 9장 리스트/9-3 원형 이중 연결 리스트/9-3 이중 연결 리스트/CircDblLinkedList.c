#include <stdio.h>
#include <stdlib.h>
#include "CircDblLinkedList.h"

static Dnode* AllocDnode()
{
	return (Dnode*)calloc(1, sizeof(Dnode));
}

static void SetDnode(Dnode* n, const Member* x, const Dnode* prev, const Dnode* next)
{
	n->data = *x;
	n->prev = prev;
	n->next = next;
}

static int IsEmpty(const Dlist* list)
{
	return list->head->next == list->head;
}

/*--- 리스트를 초기화 ---*/
void Initialize(Dlist* list)
{
	Dnode* dummynode = AllocDnode();
	list->head = list->crnt = dummynode;
	dummynode->prev = dummynode->next = dummynode;
}

/*--- 주목노드의 데이터를 나타냄 ---*/
void PrintCurrent(const Dlist* list)
{
	if (IsEmpty(list))
		printf("선택한 노드가 없습니다.");
	else
		PrintMember(&list->crnt->data);
}

/*--- 주목노드의 데이터를 나타냄(줄바꿈 문자 붙임) ---*/
void PrintLnCurrent(const Dlist* list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- 함수 compare로 x와 같은 노드를 검색 ---*/
Dnode* search(Dlist* list, const Member* x, int compare(const Member* x, const Member* y))
{
	Dnode* ptr = list->head->next;
	while (ptr != list->head) {
		if (!compare(&ptr->data, x)) {
			list->crnt = ptr;
			return ptr;
		}
		ptr = ptr->next;
	}
	return NULL;
}

/*--- 모든 노드의 데이터를 리스트 순서로 나타냄 ---*/
void Print(const Dlist* list)
{
	if (IsEmpty(list))
		puts("노드가 없습니다.");
	else {
		Dnode* ptr = list->head->next; // 머리노드
		puts("[모두보기]");
		while (ptr != list->head) {
			PrintLnMember(&ptr->data);
			ptr = ptr->next;
		}
	}
}

/*--- 모든 노드의 데이터를 리스트 순서 거꾸로 나타냄 ---*/
void PrintReverse(const Dlist* list)
{
	if (IsEmpty(list))
		puts("노드가 없습니다.");
	else {
		Dnode* ptr = list->head->prev; // 꼬리노드
		puts("[모두보기]");
		while (ptr != list->head) {
			PrintLnMember(&ptr->data);
			ptr = ptr->prev;
		}
	}
}

/*--- 주목노드를 하나 뒤쪽으로 나아가도록 ---*/
int Next(Dlist* list)
{
	if (IsEmpty(list) || list->crnt->next == list->head)
		return 0; // 진행할 수 없음
	list->crnt = list->crnt->next;
	return 1;
}

/*--- 주목노드를 하나 앞쪽으로 되돌아가도록 ---*/
int Prev(Dlist* list)
{
	if (IsEmpty(list) || list->crnt->prev == list->head)
		return 0; // 진행할 수 없음
	list->crnt = list->crnt->prev;
	return 1;
}

/*--- p가 가리키는 노드 바로 뒤에 노드를 삽입 ---*/
void InsertAfter(Dlist* list, Dnode* p, const Member* x)
{
	Dnode* ptr = AllocDnode();
	Dnode* nxt = p->next;
	p->next = p->next->prev = ptr;
	SetDnode(ptr, x, p, nxt);
	list->crnt = ptr;
}

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(Dlist* list, const Member* x)
{
	InsertAfter(list, list->head, x);
}

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(Dlist* list, const Member* x)
{
	InsertAfter(list, list->head->prev, x);
}

/*--- p가 가리키는 노드를 삭제 ---*/
void Remove(Dlist* list, Dnode* p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	list->crnt = p->prev;
	free(p);
	if (list->crnt == list->head)
		list->crnt = list->head->next; // 주목하는 노드가 더미헤드이면 한칸 다음으로 옮김
}

/*--- 머리노드를 삭제 ---*/
void RemoveFront(Dlist* list)
{
	if (!IsEmpty(list))
		Remove(list, list->head->next);
}

/*--- 꼬리노드를 삭제 ---*/
void RemoveRear(Dlist* list)
{
	if (!IsEmpty(list))
		Remove(list, list->head->prev);
}

/*--- 주목노드를 삭제 ---*/
void RemoveCurrent(Dlist* list)
{
	if (list->crnt != list->head)
		Remove(list, list->crnt);
}

int MemberCompare(const Member* x, const Member* y)
{
	int a = x->no < y->no ? -1 : x->no > y->no ? 1 : 0;
	int b = strcmp(x->name, y->name);
	return (a + b) + a * b;
}

void Purge(Dlist* list, int compare(const Member* x, const Member* y))
{
	Dnode* ptr = list->head->next;

	while (ptr != list->head) {
		Dnode* ptr2 = ptr;
		while (ptr2->next != list->head) {
			if (!compare(&ptr->data, &ptr2->next->data)) {
				list->crnt = ptr2->next;
				RemoveCurrent(list);
			}
			else {
				ptr2 = ptr2->next;
			}
		}
		ptr = ptr->next;
	}

}

Dnode* Retrieve(Dlist* list, int n)
{

	if (n < 0) return NULL;
	Dnode* ptr = list->head->next;

	for (int i = 0; i < n; i++) {
		if (list->head == ptr) return NULL;
		ptr = ptr->next;
	}
	return ptr;

}

/*--- 더미노드를 제외한 모든 노드를 삭제 ---*/
void Clear(Dlist* list)
{
	while (!IsEmpty(list))
		RemoveFront(list);
}

/*--- 원형 이중연결 리스트의 뒤처리 ---*/
void Terminate(Dlist* list)
{
	Clear(list);
	free(list->head);
}