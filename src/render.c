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
#include <keypadc.h>
#include <graphx.h>
#include <fileioc.h>

/* Standard headers */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Project header files */
#include "vector.h"
#include "render.h"

static const pixel_t center = {SCREEN_CENTER_X, SCREEN_CENTER_Y};

pixel_t *newPixel(uint16_t x, uint16_t y) {
  pixel_t result;
  result.x = x;
  result.y = y;
  return &result;
}

void drawAxes(uint16_t centerX, uint16_t centerY, uint16_t length) {

}

/* Connects two pixels together with a line */
void connect(pixel_t point1, pixel_t point2, uint8_t color) {
  gfx_SetColor(color);
  gfx_Line(point1.x, point1.y, point2.x, point2.y);
}

/* Draws a vector */
void drawVector(vector_t vector, uint8_t color,
    pixel_t* (*projection)(vector_t, uint16_t, float, uint16_t, uint16_t)) {
  uint16_t test = 10;
  pixel_t *start = &center;
  pixel_t *end = (projection)(vector, test, test, SCREEN_CENTER_X,
      SCREEN_CENTER_Y);
  connect(*start, *end, color);
  free(end);
}

/*
 * Orthographically projects the given 3d vector onto the 2d plane
 *
 * point: the vector to be projected
 * scale: how many pixels each unit in the 3d world takes up
 * offsetX and offsetY: where to draw the center
 */
pixel_t *projectOrthographic(vector_t point, uint16_t scale, float focalLength,
    uint16_t offsetX, uint16_t offsetY) {
  pixel_t result;
  result.x = scale * point.x + offsetX;
  result.y = -scale * point.z + offsetY;
  return &result;
}

/*
 * Perspectively projects the given 3d vector onto the 2d plane
 *
 * point: the vector to be projected
 * camera: the location of the camera
 * scale: how many pixels each unit in the 3d world takes up
 * offsetX and offsetY: where to draw the center
 */
pixel_t *projectPerspective(vector_t point, uint16_t cameraDist,
    float focalLength, uint16_t offsetX, uint16_t offsetY) {
  pixel_t result;
  result.x = point.x * (focalLength / (point.z + cameraDist));
  result.y = point.y * (focalLength / (point.z + cameraDist));
  return &result;
}

/*
 * Rotates a vector about the z-axis by a certain number of radians
 * NOTE: This modifies the values of the input vector, so use with caution
 *
 * point: the pointer to the vector to be rotated
 * yaw: the number of radians to rotate
 */
void rotateYaw(vector_t *point, double yaw) {
  vector_t original = *point;
  (*point).x = (original.x * cos(yaw)) - (original.y * sin(yaw));
  (*point).y = (original.x * sin(yaw)) + (original.y * cos(yaw));
  (*point).z = original.z;
  free(&original);
}

/*
 * Rotates a vector about the x-axis by a certain number of radians
 * NOTE: This modifies the values of the input vector, so use with caution
 *
 * point: the pointer to the vector to be rotated
 * pitch: the number of radians to rotate
 */
void rotatePitch(vector_t *point, double pitch) {
  vector_t original = *point;
  (*point).x = original.x;
  (*point).y = (original.y * cos(pitch)) - (original.z * sin(pitch));
  (*point).z = (original.y * sin(pitch)) + (original.z * cos(pitch));
  free(&original);
}

/*
 * Rotates a vector about the y-axis by a certain number of radians
 * NOTE: This modifies the values of the input vector, so use with caution
 *
 * point: the pointer to the vector to be rotated
 * roll: the number of radians to rotate
 */
void rotateRoll(vector_t *point, double roll) {
  //TODO: update the calculation for roll
  vector_t original = *point;
  (*point).x = original.x;
  (*point).y = (original.y * cos(roll)) - (original.z * sin(roll));
  (*point).z = (original.y * sin(roll)) + (original.z * cos(roll));
  free(&original);
}
