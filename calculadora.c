#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv.h"
#include "calculadora.h"
#define MAX_TAM 1000
typedef struct type{
    char* expression;
    int height;
}*tType;
tType inicializetType(char* exp, int height){
    tType new = malloc(sizeof(struct type));
    new->expression = strdup(exp);
    new->height = height;
    return new;
}
struct calculator{
    tTree root;
    tType* summarized;
    int numExpressions, height;
};
tCalc inicializeCalculator(){
    tCalc new = malloc(sizeof(struct calculator));
    new->summarized = malloc(sizeof(struct type)*MAX_TAM);
    new->numExpressions = new->height = 0;
    return new;
}
void readInput(tCalc c){
    char expression[MAX_TAM];
    scanf("%s%*c", expression);
    int cont = 0, j = 0;
    char aux[MAX_TAM];
    for(int i = 0; i < strlen(expression); i += j + 1, j = 0){
        if(expression[i] == '(')
            cont++;
        if(expression[i] == ')')
            cont--;
        if(expression[i] >= '1' && expression[i] <= '9'){
            aux[0] = expression[i];
            for(j = 0;  ;j++){
                if(expression[j + i + 1] >= '0' && expression[j + i + 1] <= '9'){
                    aux[j+1] = expression[j + i + 1];
                }
                else{
                    break;
                }
            }
            aux[j+1] = '\0';
            c->summarized[c->numExpressions++] = inicializetType(aux, cont);
            if(cont > c->height){
                c->height = cont;
            }
            printf("Num: %s\n", aux);
        }
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '/' || expression[i] == '*'){
            aux[0] = expression[i];
            aux[1] = '\0';
            c->summarized[c->numExpressions++] = inicializetType(aux, cont);
            if(cont > c->height){
                c->height = cont;
            }
            printf("Op: %s\n", aux);
        }
    }
}
void createTree(tTree t, int n, tType* exp, int pos, int lim){
    int left = -1, right = -1;
    for(int i = pos-1; i >= 0; i--){
        if(exp[i]->height == n){
            left = i;
            break;
        }
    }
    for(int i = pos+1; i < lim; i++){
        if(exp[i]->height == n){
            right = i;
            break;
        }
    }
    if(right >= 0 && left >= 0){
        tTree x = inicializeTree(exp[left]->expression);
        AddLeft(x, t);
        createTree(x, n + 1, exp, left, lim);

        tTree y = inicializeTree(exp[right]->expression);
        AddRight(y, t);
        createTree(y, n + 1, exp, right, lim);
    }
}
void makeTree(tCalc c){
    int x = 0;
    for(int i = 0; i < c->numExpressions; i++){
        if(c->summarized[i]->height == 1){
            c->root = inicializeTree(c->summarized[i]->expression);
            x = i;
            break;
        }
    }
    createTree(c->root, 2, c->summarized, x, c->numExpressions);
    printTree(c->root);
}
float calculate(tCalc c){
    return evaluate(c->root);
}
void freeCalculator(tCalc c){
    for(int i = 0; i < c->numExpressions; i++){
        free(c->summarized[i]->expression);
        free(c->summarized[i]);
    }
    free(c->summarized);
    c->root = freeTree(c->root);
    free(c);
}
