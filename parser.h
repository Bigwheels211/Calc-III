#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
enum tokenType{number,letter,plus,minus,multiply,divide,openpar,closepar,exp};
struct token {
    tokenType type;
    char at;
};
struct advtoken {
    tokenType type;
    char at;
    int value;
};
struct basicequation {
    token* tokens;
    int numTokens;
};
struct advequation {
    advtoken* tokens;
    int numTokens;
};
struct numberToken {
    int value;
    int length;
};
int numTokens(char func[]){ // counts the number of regular tokens in a function
    int numOfTokens = 0; 
    for (int i = 0; func[i] != '\0'; i++){
        if (func[i] != ' '){
            numOfTokens ++;
        }
    }
    return numOfTokens;
}
basicequation makeTokenList(char func[], int length){ // returns an equation created from the func input
    int numToken = numTokens(func);
    token* tokens = static_cast<token*>(malloc(numToken * sizeof(token)));
    int j = 0;
    for (int i = 0; i < length; i++){
        if (func[i] != ' '){
            tokens[j].at = func[i];
            if (func[i] == '+'){
            tokens[j].type= tokenType::plus; 
            } else if (func[i] == '-'){
            tokens[j].type= tokenType::minus; 
            } else if (func[i] == '*'){
            tokens[j].type= tokenType::multiply; 
            } else if (func[i] == '/'){
            tokens[j].type= tokenType::divide; 
            } else if (isdigit(func[i])){
            tokens[j].type= tokenType::number;
            } else if (func[i] == '^'){
            tokens[j].type= tokenType::exp; 
            } else if (func[i] == '('){
            tokens[j].type= tokenType::openpar; 
            } else if (func[i] == ')'){
            tokens[j].type= tokenType::closepar;
            }else if (isalpha(func[i])){
            tokens[j].type= tokenType::letter;
            }
            j++;
        }
    }
    basicequation theEqu;
    theEqu.tokens = tokens;
    theEqu.numTokens = numToken;
    return theEqu;
}
numberToken checkNumbers(basicequation theEqu, int numIndex){ //Returns the values of all of the number tokens that are in a row
    numberToken theNumber;
    token* tokens = theEqu.tokens;
    bool isNextNum = true;
    int lengthOfNums = 0;
    while (isNextNum){
        if (tokens[numIndex + lengthOfNums].type == number && numIndex + lengthOfNums < theEqu.numTokens){
            lengthOfNums++;
        } else{
            isNextNum = false;
        }
    }
    theNumber.length = lengthOfNums;
    int result = 0;
    for (int i = 0; i < lengthOfNums; i++){
        result += (tokens[numIndex + lengthOfNums - (i + 1)].at - '0')* (int) pow(10, i);
    }
    theNumber.value = result;
    return theNumber;
}
advequation makeadvequn(basicequation theEqu){ //Turns an equation from a basic to an advanced equation(combines all of the numbers from individual tokens to advanced tokens with integer values)
    token* basictokens = theEqu.tokens;
    int numbasic = theEqu.numTokens;
    int advLength = 0;
    advtoken* advtokens = static_cast<advtoken*>(malloc(1 * sizeof(advtoken)));
    for (int i = 0; i < numbasic; i++){
        advLength++;
        realloc(advtokens,advLength * sizeof(advtoken));
        if (basictokens[i].type != number){
            advtokens[advLength - 1].at = basictokens[i].at;
            advtokens[advLength - 1].type = basictokens[i].type;
        } else {
            numberToken theNumber = checkNumbers(theEqu, i);
            advtokens[advLength - 1].type = number;
            advtokens[advLength - 1].value = theNumber.value;
            i += theNumber.length - 1;
        }
    }
    advequation theadvequ;
    theadvequ.numTokens = advLength;
    theadvequ.tokens = advtokens;
    return theadvequ;
}
int add(advtoken num1, advtoken num2){ //adds the value of 2 number tokens (No safeties (Gotta fix that))
    return num1.value + num2.value;
}
int subtract(advtoken num1, advtoken num2){ //subtracts the value of 2 number tokens (No safeties (Gotta fix that))
    return num1.value - num2.value;
}
int multiply(advtoken num1, advtoken num2){ //multiplies the value of 2 number tokens (No safeties (Gotta fix that))
    return num1.value * num2.value;
}
int divide(advtoken num1, advtoken num2){ //divides the value of 2 number tokens (No safeties (Gotta fix that))
    return num1.value / num2.value;
}
int valueOf(char func[], int length){
    basicequation theEqu = makeTokenList(func,length);
    token* tokens = theEqu.tokens;
    for (int i = 0; i < theEqu.numTokens; i++){
        printf("current index being checked: %d\n", i);
        if (tokens[i].type == number){
            numberToken theNum = checkNumbers(theEqu, i);
            i += theNum.length - 1;
        }
    }
    free(theEqu.tokens);
    return 0;
}