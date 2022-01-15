#ifndef ___DOUBLE_STACK
#define ___DOUBLE_STACK

typedef struct {
	int max;
	int ptrA, ptrB;
	int* stk;
}STACK;

int initialize(STACK* s, int max);

int PushA(STACK* s, int x);

int PushB(STACK* s, int x);

int PopA(STACK* s, int* x);

int PopB(STACK* s, int* x);

int PeekA(const STACK* s, int* x);

int PeekB(const STACK* s, int* x);

void Print(const STACK* s);

void Clear(STACK* s);

void Delete(STACK* s);

int getCapacity(const STACK* s);

int getSizeA(const STACK* s);

int getSizeB(const STACK* s);

int Search(const STACK* s, int x);

#endif 

