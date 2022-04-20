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
	n->data = *x;		// ������
	n->left = left;		// ���� �ڽĳ�忡 ���� ������
	n->right = right;	// ������ �ڽĳ�忡 ���� ������
}

BinNode* Search(BinNode* p, const Member* x)
{
	int cond;
	if (NULL == p)
		return NULL;
	else if ((cond = MemberNoCmp(x, &p->data)) == 0)
		return p; // �˻�����
	else if (cond < 0)
		Search(p->left, x); // ���� ����Ʈ���� �̵�
	else
		Search(p->right, x); // ������ ����Ʈ���� �̵�
}

BinNode* Add(BinNode* p, const Member* x)
{
	int cond;
	if (NULL == p) {
		p = AllocBinNode();
		SetBinNode(p, x, NULL, NULL);
	}
	else if ((cond = MemberNoCmp(x, &p->data)) == 0)
		printf("[����] %d�� �̹� ��ϵǾ� �ֽ��ϴ�.\n", x->no);
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
			printf("[����] %d�� �̹� ��ϵǾ� ���� �ʽ��ϴ�.\n", x->no);
			return -1;
		}
		else if ((cond = MemberNoCmp(x, &(*p)->data)) == 0)
			break; // �����ϰ��� �ϴ� ��� �˻�����
		else if (cond < 0)
			p = &((*p)->left);
		else
			p = &((*p)->right);
	}

	if ((*p)->left == NULL) // ������ ����� ���� �ڽ��� �����Ƿ� ������ �ڽ��� ������ ����� ��ġ�� ������
		next = (*p)->right;
	else { // ������ ����� ���� ���� Ʈ������ Ű ���� ���� ū ��� �˻�
		left = &((*p)->left);
		while ((*left)->right != NULL) // ������ ����� ���� �ڽ� ���� �̵��ؼ� ���� ū ���� ã������ ���������� ��� ������
			left = &(*left)->right;
		next = *left;
		*left = (*left)->left; // ������ ���� �ű� ����� ��ġ�� �� ����� ���� �ڽ� ��带 �÷��� Ʈ���� ä��
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
	// ���� ��ȸ ������� Ʈ�� �˻� => �������� ���
	if (NULL != p) {
		PrintTree(p->left);
		PrintLnMember(&p->data);
		PrintTree(p->right);
	}
}

void FreeTree(BinNode* p)
{
	// ���� ��ȸ ������� Ʈ�� ����
	if (NULL != p) {
		FreeTree(p->left);
		FreeTree(p->right);
		free(p);
	}
}

// Q1 ������������ ���
void PrintTreeReverse(const BinNode* p)
{
	if (NULL != p) {
		PrintTreeReverse(p->right);
		PrintLnMember(&p->data);
		PrintTreeReverse(p->left);
	}
}

// Q3 ���� ���� Ű ���� ���� ��� ������ ��ȯ
BinNode* GetMinNode(const BinNode* p) {

	if (NULL != p) {
		while (NULL != p->left)
			p = p->left;
		return p;
	}
	else return NULL;
}

// Q3 ���� ū Ű ���� ���� ��� ������ ��ȯ
BinNode* GetMaxNode(const BinNode* p) {
	if (NULL != p) {
		while (NULL != p->right)
			p = p->right;
		return p;
	}
	else return NULL;
}