/*
 *--------------------------------------
 * File: matrix.c
 * Author: Garrett Luu
 * Description:
 *--------------------------------------
 */

/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Standard headers (recommended) */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"
#include "matrix.h"

transform_t *newTransform(float *elements) {
  transform_t *transform = (transform_t*) malloc(sizeof(transform_t));
  transform->matrix = elements;
  return transform;
}

/*
 * Takes a vector and applies a linear transformation
 * NOTE: This modifies the value of the original vector, so use with caution
 *
 * vector: vector to be transformed
 */
void transformVector(vector_t *vector, transform_t transform) {
  vector_t original = *vector;
  vector->x = (original.x * (*(transform.matrix))) +
      (original.y * (*(transform.matrix + 1))) +
      (original.z * (*(transform.matrix + 2)));
  vector->y = (original.x * (*(transform.matrix + 3))) +
      (original.y * (*(transform.matrix + 4))) +
      (original.z * (*(transform.matrix + 5)));
  vector->z = (original.x * (*(transform.matrix + 6))) +
      (original.y * (*(transform.matrix + 7))) +
      (original.z * (*(transform.matrix + 8)));
  free(&original);
}

transform_t *compose(transform_t t1, transform_t t2) {
  transform_t *result = (transform_t *) malloc(sizeof(transform_t));
  //TODO: matrix multiplication algorithm
  return result;
}
