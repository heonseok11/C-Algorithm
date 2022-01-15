#ifndef ___IntQueue
#define ___IntQueue

// 큐를 재현하는 구조체
typedef struct {
	int max;	//큐의 최대 용량
	int num;	//현재의 요소 개수
	int front;	//프런트
	int rear;	//리어
	int* que;	//큐의 맨 앞 요소에 대한 포인터
}QUE;

// 큐 초기화
int Initialize(QUE* q, int max);

// 큐에 데이터를 인큐
int Enque(QUE* q, int x);

// 큐에서 데이터를 디큐
int Deque(QUE* q, int* x);

// 큐에서 데이터를 피크
int Peek(QUE* q, int* x);

// 모든 데이터를 삭제
void Clear(QUE* q);

// 큐의 최대 용량
int Capacity(const QUE* q);

// 큐에 저장된 데이터 개수
int Size(const QUE* q);

// 큐가 비어있는가?
int IsEmpty(const QUE* q);

// 큐가 가득찼는가?
int IsFull(const QUE* q);

// 큐에서 검색
int Search(const QUE* q, int x);

int Search2(const QUE* q, int x);

// 모든 데이터 출력
void Print(const QUE* q);

// 큐 종료
void Terminate(QUE* q);

int FrontEnque(QUE* q, int x);

int RearDeque(QUE* q, int* x);

#endif // !___IntQueue

