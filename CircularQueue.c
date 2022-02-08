#include<stdio.h>
#include<stdlib.h>
#include "CircularQueue.h"

// ���� ť���� F / R�� �̵� ��Ű�� ���
void QueueInit(Queue* pq) {
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue* pq) {
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

// �� �κ� �߿�
int NextPosIndex(int pos) { // ť�� ���� ��ġ�� �ش��ϴ� �ε��� ���� ��ȯ
	if (pos == QUE_LEN - 1) // �迭�� ������ ����� �ε��� ��
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue *pq, Data data){
	if (NextPosIndex(pq->rear) == pq->front) {
		printf("memory error");
		exit(-1);
	}
	pq->rear = NextPosIndex(pq->rear); // rear ��ĭ �̵�
	pq->queArr[pq->rear] = data; // rear ����Ű�� ���� �����͸� �����Ѵ�.
}

Data Dequeue(Queue* pq) {
	if (QIsEmpty(pq)) {
		printf("memory error");
		exit(-1);
	}
	pq->front = NextPosIndex(pq->front); // front�� �� ĭ �̵�
	return pq->queArr[pq->front];
}

Data Qpeek(Queue* pq) {
	if (QIsEmpty(pq)) {
		printf("memory error");
		exit(-1);
	}
	return pq->queArr[NextPosIndex(pq->front)];
}