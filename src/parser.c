/*
 *--------------------------------------
 * File: parser.c
 * Author: Garrett Luu
 * Description: Infix and postfix expression parser
 *--------------------------------------
 */

/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Standard headers */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

RPNStack_t *makeRPNStack(uint8_t capacity) {
  RPNStack_t *stack = malloc(sizeof(RPNStack_t));
  stack->elements = malloc(capacity * sizeof(double));
  stack->capacity = capacity;
  stack->size = 0;
  return stack;
}

void pushRPN(RPNStack_t *stack, double value) {
  stack->elements[stack->size] = value;
  stack->size++;
}

double popRPN(RPNStack_t *stack) {
  stack->size--;
  return stack->elements[stack->size];
}

void freeRPNStack(RPNStack_t *stack) {
  free(stack->elements);
  free(stack);
}

char *shunt(char *infix) {

}

double parse(char *rpn) {
  char tok;
  char *tokens;

  char *e, *delim = " ";

  char* rpnCpy;
  double a, b;
  double result;

  RPNStack_t* stack = makeRPNStack(10);

  strcpy(rpnCpy, rpn);
  for(tokens = strtok(rpnCpy, delim); tokens;  tokens = strtok(NULL, delim)) {
    a = strtod(tokens, &e);
    tok = *tokens;

    //If the token is not an operator
    if (e > tokens && tok != '+' && tok != '-' && tok != '/' && tok != '*' &&
        tok != '^' && tok != 'x' && tok != 'y' ) {
      pushRPN(stack, a);
    } else if (tok == '+') {
      b = popRPN(stack);
      a = popRPN(stack);
      pushRPN(stack, a + b);
    } else if (tok == '-') {
      b = popRPN(stack);
      a = popRPN(stack);
      pushRPN(stack, a - b);
    } else if (tok == '*') {
      b = popRPN(stack);
      a = popRPN(stack);
      pushRPN(stack, a * b);
    } else if (tok == '/') {
      b = popRPN(stack);
      a = popRPN(stack);
      pushRPN(stack, a / b);
    } else if (tok == '^') {
      b = popRPN(stack);
      a = popRPN(stack);
      pushRPN(stack, pow(a, b));
    } else if (strcmp(tokens, "sin")) {
      b = popRPN(stack);
      pushRPN(stack, sin(b));
    } else if (strcmp(tokens, "cos")) {
      b = popRPN(stack);
      pushRPN(stack, cos(b));
    }
  }
  result = popRPN(stack);
  freeRPNStack(stack);
  return result;
}
