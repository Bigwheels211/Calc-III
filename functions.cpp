#include "parser.h"

int main(int argc, char** argv){
    char func[] = "53 * 5";
    int num = valueOf(func, 26);
    printf("%d\n", num);
    return num;
}