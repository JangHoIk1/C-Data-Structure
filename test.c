#include<stdio.h>
#include "insertLinkedList.h"
int main(void) {

	linkedList_h* L;
	L = createLinkedList_h();
	printf("(1)리스트 생성하기(head)\n");
	printList(L);

	printf("\n(2)리스트 노드[1] 생성하기\n");
	insertFirstNode(L, "1");
	printList(L);


	printf("\n(3)마지막 노드[2] 생성하기\n");
	insertFirstNode(L, "2");
	printList(L);


	printf("\n(4)리스트 첫번째 노드에 [3] 삽입하기\n"); // 삽입을 하겠다
	insertFirstNode(L, "3");
	printList(L);

	
	printf("\n(5)리스트 공백 리스트 만들기(메모리 해제)\n"); // 삽입을 하겠다
	freeLinkedList_h(L);
	printList(L);

	getchar();
	return 0;

}