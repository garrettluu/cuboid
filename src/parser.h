#ifndef PARSER_H
#define PARSER_H

typedef struct RPNStack {
  double *elements;
  uint8_t size;
  uint8_t capacity;
} RPNStack_t;

RPNStack_t *makeRPNStack(uint8_t capacity);
void pushRPN(RPNStack_t *stack, double value);
double popRPN(RPNStack_t *stack);
void freeRPNStack(RPNStack_t *stack);

char *shunt(char *infix);
double parse(char *rpn);

#endif
