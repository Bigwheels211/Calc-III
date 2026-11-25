#include "parser.h"

int main(int argc, char** argv){
    char func[] = "713531 + 95 +12378-7554563";
    int num = valueOf(func, 26);
    return 0;
}