#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

static Node* AllocNode()
{
	return (Node*)calloc(1, sizeof(Node));
}

// 노드 n의 각 멤버에 값을 설정
static void SetNode(Node* n, const Member* x, const Node* next)
{
	n->data = *x;		// 데이터 
	n->p_next = next;	// 뒤쪽 포인터
}

void Initialize(List* list)
{
	list->head = NULL;
	list->crnt = NULL;
}

Node* search(List* list, const Member* x, int compare(const Member* x, const Member* y))
{
	Node* ptr = list->head;
	while (NULL != ptr) {
		if (compare(&ptr->data, x) == 0) { // 키 값이 같은 경우
			list->crnt = ptr;
			return ptr;
		}
		ptr = ptr->p_next;
	}
	return NULL;
} 

void InsertFront(List* list, const Member* x)
{
	Node* ptr = list->head;
	list->head = list->crnt = AllocNode();
	SetNode(list->head, x, ptr); // 원래 head를 새로 만든 head의 p_next 값으로 집어넣음
}

void InsertRear(List *list, const Member *x)
{
	if (NULL != list->head) {
		Node* ptr = list->head;
		while (NULL != ptr->p_next) // 마지막(꼬리) 노드로 이동
			ptr = ptr->p_next;
		ptr->p_next = list->crnt = AllocNode();
		SetNode(ptr->p_next, x, NULL);
	}
	else { // 비어있는 경우
		InsertFront(list, x); // 머리에 삽입
	}
}

void RemoveFront(List* list) 
{
	if (NULL != list->head) {
		Node* ptr = list->head->p_next;
		free(list->head); // 머리노드 해제
		list->head = list->crnt = ptr;
	}
}

void RemoveRear(List* list)
{
	if (NULL != list->head) {
		if (list->head->p_next == NULL) // 노드가 한개만 있는 경우
			RemoveFront(list);
		else {
			Node* ptr = list->head;
			Node* pre;
			while (ptr->p_next != NULL) {
				pre = ptr; // 꼬리에서 두번째의 노드 저장
				ptr = ptr->p_next;
			}
			pre->p_next = NULL;
			free(ptr);
			list->crnt = pre;
		}
	}
}

void RemoveCurrent(List* list)
{
	if (list->head != NULL) {
		if (list->head == list->crnt) 
			RemoveFront(list); // 머리 노드를 선택한 상태라면 머리 노드를 삭제
		else {
			Node* ptr = list->head;
			while (ptr->p_next != list->crnt) // 현재 노드의 다음 노드가 crnt 이면 종료
				ptr = ptr->p_next;
			ptr->p_next = list->crnt->p_next;
			free(list->crnt);
			list->crnt = ptr;
		}
	}
}

void Clear(List* list)
{
	while (list->head != NULL) // 헤드가 NULL일 때까지 반복
		RemoveFront(list); 
	list->crnt = NULL;
}

void PrintCurrent(const List* list)
{
	if (NULL == list->crnt)
		printf("선택한 노드가 없습니다.");
	else
		PrintMember(&list->crnt->data);
}

void PrintLnCurrent(const List* list)
{
	PrintCurrent(list);
	putchar('\n');
}

void Print(const List* list)
{
	if (NULL == list->head)
		puts("노드가 없습니다.");
	else {
		Node* ptr = list->head;
		puts("<모두보기>");
		while (ptr != NULL) {
			PrintLnMember(&ptr->data);
			ptr = ptr->p_next;
		}
	}
}

// 이 함수 아직 어떻게 만드는지 모르겠음...
int MemberCompare(const Member* x, const Member* y)
{
	int a = x->no < y->no ? -1 : x->no > y->no ? 1 : 0;
	int b = strcmp(x->name, y->name);
	return (a + b) + a * b;
}

void Purge(List* list, int compare(const Member* x, const Member* y))
{
	Node* ptr = list->head;
	        
	while (ptr != NULL) {
		Node* pre = ptr;
		while (pre->p_next != NULL) { // pre(ptr)->p_next 가 NULL 아니면 진행
			Node* ptr2 = pre->p_next; // ptr2는 ptr의 다음 노드를 가리킴
			if (!compare(&ptr->data, &ptr2->data)) { // ptr과 ptr2의 노드 내용이 같을 경우 ptr2를 해제
				pre->p_next = ptr2->p_next; // pre(ptr)->p_next에 ptr2의 다음노드 주소를 삽입
				free(ptr2);
			}
			else {
				pre = ptr2; // pre = pre->p_next;
			}	
		}
		ptr = ptr->p_next;
	}
	list->crnt = list->head;
}

Node* Retrieve(List* list, int n)
{

	if (n < 0) return NULL;
	Node* ptr = list->head;

	for (int i = 0; i < n; i++) {
		if (NULL == ptr) return NULL;
		ptr = ptr->p_next;
	}
	return ptr;
	
}

void Terminate(List* list)
{
	Clear(list);
}