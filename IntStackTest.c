#include<stdio.h>
#include<stdlib.h>
#include "IntStack.h"
int main(void)
{
	IntStack s;
	if (Initialize(&s, 60) == -1) {
		puts("스택 생성 실패");
		return 1;
	}

	while (1) {
		int menu, x;
		printf("현재 데이터 수는 : %d / %d \n",size(&s), capacity(&s));
		printf("(1)push (2)pop (3)peek (4)print (5)Terminate : ");
		scanf_s("%d", &menu);

		if (menu == 0) {
			break;
		}
		switch (menu) {
		case 1: // push
			
		case 2: // pop

		case 3: // peek

		case 4: // print
			print(&s);
			break;
		}
	}
	Terminate(&s);
	return 0;
}