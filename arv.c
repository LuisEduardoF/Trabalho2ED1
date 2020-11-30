#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv.h"
struct treenode{
    char* c;
    tTree right, left;
};
int isEmpty(tTree t){
    return t == NULL;
}
tTree inicializeTree(char *c){
    tTree new = malloc(sizeof(struct treenode));

    new->c = strdup(c);
    new->right = new->left = NULL;

    return new;
}
tTree AddLeft(tTree left, tTree origem){
    origem->left = left;
    return origem;
}
tTree AddRight(tTree right, tTree origem){
    origem->right = right;
    return origem;
}
tTree searchTree(char *c, tTree t){
    if(!isEmpty(t)){
       if(strcmp(t->c, c) == 0){
           return t;
       }
       else{
           tTree right = searchTree(c, t->right), left = searchTree(c, t->left);
           if(right != NULL){
               return right;
           }
           if(left != NULL){
               return left;
           }
           return NULL;
       }
    }
    return NULL;
}
float evaluate(tTree t){
    if(!isEmpty(t)){
            if(!strcmp(t->c, "+"))
                return evaluate(t->left) + evaluate(t->right);
            else if(!strcmp(t->c, "-"))
                return evaluate(t->left) - evaluate(t->right);
            else if(!strcmp(t->c, "/"))
                return evaluate(t->left) / evaluate(t->right);
            else if(!strcmp(t->c, "*"))
                return evaluate(t->left) * evaluate(t->right);
            else{
                return atof(t->c);
            }
    }
    return 0;
}
tTree updateTree(char *c, tTree t){
    free(t->c);
    t->c = strdup(c);
    return t;
}
char* peek(tTree t){
    return t->c;
}
void printTree(tTree t){
    if(!isEmpty(t)){
        printf("%s\n", t->c);
        printTree(t->left); 
        printTree(t->right);
    }
}
tTree freeTree(tTree t){
    if(!isEmpty(t)){
        free(t->c);
        freeTree(t->left); freeTree(t->right);
        free(t);
    }
    return NULL;
}