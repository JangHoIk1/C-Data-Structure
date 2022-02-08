#include<stdio.h>
#include<stdlib.h>
#include "CircularQueue.h"

// 원형 큐에서 F / R의 이동 시키는 방법
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

// 이 부분 중요
int NextPosIndex(int pos) { // 큐의 다음 위치에 해당하는 인덱스 값을 반환
	if (pos == QUE_LEN - 1) // 배열의 마지막 요소의 인덱스 값
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue *pq, Data data){
	if (NextPosIndex(pq->rear) == pq->front) {
		printf("memory error");
		exit(-1);
	}
	pq->rear = NextPosIndex(pq->rear); // rear 한칸 이동
	pq->queArr[pq->rear] = data; // rear 가리키는 곳에 데이터를 저장한다.
}

Data Dequeue(Queue* pq) {
	if (QIsEmpty(pq)) {
		printf("memory error");
		exit(-1);
	}
	pq->front = NextPosIndex(pq->front); // front를 한 칸 이동
	return pq->queArr[pq->front];
}

Data Qpeek(Queue* pq) {
	if (QIsEmpty(pq)) {
		printf("memory error");
		exit(-1);
	}
	return pq->queArr[NextPosIndex(pq->front)];
}