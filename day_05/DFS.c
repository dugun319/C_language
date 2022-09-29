#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 30 // 헤드 포인터 배열의 최대 크기
#define FALSE 0 // 추가!
#define TRUE 1 // 추가!
typedef int element;    		// 스택 원소(element)의 자료형을 int로 정의 

//인접 리스트의 노드 구조를 구조체로 정의
typedef struct graphNode { 
    int vertex;                // 정점을 나타내는 데이터 필드
    struct graphNode* link;    // 다음 인접 정점을 연결하는 링크 필드
}graphNode;

//그래프를 인접 리스트로 표현하기 위한 구조체 정의
typedef struct graphType {
    int n;                               // 그래프의 정점 개수
    graphNode* adjList_H[MAX_VERTEX];    // 그래프 정점에 대한 헤드 포인터 배열
    int visited[MAX_VERTEX];             // 정점에 대한 방문 표시를 위한 배열 추가!
}graphType;


typedef struct  stackNode {	// 스택의 노드를 구조체로 정의
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;				// 스택의 top 노드를 지정하기 위해 포인터 top 선언

// 스택이 공백 상태인지 확인하는 연산
int isStackEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));

	temp->data = item;
	temp->link = top;     // 삽입 노드를 top의 위에 연결
	top = temp;           // top 위치를 삽입 노드로 이동
}

// 스택의 top에서 원소를 삭제하는 연산
element pop() {
	element item;
	stackNode* temp = top;

	if (isStackEmpty()) {		// 스택이 공백 리스트인 경우
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {					// 스택이 공백 리스트가 아닌 경우
		item = temp->data;
		top = temp->link;	// top 위치를 삭제 노드 아래로 이동
		free(temp);			// 삭제된 노드의 메모리 반환
		return item;		// 삭제된 원소 반환
	}
}

// 스택의 top 원소를 검색하는 연산
element peek() {
	if (isStackEmpty()) {		// 스택이 공백 리스트인 경우
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {					// 스택이 공백 리스트가 아닌 경우
		return(top->data);  // 현재 top의 원소 반환
	}
}

// 스택의 원소를 top에서 bottom 순서로 출력하는 연산
void printStack() {
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}

void createGraph(graphType* g) { //그래프의 정점 개수를 0으로 초기화
    int v;
    g->n =0;
    for (v = 0; v <MAX_VERTEX;v++) {
        g->adjList_H[v] = NULL; //그래프의 정점에 대한 헤드 포인터 배열을 NULL로 초기화
        g->visited[v] = FALSE;  //그래프의 정점에 대한 배열 visited를 FALSE로 초기화 추가!
    }
}

// 그래프 g에 정점 v를 삽입하는 연산
void insertVertex(graphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) {
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	g->n++;								// 그래프의 정점 개수 n을 하나 증가
}

// 그래프 g에 간선 (u, v)를 삽입하는 연산
void insertEdge(graphType* g, int u, int v) {
	graphNode* node;

	// 간선 (u, v)를 삽입하기 위해 정점 u와 정점 v가 현재 그래프에 있는지 확인
	if (u >= g->n || v >= g->n) {
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];	// 삽입 간선에 대한 노드를 리스트의 첫 번째 노드로 연결
	g->adjList_H[u] = node;
}

// 그래프 g의 각 정점에 대한 인접 리스트를 출력하는 연산
void print_adjList(graphType* g) {
	int i;
	graphNode* p;
	for (i = 0; i < g->n; i++) {
		printf("\n\t\t정점 %c의 인접 리스트", i + 65);
		p = g->adjList_H[i];
		while (p) {
			printf(" -> %c", p->vertex + 65); // 정점 0~3을 A~D로 출력
			p = p->link;
		}
	}
}

// 그래프 g에서 정점 v에 대한 깊이 우선 탐색 연산
void DFS_adjustList(graphType*g, int v) {
    graphNode* w;
    top = NULL;                  // 스택의 top 설정
    push(v);                     // 깊이 우선 탐색을 시작하는 정점 v를 스택에 push
    g->visited[v] = TRUE;        // 정점 v를 방문했으므로 해당 배열값을 TRUE로 설정
    printf(" %c", v+65);
    
    // 스택이 공백이 아닌 동안 깊이 우선 탐색 반복
    while(!isStackEmpty()) {
        w = g->adjList_H[v];
        // 인접 정점이 있는 동안 수행

        while(w) {
            //현재 정점 w를 방문하지 않은 경우
            if(!g->visited[w->vertex]) {
                push(w->vertex);                //현재 정점 W를 스택에 push
                g->visited[w->vertex] = TRUE;   //정점 w에 대한 배열값을 TURE로 설정
                printf(" %c", w->vertex +65);   //정점 0~6을 A~G로 바꾸어서 출력
                v = w->vertex;
                w = g-> adjList_H[v];
            }
            // 현재 정점 w가 이미 방문된 경우
            else w = w->link;
        }
        v = pop();  //현재 정점에서 순회를 진행할 인접 정점이 더 없는 경우에 스택 pop!
    }// 스택이 공백이면 깊이 우선 탐색 종료
}

int main() {
    int i;
    graphType* G9;
    G9 = (graphType*)malloc(sizeof(graphType));
    createGraph(G9);

    // 그래프 G9 구성 : 정점 u에 대한 간선(u,v)는 v가 큰 것부터 삽입
    for(i=0;i<7;i++) 
        insertVertex(G9,i);
    insertEdge(G9,0,2);
    insertEdge(G9,0,1);
    insertEdge(G9,1,4);
    insertEdge(G9,1,3);
    insertEdge(G9,1,0);
    insertEdge(G9,2,4);
    insertEdge(G9,2,0);
    insertEdge(G9,3,6);
    insertEdge(G9,3,1);
    insertEdge(G9,4,6);
    insertEdge(G9,4,2);
    insertEdge(G9,4,1);
    insertEdge(G9,5,6);
    insertEdge(G9,6,5);
    insertEdge(G9,6,4);
    insertEdge(G9,6,3);
    printf("\n G9의 인접 리스트");
    print_adjList(G9);        // G9 인접 리스트를 확인용 출력

    printf("\n\n///////////////\n\n깊이 우선탐색>>");
    DFS_adjustList(G9,0);        //0번 정점인 정점 A에서 깊이 우선 탐색 시작

    getchar();
    
    return 0;
}