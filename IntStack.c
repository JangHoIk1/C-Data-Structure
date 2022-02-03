#include<stdio.h>
#include<stdlib.h>
#include "IntStack.h"

int Initialize(IntStack* s, int max) {
	s->ptr = 0; // ���ÿ� �׿��ִ� �����͸� 0���� �ʱ�ȭ 
	if ((s->stk=calloc(max, sizeof(int))) == NULL) {
		s->max = 0; // max�� 0�̶�� ���� �ǹ̴� ? -> �迭�� ���� ����
		return -1;
	}
	
	s->max = max;
	return 0;
}

int push(IntStack* s, int x) {
	// �����Ͱ� ���� �� �ִٸ�
	if (s->ptr >= s->max) { // ptr >= max
		return -1;
	}
	s->stk[s->ptr++] = x;
	return 0;

}

// stack pop
// ������ �ڷḦ ��ȯ�ϴ� pop() ������ stack���� �ڷḦ ��ȯ�ϸ鼭 �� �ڷᰡ
// �ִ� ��Ҹ� �����Ѵ�. �� �ݴ�� peek() ������ �ڷḦ ���� �ϴ� ���� ����������
// ���� ���� �ʴ´�.
// �߿��� ���� �ڷḦ �����Ѵٰ� �ϴ� �ǹ̴� �޸��� ������ �ǹ��ϴ� ����
// �ƴϴ�.
// stack���� �޸𸮸� �����ϴ� ������ deleteStack()�Լ��� ����Ѵ�
int pop(IntStack* s, int* x){
	if (s->ptr <= 0) // stack�� ���������
		return -1;

	*x = s->stk[s->ptr--];
	return 0;
}

// stack peek
int peek(const IntStack* s, int* x) {
	if (s->ptr <= 0)
		return -1;

	// ������ ������� ������ �����(top) ��� stk[ptr-1]�� ���� 
	// ������ x�� ����Ű�� ������ �����ض�
	*x = s->stk[s->ptr - 1];
	return 0; // �����ϸ� 0�� ��ȯ
}

// stack�� �׿��ִ� ��� ������ �����Ѵ�.
void clear(IntStack* s) {
	s->ptr = 0;
}

// stack �뷮
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

// stack �˻�
int Search(const IntStack* s, int x) {
	int i;
	for (i = s->ptr - 1; i >= 0; i--) {
		if (s->stk[i] == x)
			return i; // �˻� ����
	}
	return -1; // �˻� ����

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
		free(s->stk); // �迭�� ����
	s->max = s->ptr = 0;

}