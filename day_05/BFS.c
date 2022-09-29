#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedQueue.h"
#include "adjList.h"
#include "BFS.h"

void BFS_adjustList(graphType *g, int v)
{
    graphNode *w;
    LQueueType *Q;           //큐
    Q = createLinkedQueue(); //큐 생성
    g->visited[v] = true;    //시작 정점 v에 대한 배열값을 TRUE로 설정
    printf(" %c", v + 65);
    enLQueue(Q, v); //현재 정점 v를 큐에 enQueue

    // 큐가 공백이 아닌 동안 너비 우선 탐색 수행
    while (!isLQEmpty(Q))
    {
        v = deLQueue(Q);
        //현재 정점 w를 방문하지 않은 경우
        for (w = g->adjList_H[v]; w; w = w->link) // 인접 정점이 있는 동안 수행
            if (!g->visited[w->vertex])
            { // 정점 w가 방문하지 않은 정점인 경우
                g->visited[w->vertex] = true;
                printf(" %c", w->vertex + 65); // 정점 0~6을 A~G로 바꾸어 출력
                enLQueue(Q, w->vertex);
            }
    } // 큐가 공백이면 너비 우선 탐색 종료
}