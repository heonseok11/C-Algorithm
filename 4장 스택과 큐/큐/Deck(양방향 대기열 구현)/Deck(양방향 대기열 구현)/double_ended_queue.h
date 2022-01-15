#ifndef ___IntQueue
#define ___IntQueue

// ť�� �����ϴ� ����ü
typedef struct {
	int max;	//ť�� �ִ� �뷮
	int num;	//������ ��� ����
	int front;	//����Ʈ
	int rear;	//����
	int* que;	//ť�� �� �� ��ҿ� ���� ������
}QUE;

// ť �ʱ�ȭ
int Initialize(QUE* q, int max);

// ť�� �����͸� ��ť
int Enque(QUE* q, int x);

// ť���� �����͸� ��ť
int Deque(QUE* q, int* x);

// ť���� �����͸� ��ũ
int Peek(QUE* q, int* x);

// ��� �����͸� ����
void Clear(QUE* q);

// ť�� �ִ� �뷮
int Capacity(const QUE* q);

// ť�� ����� ������ ����
int Size(const QUE* q);

// ť�� ����ִ°�?
int IsEmpty(const QUE* q);

// ť�� ����á�°�?
int IsFull(const QUE* q);

// ť���� �˻�
int Search(const QUE* q, int x);

int Search2(const QUE* q, int x);

// ��� ������ ���
void Print(const QUE* q);

// ť ����
void Terminate(QUE* q);

int FrontEnque(QUE* q, int x);

int RearDeque(QUE* q, int* x);

#endif // !___IntQueue

