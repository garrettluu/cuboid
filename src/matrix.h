#ifndef MATRIX_H
#define MATRIX_H

typedef struct transformation {
  float *matrix;
} transform_t;

transform_t *newTransform(float *elements);

void tranformVector(vector_t *vector, transform_t transform);

#endif
