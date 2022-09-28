#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    char data;
    struct treeNode* left;
    struct treeNode* right;
    int isThreadRight;
} treeNode;

treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode, int isThreadRight) {
    treeNode* root = (treeNode*)malloc(sizeof(treeNode));
    root->data = data;
    root->left = leftNode;
    root->right = rightNode;
    root->isThreadRight = isThreadRight;
    return root;
}

treeNode* findThreadSuccessor(treeNode* p) {
    treeNode* q = p->right;
    if(q == NULL) {
        return q;
    }
    if(p->isThreadRight == 1) {
        return q;
    }
    while(q->left != NULL)
    {
        q = q->left;
    }
    return q;

}


void threadInorder(treeNode* root) {
    treeNode* q;
    q = root;
    while(q->left)
    {
        q = q->left;
    }
    do {
        printf("%3c", q->data);
        q = findThreadSuccessor(q);
    } while(q);
}

int main() {
   
    treeNode* c7 = makeRootNode('D', NULL, NULL, 0);
    treeNode* c6 = makeRootNode('C', NULL, NULL, 1);
    treeNode* c5 = makeRootNode('B', NULL, NULL, 1);
    treeNode* c4 = makeRootNode('A', NULL, NULL, 1);
    treeNode* c3 = makeRootNode('/', c6, c7, 0);
    treeNode* c2 = makeRootNode('*', c4, c5, 0);
    treeNode* c1 = makeRootNode('-', c2, c3, 0);

    c4->right = c2;
    c5->right = c1;
    c6->right = c3;
    
    printf("\nBinary Thread inorder: ");

    threadInorder(c1);

    //getchar();

    return 0;
}