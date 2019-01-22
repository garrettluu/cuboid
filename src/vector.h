#ifndef VECTOR_H
#define VECTOR_H

vector_t *newVector(double x, double y, double z);
vector_t *add(vector_t *v1, vector_t *v2);
vector_t *subtract(vector_t *v1, vector_t *v2);
double dot(vector_t *v1, vector_t *v2);
vector_t *cross(vector_t v1, vector_t v2);

#endif
