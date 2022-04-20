#include <stdio.h>
#include <stdlib.h>
#include "ArrayLinkedList.h"
#include "Member.h"

// 삽입할 레코드의 인덱스를 구한 다음 반환
static Index GetIndex(List* list)
{
	if (list->deleted == null) // 삭제할 레코드가 없는 경우
		return ++(list->max);
	else {
		Index rec = list->deleted;
		list->deleted = list->n[rec].Dnext; // 프리리스트의 머리노드를 그 다음 프리리스트로 변경
		return rec;
	}
}

// 지정된 레코드를 프리 리스트의 머리노드에 등록
static void DeleteIndex(List* list, Index idx)
{
	if (list->deleted == null) { // 삭제할 레코드가 없는 경우
		list->deleted = idx;
		list->n[idx].Dnext = null;
	}
	else {
		Index ptr = list->deleted;
		list->deleted = idx;
		list->n[idx].Dnext = ptr;
	}
}

// n이 가리키는 노드의 각 멤버에 값을 설정
static void SetNode(Node* n, const Member* x, Index next)
{
	n->data = *x;
	n->next = next;
}

/*--- 선형 리스트를 초기화(가장 큰 요솟수는 size) ---*/
void Initialize(List* list, int size)
{
	list->n = (int*)calloc(size, sizeof(Node));
	list->head = null;
	list->crnt = null;
	list->max = null;
	list->deleted = null;
}

/*--- 함수 compare에 의해 x와 같은 것으로 판단되는 노드를 검색 ---*/
Index search(List* list, const Member* x, int compare(const Member* x, const Member* y))
{
	Index ptr = list->head;
	while (ptr != null) {
		if (compare(&list->n[ptr].data, x) == 0) {
			list->crnt = ptr;
			return ptr;
		}
		ptr = list->n[ptr].next;
	}
	return null;
}

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(List* list, const Member* x)
{
	Index ptr = list->head; // 기존의 head 인덱스 값을 ptr에 대입
	list->head = list->crnt = GetIndex(list);
	SetNode(&list->n[list->head], x, ptr); 
}

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(List* list, const Member* x)
{
	if (list->head == null)
		InsertFront(list, x);
	else {
		Index ptr = list->head;
		while (list->n[ptr].next != null)
			ptr = list->n[ptr].next;
		list->n[ptr].next = list->crnt = GetIndex(list);
		SetNode(&list->n[list->n[ptr].next], x, null);
	}
}

/*--- 머리노드를 삭제 ---*/
void RemoveFront(List* list)
{
	if (list->head != null) {
		Index ptr = list->n[list->head].next;
		DeleteIndex(list, list->head);
		list->head = list->crnt = ptr;
	}
}

/*--- 꼬리노드를 삭제 ---*/
void RemoveRear(List* list)
{
	if (list->head == null) {
		// 노드가 1개만 있으면 머리 노드를 삭제
		if (list->n[list->head].next == null)
			RemoveFront(list);
		else {
			Index ptr = list->head;
			Index pre;
			while (list->n[ptr].next != null) {
				pre = ptr;
				ptr = list->n[ptr].next;
			}
			list->n[pre].next = null;
			DeleteIndex(list, ptr);
			list->crnt = pre;
		}
	}
}

/*--- 주목노드를 삭제 ---*/
void RemoveCurrent(List* list)
{
	if (list->head != null) {
		if (list->crnt == list->head)
			RemoveFront(list);
		else {
			Index ptr = list->head;
			while (list->n[ptr].next != list->crnt)
				ptr = list->n[ptr].next;
			list->n[ptr].next = list->n[list->crnt].next;
			DeleteIndex(list, list->crnt);
			list->crnt = ptr;
		}
	}
}

/*--- 모든 노드를 삭제 ---*/
void Clear(List* list)
{
	while (list->head != null)
		RemoveFront(list);
	list->crnt = null;
}

/*--- 주목노드의 데이터를 나타냄 ---*/
void PrintCurrent(const List* list)
{
	if (list->crnt == null)
		puts("선택한 노드가 없습니다!");
	else
		PrintMember(&list->n[list->crnt].data);
}

/*--- 주목노드의 데이터를 나타냄(줄바꿈 문자 붙임) ---*/
void PrintLnCurrent(const List* list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- 모든 노드의 데이터를 나타냄 ---*/
void Print(const List* list)
{
	if (list->head == null)
		puts("노드가 없습니다.");
	else {
		Index ptr = list->head;
		puts("[모두보기]");
		while (ptr != null) {
			PrintLnMember(&list->n[ptr].data);
			ptr = list->n[ptr].next;
		}
	}
}

int MemberCompare(const Member* x, const Member* y)
{
	int a = x->no < y->no ? -1 : x->no > y->no ? 1 : 0;
	int b = strcmp(x->name, y->name);
	return (a + b) + a * b;
}

void Purge(List* list, int compare(const Member* x, const Member* y))
{
	Index ptr = list->head;

	while (ptr != null) {
		Index ptr2 = ptr;
		while (list->n[ptr2].next != null) { 
			if (!compare(&list->n[ptr].data, &list->n[list->n[ptr2].next])) {
				list->crnt = list->n[ptr2].next;
				RemoveCurrent(list);
			}
			else {
				ptr2 = list->n[ptr2].next;
			}
		}
		ptr = list->n[ptr].next;
	}
	
}

Index Retrieve(List* list, int n)
{

	if (n < 0) return null;
	Index ptr = list->head;

	for (int i = 0; i < n; i++) {
		if (null == ptr) return null;
		ptr = list->n[ptr].next;
	}
	return ptr;

}

/*--- 선형 리스트의 뒤처리 ---*/
void Terminate(List* list)
{
	Clear(list);
	free(list->n);
}