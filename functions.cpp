#include "parser.h"

int main(int argc, char** argv){
    char func[] = "5 + 3 * (3 + 4)";
    int num = valueOfString(func);
    printf("%d\n", num);
    return num;
}