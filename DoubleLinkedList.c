#include "DoubleLinkedList.h"

linkedList_h* createLinkedList_h(void){

	linkedList_h* DL;
	DL = (linkedList_h*)malloc(sizeof(linkedList_h));
	DL -> head = NULL;
	return DL;
}



void printList(linkedList_h* DL){

	listNode* p;
	printf("DL = (");
	p = DL -> head;

	if(p == NULL)
	{
		printf(") \n");
		return;
	}
	do
	{
		printf("%s", p->data);
		p = p -> rlink;
		if(p != DL -> head)
		{
			printf(", ");
		}
	}
	while(p != DL->head);
	
	printf(") \n");

}



void insertNode(linkedList_h* DL, listNode* pre, char* x)
{	
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	
	strcpy(newNode -> data, x);

	if(DL -> head == NULL)
	{
		newNode -> llink = NULL;
		newNode -> rlink = NULL;
		DL -> head = newNode;
	}
	else
	{
		newNode -> rlink = pre -> rlink;
		pre -> rlink = newNode;
		newNode -> llink = pre;

		if(newNode -> rlink != NULL)
		{
			newNode -> rlink -> llink = newNode;
		}
	}
}



void deleteNode(linkedList_h* DL, listNode* old){
	
	if(DL -> head == NULL)
	{
		return;
	}else if(old == NULL)
	{
		return;
	}else{
		old -> rlink -> llink = old -> llink;
		old -> llink -> rlink = old -> rlink;
		free(old);
	}

}

listNode* searchNode(linkedList_h* DL, char* x){

	listNode* temp;
	temp = DL -> head;
	while(temp != NULL)
	{
		if(strcmp(temp -> data, x) == 0)
		{
			return temp;
		}else{
			temp = temp -> rlink;
		}
	}

	return temp;
}
