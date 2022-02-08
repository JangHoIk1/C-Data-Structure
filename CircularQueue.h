#pragma once
#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__


#define TRUE 1 // 검사(큐에 데이터가 존재 하는지)
#define FALSE 0 // 검사()

#define QUE_LEN 100
typedef int Data;

typedef struct _cQueue {
	int front; // F
	int rear; // R
	Data queArr[QUE_LEN];
}CQueue;


typedef CQueue Queue;

//Queue의 함수 정의
void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data Qpeek(Queue* pq);



#endif