#include "DoubleLinkedList.h"

int main()
{
	linkedList_h* DL;
	listNode* p;

	DL = createLinkedList_h();
	printf("(1) Create DoubleLinkedList!!\n\n");
	printList(DL);

	printf("(2) Insert Node [Mon] in DoubleLinkedList!!\n\n");
	insertNode(DL, NULL, "Mon");
	printList(DL);
	
	printf("(3) Insert Node [Wed] behind the Node [Mon] in DoubleLinkedList!!\n\n");
	p = searchNode(DL, "Mon");
	insertNode(DL, p, "Wed");
	printList(DL);

	printf("(4) Insert Node [Fri] behind the Node [Wed] in DoubleLinkedList!!\n\n");
	p = searchNode(DL, "Wed");
	insertNode(DL, p, "Fri");
	printList(DL);
	
	printf("(5) Delete Node [Wed] in DoubleLinkedList!!\n\n");
	p = searchNode(DL, "Mon");
	deleteNode(DL, p);
	printList(DL);

	return 0;

}
