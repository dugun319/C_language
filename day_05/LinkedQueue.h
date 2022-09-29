#pragma once

typedef int element;		// 스택 원소(element)의 자료형을 int로 정의 

typedef struct QNode {	// 스택의 노드를 구조체로 정의
	element data;
	struct QNode* link;
} QNode;

typedef struct {	// 스택의 노드를 구조체로 정의
	QNode* front;
    QNode* rear;
} LQueueType;

LQueueType* createLinkedQueue(void);
int isLQEmpty(LQueueType* LQ);
void enLQueue(LQueueType* LQ, element item);
element deLQueue(LQueueType* LQ);
void printLQ(LQueueType* LQ);