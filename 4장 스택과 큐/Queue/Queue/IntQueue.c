#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

int Initialize(QUE* q, int max)
{
	q->num = q->front = q->rear = 0;
	if ((q->que = (int*)calloc(max, sizeof(int))) == NULL) {
		q->max = 0;
		return -1;
	}
	q->max = max;
	return 0;
}

int Enque(QUE* q, int x)
{
	if (q->num == q->max) return -1; // ť�� ������
	else {
		q->num++;
		q->que[q->rear++] = x;
		if (q->rear == q->max) q->rear = 0; // ���� �迭�� ���� ������ ����Ű�� �ǹǷ� �迭�� ó���� 0���� ���� ��
		return 0;
	}
}

int Deque(QUE* q, int* x)
{
	if (q->num <= 0) return -1; // ť�� ��� ����
	else {
		q->num--;
		*x = q->que[q->front++];
		if (q->front == q->max) q->front = 0; //Enque �Լ��� �������� ����
		return 0;
	}
}

int Peek(QUE* q, int* x)
{
	if (q->num <= 0) return -1; // ť�� ��� ����
	*x = q->que[q->front];
	return 0;
}

void Clear(QUE* q)
{
	q->num = q->front = q->rear = 0;
}

int Capacity(const QUE* q)
{
	return q->max;
}

int Size(const QUE* q)
{
	return q->num;
}

int IsEmpty(const QUE* q)
{
	return q->num <= 0;
}

int IsFull(const QUE* q)
{
	return q->num >= q->max;
}

int Search(const QUE* q, int x)
{
	int i, idx;
	for (i = 0; i < q->num; i++) {
		if (q->que[idx = (i + q->front) % q->max] == x) return idx;
	}
	return -1;
}

int Search2(const QUE* q, int x)
{
	int i, idx;
	for (i = 0; i < q->num; i++) {
		if (q->que[idx = (i + q->front) % q->max] == x) {
			if (idx >= q->front) return idx - q->front;
			else return idx + q->max - q->front;
			    // if (q->que[(i + q->front) % q->max] == x) return i;
				// �ᱹ i�� ��ȯ�ϸ� �ȴ�...
		}
	}
	return -1;
}

void Print(const QUE* q)
{
	for (int i = 0; i < q->num; i++) 
		printf("que[%d] = %d\n", (i + q->front) % q->max, q->que[(i + q->front) % q->max]);
}

void Terminate(QUE* q)
{
	if (q->que != NULL) free(q->que);
	q->max = q->num = q->front = q->rear = 0;
}