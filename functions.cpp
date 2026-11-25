#include "parser.h"

int main(int argc, char** argv){
    char func[] = "53 * 5 + 2 + 2^10";
    int num = valueOf(func);
    printf("%d\n", num);
    return num;
}