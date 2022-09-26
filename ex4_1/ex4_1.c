#include <stdio.h>
#include "LinkedList.h"

int main()
{
	linkedList_h* L;
	listNode* p;
	L = createLinkedList_h();
	
	printf("(1) Insert [Mon], [Wed], {Sun] node in List\n");
	insertLastNode(L, "Mon");
	insertLastNode(L, "Wed");
	insertLastNode(L, "Sun");
	printList(L);

	printf("\n(2) Search [수] Node! \n");
	p = searchNode(L, "Wed");
	if(p == NULL)
	{
		printf("There is no finding data!\n");
	}
	else
	{
		printf("[%s] is found!\n", p -> data );
	}
	printList(L);

	printf("\n(3) Insert [Fri] node follow the [Wed] node!\n");
	insertMiddleNode(L, p, "Fri");
	printList(L);

	printf("\n(4) Delete [Sun] node \n");
	p = searchNode(L, "Sun");
	deleteNode(L, p);
	printList(L);

	printf("\n(5) Reverse the sequence of the LIST!\n");
	reverse(L);
	printList(L);

	printf("GitHub");

<<<<<<< HEAD
	printf("master");
=======
	printf("hotfix");
>>>>>>> hotfix
		
	freeLinkedList_h(L);

	return 0;

}
