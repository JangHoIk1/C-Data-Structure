#include<stdio.h>
#include "insertLinkedList.h"
int main(void) {

	linkedList_h* L;
	L = createLinkedList_h();
	printf("(1)����Ʈ �����ϱ�(head)\n");
	printList(L);

	printf("\n(2)����Ʈ ���[1] �����ϱ�\n");
	insertFirstNode(L, "1");
	printList(L);


	printf("\n(3)������ ���[2] �����ϱ�\n");
	insertFirstNode(L, "2");
	printList(L);


	printf("\n(4)����Ʈ ù��° ��忡 [3] �����ϱ�\n"); // ������ �ϰڴ�
	insertFirstNode(L, "3");
	printList(L);

	
	printf("\n(5)����Ʈ ���� ����Ʈ �����(�޸� ����)\n"); // ������ �ϰڴ�
	freeLinkedList_h(L);
	printList(L);

	getchar();
	return 0;

}