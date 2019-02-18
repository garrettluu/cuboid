#ifndef MATRIX_H
#define MATRIX_H

typedef struct transformation {
  float *matrix;
} transform_t;

transform_t *newTransform(float *elements);

void transformVector(vector_t *vector, transform_t transform);

transform_t *compose(transform_t transform1, transform_t transform2);

transform_t *addMatrices(transform_t transform1, transform_t transform2);

#endif
