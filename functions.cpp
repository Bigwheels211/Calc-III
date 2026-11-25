#include "parser.h"

int main(int argc, char** argv){
    char func[] = "53 * 5 + 10 + 15213 + 1248172 + 2^10";
    int num = valueOf(func, 26);
    printf("%d\n", num);
    return num;
}