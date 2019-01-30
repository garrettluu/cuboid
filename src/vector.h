#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector {
  float x;
  float y;
  float z;
} vector_t;

static const vector_t basisX = {1, 0, 0};
static const vector_t basisY = {0, 1, 0};
static const vector_t basisZ = {0, 0, 1};

vector_t *newVector(float x, float y, float z);
vector_t *add(vector_t v1, vector_t v2);
vector_t *subtract(vector_t v1, vector_t v2);
double dot(vector_t v1, vector_t v2);
vector_t *cross(vector_t v1, vector_t v2);
vector_t *normalize(vector_t vector);
float length(vector_t vector);
float distance(vector_t v1, vector_t v2);
  
#endif
