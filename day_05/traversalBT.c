#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct treeNode { //_TreeNode 가 더 좋을 것으로 생각
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

    
    treeNode* c7 = makeRootNode('D', NULL, NULL);
    treeNode* c6 = makeRootNode('C', NULL, NULL);
    treeNode* c5 = makeRootNode('B', NULL, NULL);
    treeNode* c4 = makeRootNode('A', NULL, NULL);
    treeNode* c3 = makeRootNode('/', c6, c7);
    treeNode* c2 = makeRootNode('*', c4, c5);
    treeNode* c1 = makeRootNode('-', c2, c3);
    
    
    treeNode* n11 = makeRootNode('K', NULL, NULL);
    treeNode* n10 = makeRootNode('J', NULL, NULL);
    treeNode* n9 = makeRootNode('I', NULL, NULL);
    treeNode* n8 = makeRootNode('H', NULL, NULL);
    treeNode* n7 = makeRootNode('G', NULL, n11);
    treeNode* n6 = makeRootNode('F', NULL, NULL);
    treeNode* n5 = makeRootNode('E', n9, n10);
    treeNode* n4 = makeRootNode('D', n8, NULL);
    treeNode* n3 = makeRootNode('C', n6, n7);
    treeNode* n2 = makeRootNode('B', n4, n5);
    treeNode* n1 = makeRootNode('A', n2, n3);


    printf("\nPreorder: ");
    preorder(c1);

    printf("\nInorder: ");
    inorder(c1);

    printf("\nPostorder: ");
    postorder(c1);    


    printf("\nPreorder: ");
    preorder(n1);

    printf("\nInorder: ");
    inorder(n1);

    printf("\nPostorder: ");
    postorder(n1);

    //getchar();

    return 0;
}