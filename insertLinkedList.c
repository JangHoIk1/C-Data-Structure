#include<stdio.h>
#include "insertLinkedList.h" // 사용자 정의 헤더 파일

// 비어있는 연결 리스트 생성
linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h*));
	L->head = NULL;
}

// 연결 리스트 메모리 해제(삭제)
void freeLinkedList_h(linkedList_h* L) {
	listNode* p;

	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p); // free는 메모리 해제 함수
		p = NULL;
	}

}


// 첫번째 노드 삽입
void inserFirstNode(linkedList_h* L, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode*)); // 새 노드에 할당하겠다.
	strcpy(newNode->data, x); // 새 노드의 데이터 필드에 x 저장
	newNode->link = L->head; // 헷갈리는 부분
	L->head = newNode;
	
}

// 중간에 노드 삽입(가장 중요한 부분)
void inserMiddleNode(linkedList_h* L, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode*)); // 새 노드에 할당하겠다.
	strcpy(newNode->data, x);
	if (L->head == NULL) { // 현재 가리키는 곳이 공백이라면 // L->head가 마지막 노드란뜻인듯
		newNode->link = NULL; // 새 노드를 첫번째이자 마지막 노드로 연결
		L->head = newNode;
	}
	else if(pre == NULL) { // insert를 지정할 포인터 pre가 NULL 이라면
		newNode->link = L->head; // 새 노드를 첫 번째 노드로 삽입
		L->head = newNode;
	}
	else {
		newNode->link = pre->link; // 포인터 pre의 노드 뒤에 새 노드를 연결하겠다.
		pre->link = newNode;
	}

}

void inserLastNode(linkedList_h* L, char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode*));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	
	if (L->head == NULL) {
		L->head = newNode;
		return;
	}

	temp = L->head;
	while (temp->link != NULL) { // 즉 temp 가 마지막 노드가 될때까지
		temp = temp->link; // 계속 다음 링크로 타고 들어가는 것 // 현재 리스트에서 마지막 노드를 찾음
	} // NULL 값이 가리킬때까지 돌아간다 즉, 빠져나온다고하면 temp->Link 가 NULL값
	// 즉 마지막 노드가 된다는 뜻이다.

	temp->link = newNode; // 새 노드를 마지막 노드(temp)의 다음으로 연결

}









