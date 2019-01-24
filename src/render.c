/*
 *--------------------------------------
 * File: render.c
 * Author: Garrett Luu
 * Description: Handles rendering and drawing elements
 *--------------------------------------
 */

/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* GraphX library */
#include <graphx.h>

/* Standard headers */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Vectors */
#include "vector.h"

#include "render.h"

void drawAxes(uint16_t centerX, uint16_t centerY, uint16_t length) {
  //TODO: Add x, y, z axes;
}

/* Connects two pixels together with a line */
void connect(pixel_t point1, pixel_t point2, uint8_t color) {
  gfx_SetColor(color);
  gfx_Line(point1.x, point1.y, point2.x, point2.y);
}

void drawVector(vector_t vector, uint8_t color) {
  uint16_t test = 100;
  //TODO: Assign something to start
  pixel_t start;
  pixel_t *end = projectOrthographic(vector, test, test, test);
  connect(start, *end, color);
}

/* Orthographically projects the given 3d vector onto the 2d plane */
pixel_t *projectOrthographic(vector_t point, uint16_t scale,
    uint16_t offsetX, uint16_t offsetY) {
  pixel_t result;
  result.x = scale * point.x + offsetX;
  result.y = scale * point.z + offsetY;
  return &result;
}

vector_t rotateEuler(vector_t *point, double alpha, double beta, double gamma) {
    vector_t result;
    return result;
}
