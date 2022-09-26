#include "CircularLinkedList.h"

int main()
{

	linkedList_h* CL;
	listNode* p;

	CL = createLinkedList_h();
	printf("(1) Create CircularLinkedList!!\n");
	printList(CL);

	printf("\n(2) Insert [Mon] Node in CircularLinkedList!!\n");
	insertFirstNode(CL, "Mon");
	printList(CL);

	printf("\n(3) Insert [Wed] node behind [Mon] Node in CircularLinkedList!!\n");
	p = searchNode(CL, "Mon");
	insertMiddleNode(CL, p, "Wed");
	printList(CL);
	
	printf("\n(4) Insert [Fri] node behind [Wed] Node in CircularLinkedList!!\n");
	p = searchNode(CL, "Wed");
	insertMiddleNode(CL, p, "Fri");
	printList(CL);

	printf("\nDelete [Wed] Node in CircularLinkedList!!\n");
	p = searchNode(CL, "Wed");
	deleteNode(CL, p);
	printList(CL);
}
