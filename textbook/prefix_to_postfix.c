/*
 * convert prefix to post fix expression 
 * from "Data Structures: A Pseudocode Approach with C"
 */

#include<stdio.h>
#include<string.h>

#define OPERATORS "+-*/"

// prototype declaration
void prefixToPostfix(char* prefixIn, char* postfixOut);
int findExprLen(char* exprIn);

int main(void) {
// loacl definition
    char prefixExpr[256];
    char postfixExpr[256] = "";

// statements
    printf("==========\n\n");

    printf("Enter a proper prefix expression: ");
    scanf("%255s", prefixExpr);
    prefixToPostfix(prefixExpr, postfixExpr);
    printf("Result: ");
    printf("%s\n", postfixExpr);

    printf("==========\n\n");

    return 0;
}

/* ================ prefixToPostfix ================
 * convert prefix expression to postfix format
 *     pre:  prefixIn is string prefix expression,
 *           expression can contain no errors/spaces
 *           postfixOut is string variable for postfix result
 *     post: expression has been converted
 */
void prefixToPostfix(char* prefixIn, char* postfixOut) {
// local definition
    char operator[2];
    char postfix1[256];
    char postfix2[256];
    char temp[256];
    int lenPrefix;

// base case: if only one operand
    if(strlen(prefixIn) == 1) {
        *postfixOut = *prefixIn;
        *(postfixOut + 1) = '\0';
        return;
    }

// general case:
    *operator = *prefixIn;
    *(operator + 1) = '\0';

    // find first expression
    lenPrefix = findExprLen(prefixIn + 1);
    strncpy(temp, (prefixIn + 1), lenPrefix);
    *(temp + lenPrefix) = '\0';
    prefixToPostfix(temp, postfix1);

    // find second expression
    strcpy(temp, (prefixIn + 1 + lenPrefix));
    prefixToPostfix(temp, postfix2);
    
    // concatenate to postfixOut
    strcpy(postfixOut, postfix1);
    strcat(postfixOut, postfix2);
    strcat(postfixOut, operator);

    return;
}

/* =============== findExprLen ===============
 * determine size of first substring in an expression
 *     pre:  exprIn contains prefix expression
 *     post: size of expression is returned
 */
int findExprLen(char* exprIn) {
// local definition
    int len1, len2;

// general case:
    // if 1st char is an operator
    if(strcspn(exprIn, OPERATORS) == 0) {
        // find length of 1st expression
        len1 = findExprLen(exprIn + 1);

        // find length of 2nd expression
        len2 = findExprLen(exprIn + 1 + len1);
    }
// base case:
    // 1st char is an operand
    else {
        len1 = len2 = 0;
    }

    return len1 + len2 + 1;
}