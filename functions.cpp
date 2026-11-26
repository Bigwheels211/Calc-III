#include "parser.h"

int main(int argc, char** argv){
    char func[] = "5x^2";
    int input = 3;
    char variable = 'x';
    int num = valueOfStrFunction(func, input,variable);
    printf("%d\n", num);
    return num;
}