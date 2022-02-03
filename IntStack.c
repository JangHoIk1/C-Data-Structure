#include<stdio.h>
#include<stdlib.h>
#include "IntStack.h"

int Initialize(IntStack* s, int max) {
	s->ptr = 0; // 스택에 쌓여있는 데이터를 0으로 초기화 
	if ((s->stk=calloc(max, sizeof(int))) == NULL) {
		s->max = 0; // max가 0이라는 것의 의미는 ? -> 배열의 생성 실패
		return -1;
	}
	
	s->max = max;
	return 0;
}

int push(IntStack* s, int x) {
	// 데이터가 가득 차 있다면
	if (s->ptr >= s->max) { // ptr >= max
		return -1;
	}
	s->stk[s->ptr++] = x;
	return 0;

}

// stack pop
// 스택의 자료를 반환하는 pop() 연산은 stack에서 자료를 반환하면서 그 자료가
// 있던 장소를 제거한다. 그 반대로 peek() 연산은 자료를 제거 하는 것은 동일하지만
// 제거 하지 않는다.
// 중요한 점은 자료를 제거한다고 하는 의미는 메모리의 해제를 의미하는 것이
// 아니다.
// stack에서 메모리를 해제하는 연산은 deleteStack()함수를 사용한다
int pop(IntStack* s, int* x){
	if (s->ptr <= 0) // stack이 비어있으면
		return -1;

	*x = s->stk[s->ptr--];
	return 0;
}

// stack peek
int peek(const IntStack* s, int* x) {
	if (s->ptr <= 0)
		return -1;

	// 스택이 비어있지 않으면 꼭대기(top) 요소 stk[ptr-1]의 값을 
	// 포인터 x가 가리키는 변수에 저장해라
	*x = s->stk[s->ptr - 1];
	return 0; // 성공하면 0을 반환
}

// stack에 쌓여있는 모든 데이터 삭제한다.
void clear(IntStack* s) {
	s->ptr = 0;
}

// stack 용량
int capacity(const IntStack* s) {
	return s->max;
}

int size(const IntStack* s) {
	return s->ptr;
}

int isEmpty(const IntStack* s) {
	return s->ptr <= 0;
}

int IsFull(const IntStack* s) {
	return s->ptr >= s->max;
}

// stack 검색
int Search(const IntStack* s, int x) {
	int i;
	for (i = s->ptr - 1; i >= 0; i--) {
		if (s->stk[i] == x)
			return i; // 검색 성공
	}
	return -1; // 검색 실패

}

void print(const IntStack* s) {
	int i = 0;

	for (i = 0; i < s->ptr; i++) {
		print("%d ", s->stk[i]);
	}
	putchar('\n');
}

void Terminate(IntStack* s) {
	if (s->stk != NULL)
		free(s->stk); // 배열을 삭제
	s->max = s->ptr = 0;

}