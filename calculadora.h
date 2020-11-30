#ifndef CALCULADORA
#define CALCULADORA
typedef struct calculator *tCalc;
tCalc inicializeCalculator();
void readInput(tCalc);
void makeTree(tCalc);
float calculate(tCalc);
void freeCalculator(tCalc);
#endif