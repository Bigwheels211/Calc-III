#include "parser.h"

int main(int argc, char** argv){
    char func[] = "60 / -1*(x10)";
    int input = 3;
    char variable = 'x';
    int num = valueOfStrFunction(func, input,variable);
    //int num = valueOfString(func);
    printf("%d\n", num);
    return num;
}