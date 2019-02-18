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
  //Copy the original vector
  vector_t original = *vector;
  //Matrix multiplication between 3x3 and 1x3 matrices
  vector->x = (original.x * (*(transform.matrix))) +
      (original.y * (*(transform.matrix + 1))) +
      (original.z * (*(transform.matrix + 2)));
  vector->y = (original.x * (*(transform.matrix + 3))) +
      (original.y * (*(transform.matrix + 4))) +
      (original.z * (*(transform.matrix + 5)));
  vector->z = (original.x * (*(transform.matrix + 6))) +
      (original.y * (*(transform.matrix + 7))) +
      (original.z * (*(transform.matrix + 8)));
  //Destroy the original vector
  free(&original);
}
//
transform_t *compose(transform_t transform1, transform_t transform2) {
  transform_t *result;
  // *(result->matrix) = {*(transform1.matrix) * *(transform2.matrix) + *(&(transform1.matrix) + 3)

  // TODO: matrix multiplication algorithm
  return result;
}

transform_t *addMatrices(transform_t transform1, transform_t transform2) {
  transform_t result;
  *(result.matrix) = *(transform1.matrix) + *(transform2.matrix);
  *(result.matrix + 1) = *(transform1.matrix + 1) + *(transform2.matrix + 1);
  *(result.matrix + 2) = *(transform1.matrix + 2) + *(transform2.matrix + 2);

  *(result.matrix + 3) = *(transform1.matrix + 3) + *(transform2.matrix + 3);
  *(result.matrix + 4) = *(transform1.matrix + 4) + *(transform2.matrix + 4);
  *(result.matrix + 5) = *(transform1.matrix + 5) + *(transform2.matrix + 5);

  *(result.matrix + 6) = *(transform1.matrix + 6) + *(transform2.matrix + 6);
  *(result.matrix + 7) = *(transform1.matrix + 7) + *(transform2.matrix + 7);
  *(result.matrix + 8) = *(transform1.matrix + 8) + *(transform2.matrix + 8);
  return &result;
}
