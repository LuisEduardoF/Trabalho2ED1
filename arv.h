#ifndef ARVORE
#define ARVORE

typedef struct treenode *tTree;

tTree inicializeTree(char*);
tTree AddLeft(tTree left, tTree origem);
tTree AddRight(tTree right, tTree origem);
tTree searchTree(char*, tTree);
tTree updateTree(char*, tTree);
float evaluate(tTree);
char* peek(tTree);
void printTree(tTree);
tTree freeTree(tTree);

#endif