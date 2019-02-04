/*
 *--------------------------------------
 * File: vector.c
 * Author: Garrett Luu
 * Description: Implementation of a vector structure, representing a point in
 *     three-dimensional space
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

vector_t *newVector(float xCoord, float yCoord, float zCoord) {
  vector_t *vector = (vector_t *) malloc(sizeof(vector_t));
  vector->x = xCoord;
  vector->y = yCoord;
  vector->z = zCoord;
  return vector;
}

vector_t *newVectorFromArray(float *components) {
  vector_t *vector = (vector_t *) malloc(sizeof(vector_t));
  vector->x = *components;
  vector->y = *(components + 1);
  vector->z = *(components + 2);
  return vector;
}

vector_t *add(vector_t v1, vector_t v2) {
  vector_t sum;
  sum.x = v1.x + v2.x;
  sum.y = v1.y + v2.y;
  sum.z = v1.z + v2.z;
  return &sum;
}

vector_t *subtract(vector_t v1, vector_t v2) {
  vector_t diff;
  diff.x = v1.x - v2.x;
  diff.y = v1.y - v2.y;
  diff.z = v1.z - v2.z;
  return &diff;
}

double dot(vector_t v1, vector_t v2) {
  return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

vector_t *cross(vector_t v1, vector_t v2) {
  vector_t cross;
  cross.x = ((v1.y * v2.z) - (v2.y * v1.z));
  cross.y = -((v1.x * v2.z) - (v2.x * v1.z));
  cross.z = (v1.x * v2.y) - (v2.x * v1.y);
  return &cross;
}

vector_t *normalize(vector_t vector) {
  float norm = length(vector);
  vector_t unit;
  unit.x = vector.x / norm;
  unit.y = vector.y / norm;
  unit.z = vector.z / norm;
  return &unit;
}

float length(vector_t vector) {
  float result = sqrt(dot(vector, vector));
  return result;
}

float distance(vector_t v1, vector_t v2) {
  vector_t *diff = subtract(v1, v2);
  float result = length(*diff);
  free(&diff);
  return result;
}
