#pragma once
#ifndef __IntStack
#define __IntStack

// 스택을 구현하는 구조체 부분
typedef struct {
	int max; // 스택 최대 길이값(용량), stk[MAX]
	int ptr; // 스택 포인터, 스택이 비어있으면 ptr의 값은 0
	int* stk; // start stack 스택의 첫 요소에 대한 포인터, index가 0인 요소의 스택 바닥
		      // 배열의 첫 번째 요소를 가리키는 포인터 이다.
			  // stk[ptr -1]-> 무엇을 의미하는 것인가? : stack에서 top 데이터를 가리킨다.
			  // stk[0], stk[1], ..... stk[max - 1]

}IntStack;

// 스택 초기화
int Initialize(IntStack* s, int max);

// stack push
int push(IntStack* s, int x);

// stack pop
int pop(IntStack* s, int* x); // 포인터 변수 부분 중요! 푸시는 포인터가 안붙었는데
//pop에는 왜 포인터가 붙었지? -> pop한 또 다른 임시스택에 일시적으로 저장하려고 포인터 변수 선언

// stack peek 데이터를 빼내지만 기존의 값은 그대로 놔둠
int peek(const IntStack* s, int* x);

// stack clear 스택 비우기(지우기) -> 데이터를 지우는게 아닌 메모리를 지우는 것
void clear(IntStack* s);

// stack max
int capacity(const IntStack* s); // 최대 용량을 나타내는 것

// stack count 스택의 개수
int size(const IntStack* s);

// stack empty 스택이 비어있는지
int isEmpty(const IntStack* s);

// stack Full
int IsFull(const IntStack* s);

// stack search
int Search(const IntStack* s, int x);

// stack 출력
void print(const IntStack* s);

// stack end
void Terminate(IntStack* s);

#endif
