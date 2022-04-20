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

/*--- ����Ʈ�� �ʱ�ȭ ---*/
void Initialize(Dlist* list)
{
	Dnode* dummynode = AllocDnode();
	list->head = list->crnt = dummynode;
	dummynode->prev = dummynode->next = dummynode;
}

/*--- �ָ����� �����͸� ��Ÿ�� ---*/
void PrintCurrent(const Dlist* list)
{
	if (IsEmpty(list))
		printf("������ ��尡 �����ϴ�.");
	else
		PrintMember(&list->crnt->data);
}

/*--- �ָ����� �����͸� ��Ÿ��(�ٹٲ� ���� ����) ---*/
void PrintLnCurrent(const Dlist* list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- �Լ� compare�� x�� ���� ��带 �˻� ---*/
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

/*--- ��� ����� �����͸� ����Ʈ ������ ��Ÿ�� ---*/
void Print(const Dlist* list)
{
	if (IsEmpty(list))
		puts("��尡 �����ϴ�.");
	else {
		Dnode* ptr = list->head->next; // �Ӹ����
		puts("[��κ���]");
		while (ptr != list->head) {
			PrintLnMember(&ptr->data);
			ptr = ptr->next;
		}
	}
}

/*--- ��� ����� �����͸� ����Ʈ ���� �Ųٷ� ��Ÿ�� ---*/
void PrintReverse(const Dlist* list)
{
	if (IsEmpty(list))
		puts("��尡 �����ϴ�.");
	else {
		Dnode* ptr = list->head->prev; // �������
		puts("[��κ���]");
		while (ptr != list->head) {
			PrintLnMember(&ptr->data);
			ptr = ptr->prev;
		}
	}
}

/*--- �ָ��带 �ϳ� �������� ���ư����� ---*/
int Next(Dlist* list)
{
	if (IsEmpty(list) || list->crnt->next == list->head)
		return 0; // ������ �� ����
	list->crnt = list->crnt->next;
	return 1;
}

/*--- �ָ��带 �ϳ� �������� �ǵ��ư����� ---*/
int Prev(Dlist* list)
{
	if (IsEmpty(list) || list->crnt->prev == list->head)
		return 0; // ������ �� ����
	list->crnt = list->crnt->prev;
	return 1;
}

/*--- p�� ����Ű�� ��� �ٷ� �ڿ� ��带 ���� ---*/
void InsertAfter(Dlist* list, Dnode* p, const Member* x)
{
	Dnode* ptr = AllocDnode();
	Dnode* nxt = p->next;
	p->next = p->next->prev = ptr;
	SetDnode(ptr, x, p, nxt);
	list->crnt = ptr;
}

/*--- �Ӹ��� ��带 ���� ---*/
void InsertFront(Dlist* list, const Member* x)
{
	InsertAfter(list, list->head, x);
}

/*--- ������ ��带 ���� ---*/
void InsertRear(Dlist* list, const Member* x)
{
	InsertAfter(list, list->head->prev, x);
}

/*--- p�� ����Ű�� ��带 ���� ---*/
void Remove(Dlist* list, Dnode* p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	list->crnt = p->prev;
	free(p);
	if (list->crnt == list->head)
		list->crnt = list->head->next; // �ָ��ϴ� ��尡 ��������̸� ��ĭ �������� �ű�
}

/*--- �Ӹ���带 ���� ---*/
void RemoveFront(Dlist* list)
{
	if (!IsEmpty(list))
		Remove(list, list->head->next);
}

/*--- ������带 ���� ---*/
void RemoveRear(Dlist* list)
{
	if (!IsEmpty(list))
		Remove(list, list->head->prev);
}

/*--- �ָ��带 ���� ---*/
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

/*--- ���̳�带 ������ ��� ��带 ���� ---*/
void Clear(Dlist* list)
{
	while (!IsEmpty(list))
		RemoveFront(list);
}

/*--- ���� ���߿��� ����Ʈ�� ��ó�� ---*/
void Terminate(Dlist* list)
{
	Clear(list);
	free(list->head);
}