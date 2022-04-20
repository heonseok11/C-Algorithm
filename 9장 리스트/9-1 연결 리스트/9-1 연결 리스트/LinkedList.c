#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

static Node* AllocNode()
{
	return (Node*)calloc(1, sizeof(Node));
}

// ��� n�� �� ����� ���� ����
static void SetNode(Node* n, const Member* x, const Node* next)
{
	n->data = *x;		// ������ 
	n->p_next = next;	// ���� ������
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
		if (compare(&ptr->data, x) == 0) { // Ű ���� ���� ���
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
	SetNode(list->head, x, ptr); // ���� head�� ���� ���� head�� p_next ������ �������
}

void InsertRear(List *list, const Member *x)
{
	if (NULL != list->head) {
		Node* ptr = list->head;
		while (NULL != ptr->p_next) // ������(����) ���� �̵�
			ptr = ptr->p_next;
		ptr->p_next = list->crnt = AllocNode();
		SetNode(ptr->p_next, x, NULL);
	}
	else { // ����ִ� ���
		InsertFront(list, x); // �Ӹ��� ����
	}
}

void RemoveFront(List* list) 
{
	if (NULL != list->head) {
		Node* ptr = list->head->p_next;
		free(list->head); // �Ӹ���� ����
		list->head = list->crnt = ptr;
	}
}

void RemoveRear(List* list)
{
	if (NULL != list->head) {
		if (list->head->p_next == NULL) // ��尡 �Ѱ��� �ִ� ���
			RemoveFront(list);
		else {
			Node* ptr = list->head;
			Node* pre;
			while (ptr->p_next != NULL) {
				pre = ptr; // �������� �ι�°�� ��� ����
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
			RemoveFront(list); // �Ӹ� ��带 ������ ���¶�� �Ӹ� ��带 ����
		else {
			Node* ptr = list->head;
			while (ptr->p_next != list->crnt) // ���� ����� ���� ��尡 crnt �̸� ����
				ptr = ptr->p_next;
			ptr->p_next = list->crnt->p_next;
			free(list->crnt);
			list->crnt = ptr;
		}
	}
}

void Clear(List* list)
{
	while (list->head != NULL) // ��尡 NULL�� ������ �ݺ�
		RemoveFront(list); 
	list->crnt = NULL;
}

void PrintCurrent(const List* list)
{
	if (NULL == list->crnt)
		printf("������ ��尡 �����ϴ�.");
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
		puts("��尡 �����ϴ�.");
	else {
		Node* ptr = list->head;
		puts("<��κ���>");
		while (ptr != NULL) {
			PrintLnMember(&ptr->data);
			ptr = ptr->p_next;
		}
	}
}

// �� �Լ� ���� ��� ������� �𸣰���...
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
		while (pre->p_next != NULL) { // pre(ptr)->p_next �� NULL �ƴϸ� ����
			Node* ptr2 = pre->p_next; // ptr2�� ptr�� ���� ��带 ����Ŵ
			if (!compare(&ptr->data, &ptr2->data)) { // ptr�� ptr2�� ��� ������ ���� ��� ptr2�� ����
				pre->p_next = ptr2->p_next; // pre(ptr)->p_next�� ptr2�� ������� �ּҸ� ����
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