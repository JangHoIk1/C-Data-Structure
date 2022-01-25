#pragma once
// ��� ����
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listNode;

// head ����� ����
typedef struct {
	listNode* head;
}linkedList_h;


linkedList_h* createLinkedList_h(void);
void freeLinkedList_h(linkedList_h* L); // ���� ����Ʈ �޸� ���� �ϴ� �Լ�
void inserFirstNode(linkedList_h* L, char *x);
void inserMiddleNode(linkedList_h* L, listNode * pre, char* x); // �߰��� ���ԵǾ��� ��
void inserLastNode(linkedList_h* L, char* x);
//void printList(linkedList_h* L);
























