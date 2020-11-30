#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int main(){
    tCalc c = inicializeCalculator();
    readInput(c);
    makeTree(c);
    printf("Result: %.2f\n", calculate(c));
    freeCalculator(c);
    return 0;
}