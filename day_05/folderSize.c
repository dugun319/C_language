#include <stdio.h>
#include <stdlib.h>

int FolderSize;

typedef struct treeNode {
    int size;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

treeNode* makeRootNode(int size, treeNode* leftNode, treeNode* rightNode) {
    treeNode* root = (treeNode*)malloc(sizeof(treeNode));
    root->size= size;
    root->left = leftNode;
    root->right = rightNode;
    return root;
}

int postorder(treeNode* root) {
    if(root) {
        postorder(root->left);      //Work L
        postorder(root->right);     //Work R
        FolderSize += root->size;   //Work D
    }
    return FolderSize;
}

int main() {
   
    treeNode* n15 = makeRootNode(120, NULL, NULL);
    treeNode* n14 = makeRootNode(55, NULL, NULL);
    treeNode* n9 = makeRootNode(100, NULL, NULL);
    treeNode* n8 = makeRootNode(200, NULL, NULL);
    treeNode* n7 = makeRootNode(68, n14, n15);
    treeNode* n6 = makeRootNode(40, NULL, NULL);
    treeNode* n5 = makeRootNode(15, NULL, NULL);
    treeNode* n4 = makeRootNode(2, n8, n9);
    treeNode* n3 = makeRootNode(10, n6, n7);
    treeNode* n2 = makeRootNode(0, n4, n5);
    treeNode* n1 = makeRootNode(0, n2, n3);

    FolderSize = 0;
    printf("\n Size of C Drive: %d M\n", postorder(n2));
 
    FolderSize = 0;
    printf("\n Size of D Drive: %d M\n", postorder(n3));

    FolderSize = 0;
    printf("\n Size of MyComputer: %d M\n", postorder(n1));

    //getchar();

    return 0;
}