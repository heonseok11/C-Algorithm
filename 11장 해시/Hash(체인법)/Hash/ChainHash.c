#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ChainHash.h"

// 해시함수 (key)의 해시값을 반환
static int hash(int key, int size)
{
	return key % size;
}

// 노드의 각 멤버에 값을 설정
static void SetNode(Node* n, const Member* x, const Node* next)
{
	n->data = *x;
	n->next = next;
}

/*--- 해시 테이블 초기화 ---*/
int Initialize(ChainHash* h, int size)
{
	if ((h->table = calloc(size, sizeof(Node*))) == NULL) {
		h->size = 0;
		return 0;
	}

	h->size = size;
	for (int i = 0; i < size; i++)
		h->table[i] = NULL;
	return 1;
}

/*--- 검색 ---*/
Node* Search(const ChainHash* h, const Member* x)
{
	int key = hash(x->no, h->size);
	Node* p = h->table[key];

	while (NULL != p) {
		if (p->data.no == x->no)
			return p;
		p = p->next;
	}

	return NULL;
}

/*--- 데이터 추가 ---*/
int Add(ChainHash* h, const Member* x)
{
	int key = hash(x->no, h->size);
	Node* p = h->table[key];

	Node* temp;
	while (NULL != p) {
		if (p->data.no == x->no) // 이미 등록된 키
			return 1;
		p = p->next;
	}

	if ((temp = calloc(1, sizeof(Node))) == NULL)
		return 2;

	SetNode(temp, x, h->table[key]);
	h->table[key] = temp;
	return 0;
}

/*--- 데이터 삭제 ---*/
int Remove(ChainHash* h, const Member* x)
{
	int key = hash(x->no, h->size);
	Node* p = h->table[key];	// 현재 선택한 노드
	Node** pp = &h->table[key]; // 현재 선택한 노드에 대한 포인터
	while (NULL != p) {
		if (p->data.no == x->no) {
			*pp = p->next;
			free(p);
			return 0;
		}
		pp = &p->next;
		p = p->next;
	}
	return 1; // 삭제 실패
}

/*--- 해시 테이블 덤프(dump) ---*/
void Dump(const ChainHash* h)
{
	for (int i = 0; i < h->size; i++) {
		Node* p = h->table[i];
		printf("%02d  ", i);
		while (NULL != p) {
			printf("-> %d : (%s)  ", p->data.no, p->data.name);
			p = p->next;
		}
		putchar('\n');
	}
}

/*--- 모든 데이터 삭제 ---*/
void Clear(ChainHash* h)
{
	for (int i = 0; i < h->size; i++) {
		Node* p = h->table[i];
		while (NULL != p) {
			Node* next = p->next;
			free(p);
			p = next;
		}
		h->table[i] = NULL;
	}
}

/*--- 해시 테이블 종료 ---*/
void Terminate(ChainHash* h)
{
	Clear(h);
	free(h->table);
	h->size = 0;
}