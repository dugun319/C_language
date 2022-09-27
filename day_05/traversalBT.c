#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct treeNode {
    element data;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

treeNode* makeRootNode(element data, treeNode* leftNode, treeNode* rightNode) {
    treeNode* root = (treeNode*)malloc(sizeof(treeNode));
    root->data= data;
    root->left = leftNode;
    root->right = rightNode;
    return root;
}

void preorder(treeNode* root) {
    if(root) {
        printf("%c", root->data);   //Work D
        preorder(root->left);       //Work L
        preorder(root->right);      //Work R
    }
}

void inorder(treeNode* root) {
    if(root) {
        inorder(root->left);        //Work L
        printf("%c", root->data);   //Work D
        inorder(root->right);       //Work R
    }
}

void postorder(treeNode* root) {
    if(root) {
        postorder(root->left);      //Work L
        postorder(root->right);     //Work R
        printf("%c", root->data);   //Work D
        
    }
}

int main() {
    treeNode* n7 = makeRootNode('D', NULL, NULL);
    treeNode* n6 = makeRootNode('C', NULL, NULL);
    treeNode* n5 = makeRootNode('B', NULL, NULL);
    treeNode* n4 = makeRootNode('A', NULL, NULL);
    treeNode* n3 = makeRootNode('/', n6, n7);
    treeNode* n2 = makeRootNode('*', n4, n5);
    treeNode* n1 = makeRootNode('-', n2, n3);

    printf("\nPreorder: ");
    preorder(n1);

    printf("\nInorder: ");
    inorder(n1);

    printf("\nPostorder: ");
    postorder(n1);

    getchar();

    return 0;
}