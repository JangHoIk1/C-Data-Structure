#pragma once
// 노드 선언
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listNode;

// head 노드의 정의
typedef struct {
	listNode* head;
}linkedList_h;


linkedList_h* createLinkedList_h(void);
void freeLinkedList_h(linkedList_h* L); // 연결 리스트 메모리 해제 하는 함수
void inserFirstNode(linkedList_h* L, char *x);
void inserMiddleNode(linkedList_h* L, listNode * pre, char* x); // 중간에 삽입되었을 때
void inserLastNode(linkedList_h* L, char* x);
//void printList(linkedList_h* L);
























