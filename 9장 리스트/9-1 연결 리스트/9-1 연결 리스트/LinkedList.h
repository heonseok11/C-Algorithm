#ifndef ___LinkedList
#define ___LinkedList

#include "Member.h"

typedef struct __node {
	Member data;
	struct __node* p_next;
}Node;

typedef struct {
	Node* head; // head ��� ������
	Node* crnt; // ������ ����� ������
}List;

void Initialize(List* list);

// �Լ� compare�� x�� ���� ��带 �˻�
Node* search(List* list, const Member* x, int compare(const Member* x, const Member* y));

// �Ӹ��� ��� ����
void InsertFront(List* list, const Member* x);

// ������ ��� ����
void InsertRear(List* list, const Member* x);

// �Ӹ� ��� ����
void RemoveFront(List* list);

// ���� ��� ����
void RemoveRear(List* list);

// ������ ��带 ����
void RemoveCurrent(List* list);

// ��� ��� ����
void Clear(List* list);

// ������ ����� ������ ���
void PrintCurrent(const List* list);

// ������ ����� ������ ��� (�ٹٲ� ���� ����)
void PrintLnCurrent(const List* list);

// ��� ����� �����͸� ����Ʈ ������� ���
void Print(const List* list);

int MemberCompare(const Member* x, const Member* y);

// �ߺ� ��� ����
void Purge(List* list, int compare(const Member* x, const Member* y));

// �Ӹ����� n�� ���� ��忡 ���� ������ ��ȯ
Node* Retrieve(List* list, int n);

void Terminate(List* list);

#endif