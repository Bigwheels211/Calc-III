#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h> 
#include "parser.h"

void derivitive(int arr[], int size){
    arr[0] = 0;
    for (int i = 1; i < size; i++){
        arr[i] = 0;
    }
}
int main(int argc, char** argv){
    char func[] = "713531 + 95 +12378-7554563";
    int num = valueOf(func, 26);
    return 0;
}