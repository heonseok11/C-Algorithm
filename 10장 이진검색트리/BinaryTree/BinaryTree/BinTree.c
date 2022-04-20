#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "BinTree.h"

static BinNode* AllocBinNode()
{
	return (BinNode*)calloc(1, sizeof(BinNode));
}

static void SetBinNode(BinNode* n, const Member* x, const BinNode* left, BinNode* right)
{
	n->data = *x;		// 데이터
	n->left = left;		// 왼쪽 자식노드에 대한 포인터
	n->right = right;	// 오른쪽 자식노드에 대한 포인터
}

BinNode* Search(BinNode* p, const Member* x)
{
	int cond;
	if (NULL == p)
		return NULL;
	else if ((cond = MemberNoCmp(x, &p->data)) == 0)
		return p; // 검색성공
	else if (cond < 0)
		Search(p->left, x); // 왼쪽 서브트리로 이동
	else
		Search(p->right, x); // 오른쪽 서브트리로 이동
}

BinNode* Add(BinNode* p, const Member* x)
{
	int cond;
	if (NULL == p) {
		p = AllocBinNode();
		SetBinNode(p, x, NULL, NULL);
	}
	else if ((cond = MemberNoCmp(x, &p->data)) == 0)
		printf("[오류] %d는 이미 등록되어 있습니다.\n", x->no);
	else if (cond < 0)
		p->left = Add(p->left, x);
	else
		p->right = Add(p->right, x);

	return p;
}

int Remove(BinNode** root, const Member* x)
{
	BinNode* next, * temp;
	BinNode** left;
	BinNode** p = root;

	while (1) {
		int cond;
		if (NULL == *p) {
			printf("[오류] %d는 이미 등록되어 있지 않습니다.\n", x->no);
			return -1;
		}
		else if ((cond = MemberNoCmp(x, &(*p)->data)) == 0)
			break; // 삭제하고자 하는 노드 검색성공
		else if (cond < 0)
			p = &((*p)->left);
		else
			p = &((*p)->right);
	}

	if ((*p)->left == NULL) // 삭제할 노드의 왼쪽 자식이 없으므로 오른쪽 자식이 삭제할 노드의 위치를 차지함
		next = (*p)->right;
	else { // 삭제할 노드의 왼쪽 서브 트리에서 키 값이 가장 큰 노드 검색
		left = &((*p)->left);
		while ((*left)->right != NULL) // 삭제할 노드의 왼쪽 자식 노드로 이동해서 가장 큰 값을 찾기위해 오른쪽으로 계속 내려감
			left = &(*left)->right;
		next = *left;
		*left = (*left)->left; // 삭제할 노드로 옮길 노드의 위치에 그 노드의 왼쪽 자식 노드를 올려서 트리를 채움
		next->left = (*p)->left;
		next->right = (*p)->right;
	}

	temp = *p;
	*p = next;
	free(temp);

	return 0;
}

void PrintTree(const BinNode* p)
{
	// 중위 순회 방법으로 트리 검색 => 오름차순 출력
	if (NULL != p) {
		PrintTree(p->left);
		PrintLnMember(&p->data);
		PrintTree(p->right);
	}
}

void FreeTree(BinNode* p)
{
	// 후위 순회 방법으로 트리 삭제
	if (NULL != p) {
		FreeTree(p->left);
		FreeTree(p->right);
		free(p);
	}
}

// Q1 내림차순으로 출력
void PrintTreeReverse(const BinNode* p)
{
	if (NULL != p) {
		PrintTreeReverse(p->right);
		PrintLnMember(&p->data);
		PrintTreeReverse(p->left);
	}
}

// Q3 가장 작은 키 값을 갖는 노드 포인터 반환
BinNode* GetMinNode(const BinNode* p) {

	if (NULL != p) {
		while (NULL != p->left)
			p = p->left;
		return p;
	}
	else return NULL;
}

// Q3 가장 큰 키 값을 갖는 노드 포인터 반환
BinNode* GetMaxNode(const BinNode* p) {
	if (NULL != p) {
		while (NULL != p->right)
			p = p->right;
		return p;
	}
	else return NULL;
}