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

char *shunt(char *infix) {

}

double parse(char *rpn) {

}
