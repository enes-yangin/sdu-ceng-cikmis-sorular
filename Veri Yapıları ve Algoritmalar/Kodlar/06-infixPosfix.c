#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

/*
 * CharStack structure and its operations:
 * This stack is used to hold operators during infix to postfix conversion.
 */
typedef struct {
    char items[MAX];
    int top;
} CharStack;

/*
 * initCharStack: Initializes the character stack.
 * Explanation: This function sets the top index of the stack to -1, indicating an empty stack.
 */
void initCharStack(CharStack *s) {
    s->top = -1;
}

/*
 * isEmptyChar: Checks if the character stack is empty.
 * Explanation: Returns 1 (true) if the stack is empty, 0 (false) otherwise.
 */
int isEmptyChar(CharStack *s) {
    return s->top == -1;
}

/*
 * pushChar: Pushes a character onto the stack.
 * Explanation: This function adds an element to the top of the stack, and exits if the stack is full.
 */
void pushChar(CharStack *s, char c) {
    if(s->top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = c;
}

/*
 * popChar: Pops a character from the stack.
 * Explanation: This function removes and returns the top element of the stack. If the stack is empty, it exits.
 */
char popChar(CharStack *s) {
    if(isEmptyChar(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

/*
 * peekChar: Returns the top element of the stack without removing it.
 * Explanation: If the stack is empty, it returns a null character.
 */
char peekChar(CharStack *s) {
    if(isEmptyChar(s)) {
        return '\0';
    }
    return s->items[s->top];
}

/*
 * IntStack structure and its operations:
 * This stack is used to hold integer operands during postfix expression evaluation.
 */
typedef struct {
    int items[MAX];
    int top;
} IntStack;

/*
 * initIntStack: Initializes the integer stack.
 * Explanation: Sets the top index to -1, indicating an empty stack.
 */
void initIntStack(IntStack *s) {
    s->top = -1;
}

/*
 * isEmptyInt: Checks if the integer stack is empty.
 * Explanation: Returns 1 (true) if the stack is empty, 0 (false) otherwise.
 */
int isEmptyInt(IntStack *s) {
    return s->top == -1;
}

/*
 * pushInt: Pushes an integer onto the stack.
 * Explanation: This function adds an integer to the top of the stack, and exits if the stack is full.
 */
void pushInt(IntStack *s, int val) {
    if(s->top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = val;
}

/*
 * popInt: Pops an integer from the stack.
 * Explanation: This function removes and returns the top integer from the stack. If the stack is empty, it exits.
 */
int popInt(IntStack *s) {
    if(isEmptyInt(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

/*
 * isOperator: Checks whether a given character is an operator.
 * Explanation: Returns 1 (true) if the character is one of '+', '-', '*', '/', or '^'; otherwise returns 0 (false).
 */
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

/*
 * precedence: Returns the precedence of the given operator.
 * Explanation: Higher numerical values indicate higher precedence.
 *   '^' has the highest precedence, followed by '*' and '/' and finally '+' and '-'.
 */
int precedence(char op) {
    if(op == '^')
        return 3;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    else
        return 0;
}

/*
 * infixToPostfix: Converts an infix expression to a postfix expression.
 * Explanation: This function uses the Shunting-yard algorithm. It iterates over each character:
 *   - If the character is an operand, it is added to the output.
 *   - If it is an opening parenthesis, it is pushed to the stack.
 *   - If it is a closing parenthesis, operators are popped until an opening parenthesis is found.
 *   - If it is an operator, operators with higher or equal precedence are popped from the stack before pushing the current operator.
 */
void infixToPostfix(char *infix, char *postfix) {
    CharStack s;
    initCharStack(&s);
    int i = 0, k = 0;
    char ch;
    
    while(infix[i] != '\0') {
        ch = infix[i];
        
        // If the character is an operand, add it directly to the postfix expression.
        if(isalnum(ch)) {
            postfix[k++] = ch;
        }
        // If the character is an opening parenthesis, push it onto the stack.
        else if(ch == '(') {
            pushChar(&s, ch);
        }
        // If the character is a closing parenthesis, pop until an opening parenthesis is encountered.
        else if(ch == ')') {
            while(!isEmptyChar(&s) && peekChar(&s) != '(') {
                postfix[k++] = popChar(&s);
            }
            if(!isEmptyChar(&s) && peekChar(&s) == '(')
                popChar(&s); // Remove the '(' from the stack.
        }
        // If the character is an operator.
        else if(isOperator(ch)) {
            while(!isEmptyChar(&s) && isOperator(peekChar(&s)) &&
                  ((precedence(ch) < precedence(peekChar(&s))) ||
                  (precedence(ch) == precedence(peekChar(&s)) && ch != '^'))) {
                postfix[k++] = popChar(&s);
            }
            pushChar(&s, ch);
        }
        i++;
    }
    
    // Pop any remaining operators from the stack and append them to the postfix expression.
    while(!isEmptyChar(&s)) {
        postfix[k++] = popChar(&s);
    }
    postfix[k] = '\0'; // Null-terminate the postfix expression.
}

/*
 * evaluatePostfix: Evaluates a postfix expression and returns the result.
 * Explanation: This function uses an integer stack to process the postfix expression.
 *   - When an operand is encountered, it is pushed onto the stack.
 *   - When an operator is encountered, the top two operands are popped, the operation is performed,
 *     and the result is pushed back onto the stack.
 *   - At the end, the stack contains the final result.
 * Note: This implementation assumes that the operands are single-digit numbers.
 */
int evaluatePostfix(char *postfix) {
    IntStack s;
    initIntStack(&s);
    int i = 0;
    char ch;
    int op1, op2;
    
    while(postfix[i] != '\0') {
        ch = postfix[i];
        // If the character is a digit, convert it to an integer and push onto the stack.
        if(isdigit(ch)) {
            pushInt(&s, ch - '0');
        }
        // If the character is an operator, pop two operands, apply the operator, and push the result.
        else if(isOperator(ch)) {
            op2 = popInt(&s);
            op1 = popInt(&s);
            switch(ch) {
                case '+': pushInt(&s, op1 + op2); break;
                case '-': pushInt(&s, op1 - op2); break;
                case '*': pushInt(&s, op1 * op2); break;
                case '/': pushInt(&s, op1 / op2); break;
                case '^': pushInt(&s, (int)pow(op1, op2)); break;
            }
        }
        i++;
    }
    // The final result is the only remaining element on the stack.
    return popInt(&s);
}

/*
 * main: Demonstrates the infix to postfix conversion and postfix evaluation.
 * Explanation: Reads an infix expression from the user, converts it to a postfix expression,
 * evaluates the postfix expression, and prints both the converted expression and the evaluation result.
 */
int main() {
    char infixExp[MAX];
    char postfixExp[MAX];
    
    printf("Enter an infix expression (use single-digit operands): ");
    scanf("%s", infixExp);
    
    // Convert the infix expression to postfix.
    infixToPostfix(infixExp, postfixExp);
    printf("Postfix expression: %s\n", postfixExp);
    
    // Evaluate the postfix expression.
    int result = evaluatePostfix(postfixExp);
    printf("Evaluation result: %d\n", result);
    
    return 0;
}

