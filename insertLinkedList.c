#include<stdio.h>
#include "insertLinkedList.h" // ����� ���� ��� ����

// ����ִ� ���� ����Ʈ ����
linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h*));
	L->head = NULL;
}

// ���� ����Ʈ �޸� ����(����)
void freeLinkedList_h(linkedList_h* L) {
	listNode* p;

	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p); // free�� �޸� ���� �Լ�
		p = NULL;
	}

}


// ù��° ��� ����
void inserFirstNode(linkedList_h* L, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode*)); // �� ��忡 �Ҵ��ϰڴ�.
	strcpy(newNode->data, x); // �� ����� ������ �ʵ忡 x ����
	newNode->link = L->head; // �򰥸��� �κ�
	L->head = newNode;
	
}

// �߰��� ��� ����(���� �߿��� �κ�)
void inserMiddleNode(linkedList_h* L, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode*)); // �� ��忡 �Ҵ��ϰڴ�.
	strcpy(newNode->data, x);
	if (L->head == NULL) { // ���� ����Ű�� ���� �����̶�� // L->head�� ������ �������ε�
		newNode->link = NULL; // �� ��带 ù��°���� ������ ���� ����
		L->head = newNode;
	}
	else if(pre == NULL) { // insert�� ������ ������ pre�� NULL �̶��
		newNode->link = L->head; // �� ��带 ù ��° ���� ����
		L->head = newNode;
	}
	else {
		newNode->link = pre->link; // ������ pre�� ��� �ڿ� �� ��带 �����ϰڴ�.
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
	while (temp->link != NULL) { // �� temp �� ������ ��尡 �ɶ�����
		temp = temp->link; // ��� ���� ��ũ�� Ÿ�� ���� �� // ���� ����Ʈ���� ������ ��带 ã��
	} // NULL ���� ����ų������ ���ư��� ��, �������´ٰ��ϸ� temp->Link �� NULL��
	// �� ������ ��尡 �ȴٴ� ���̴�.

	temp->link = newNode; // �� ��带 ������ ���(temp)�� �������� ����

}









