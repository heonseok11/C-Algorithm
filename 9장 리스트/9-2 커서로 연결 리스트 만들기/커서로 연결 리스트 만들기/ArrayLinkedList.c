#include <stdio.h>
#include <stdlib.h>
#include "ArrayLinkedList.h"
#include "Member.h"

// ������ ���ڵ��� �ε����� ���� ���� ��ȯ
static Index GetIndex(List* list)
{
	if (list->deleted == null) // ������ ���ڵ尡 ���� ���
		return ++(list->max);
	else {
		Index rec = list->deleted;
		list->deleted = list->n[rec].Dnext; // ��������Ʈ�� �Ӹ���带 �� ���� ��������Ʈ�� ����
		return rec;
	}
}

// ������ ���ڵ带 ���� ����Ʈ�� �Ӹ���忡 ���
static void DeleteIndex(List* list, Index idx)
{
	if (list->deleted == null) { // ������ ���ڵ尡 ���� ���
		list->deleted = idx;
		list->n[idx].Dnext = null;
	}
	else {
		Index ptr = list->deleted;
		list->deleted = idx;
		list->n[idx].Dnext = ptr;
	}
}

// n�� ����Ű�� ����� �� ����� ���� ����
static void SetNode(Node* n, const Member* x, Index next)
{
	n->data = *x;
	n->next = next;
}

/*--- ���� ����Ʈ�� �ʱ�ȭ(���� ū ��ڼ��� size) ---*/
void Initialize(List* list, int size)
{
	list->n = (int*)calloc(size, sizeof(Node));
	list->head = null;
	list->crnt = null;
	list->max = null;
	list->deleted = null;
}

/*--- �Լ� compare�� ���� x�� ���� ������ �ǴܵǴ� ��带 �˻� ---*/
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

/*--- �Ӹ��� ��带 ���� ---*/
void InsertFront(List* list, const Member* x)
{
	Index ptr = list->head; // ������ head �ε��� ���� ptr�� ����
	list->head = list->crnt = GetIndex(list);
	SetNode(&list->n[list->head], x, ptr); 
}

/*--- ������ ��带 ���� ---*/
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

/*--- �Ӹ���带 ���� ---*/
void RemoveFront(List* list)
{
	if (list->head != null) {
		Index ptr = list->n[list->head].next;
		DeleteIndex(list, list->head);
		list->head = list->crnt = ptr;
	}
}

/*--- ������带 ���� ---*/
void RemoveRear(List* list)
{
	if (list->head == null) {
		// ��尡 1���� ������ �Ӹ� ��带 ����
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

/*--- �ָ��带 ���� ---*/
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

/*--- ��� ��带 ���� ---*/
void Clear(List* list)
{
	while (list->head != null)
		RemoveFront(list);
	list->crnt = null;
}

/*--- �ָ����� �����͸� ��Ÿ�� ---*/
void PrintCurrent(const List* list)
{
	if (list->crnt == null)
		puts("������ ��尡 �����ϴ�!");
	else
		PrintMember(&list->n[list->crnt].data);
}

/*--- �ָ����� �����͸� ��Ÿ��(�ٹٲ� ���� ����) ---*/
void PrintLnCurrent(const List* list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- ��� ����� �����͸� ��Ÿ�� ---*/
void Print(const List* list)
{
	if (list->head == null)
		puts("��尡 �����ϴ�.");
	else {
		Index ptr = list->head;
		puts("[��κ���]");
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

/*--- ���� ����Ʈ�� ��ó�� ---*/
void Terminate(List* list)
{
	Clear(list);
	free(list->n);
}