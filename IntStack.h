#pragma once
#ifndef __IntStack
#define __IntStack

// ������ �����ϴ� ����ü �κ�
typedef struct {
	int max; // ���� �ִ� ���̰�(�뷮), stk[MAX]
	int ptr; // ���� ������, ������ ��������� ptr�� ���� 0
	int* stk; // start stack ������ ù ��ҿ� ���� ������, index�� 0�� ����� ���� �ٴ�
		      // �迭�� ù ��° ��Ҹ� ����Ű�� ������ �̴�.
			  // stk[ptr -1]-> ������ �ǹ��ϴ� ���ΰ�? : stack���� top �����͸� ����Ų��.
			  // stk[0], stk[1], ..... stk[max - 1]

}IntStack;

// ���� �ʱ�ȭ
int Initialize(IntStack* s, int max);

// stack push
int push(IntStack* s, int x);

// stack pop
int pop(IntStack* s, int* x); // ������ ���� �κ� �߿�! Ǫ�ô� �����Ͱ� �Ⱥپ��µ�
//pop���� �� �����Ͱ� �پ���? -> pop�� �� �ٸ� �ӽý��ÿ� �Ͻ������� �����Ϸ��� ������ ���� ����

// stack peek �����͸� �������� ������ ���� �״�� ����
int peek(const IntStack* s, int* x);

// stack clear ���� ����(�����) -> �����͸� ����°� �ƴ� �޸𸮸� ����� ��
void clear(IntStack* s);

// stack max
int capacity(const IntStack* s); // �ִ� �뷮�� ��Ÿ���� ��

// stack count ������ ����
int size(const IntStack* s);

// stack empty ������ ����ִ���
int isEmpty(const IntStack* s);

// stack Full
int IsFull(const IntStack* s);

// stack search
int Search(const IntStack* s, int x);

// stack ���
void print(const IntStack* s);

// stack end
void Terminate(IntStack* s);

#endif
