/*
 *--------------------------------------
 * File: main.c
 * Author: Garrett Luu
 * Description: Used to demo and test functionality of cuboid library
 *--------------------------------------
 */

/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Standard headers */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* CE Libraries */
#include <keypadc.h>
#include <graphx.h>
#include <fileioc.h>

/* Project header files */
#include "vector.h"
#include "render.h"
#include "matrix.h"

/* Put your function prototypes here */

/* Globals */
vector_t iHat = {1, 0, 0};
vector_t jHat = {0, 1, 0};
vector_t kHat = {0, 0, 1};

vector_t other1 = {1, 0, 1};
vector_t other2 = {0, 2, 3};
vector_t other3 = {-3, 0, -5};

void main(void) {
  // vector_t iHat = newVector(1, 0, 0);
  sk_key_t key;
  pixel_t centerPerspective = {SCREEN_CENTER_X / 2, SCREEN_CENTER_Y};
  pixel_t centerOrthographic = {SCREEN_CENTER_X * 1.5, SCREEN_CENTER_Y};

  transform_t *testTransform;
  transform_t *testTransform2;

  transform_t *testAdd;

  float test1[] = {5, 40};
  float test2[] = {10};

  float testMatrix[] = {2, 0, 0,
                        0, 1, 0,
                        0, 0, 1};

  float testMatrix2[] = {2, 0, 0,
                         0, 1, 0,
                         0, 0, 1};


  prgm_CleanUp();
  gfx_Begin();
  gfx_SetDrawBuffer();

  testTransform = newTransform(testMatrix);
  testTransform2 = newTransform(testMatrix2);

  testAdd = addMatrices(*testTransform, *testTransform2);

  transformVector(&iHat, *testTransform);
  free(testTransform);

  key = os_GetCSC();
  while (key != sk_2nd) {
    key = os_GetCSC();

    gfx_FillScreen(gfx_white);

    drawVector(iHat, 0, centerPerspective, &projectPerspective, test1);
    drawVector(jHat, 0, centerPerspective, &projectPerspective, test1);
    drawVector(kHat, 0, centerPerspective, &projectPerspective, test1);

    drawVector(other1, 0, centerPerspective, &projectPerspective, test1);
    // drawVector(other2, 0, centerPerspective, 2.5, &projectPerspective);
    drawVector(other3, 0, centerPerspective, &projectPerspective, test1);

    drawVector(iHat, 0, centerOrthographic, &projectOrthographic, test2);
    drawVector(jHat, 0, centerOrthographic, &projectOrthographic, test2);
    drawVector(kHat, 0, centerOrthographic, &projectOrthographic, test2);

    drawVector(other1, 0, centerOrthographic, &projectOrthographic, test2);
    // drawVector(other2, 0, centerOrthographic, 10, &projectOrthographic);
    drawVector(other3, 0, centerOrthographic, &projectOrthographic, test2);

    gfx_SwapDraw();

//    if (key == sk_Right) {
      rotateYaw(&iHat, .3);
      rotateYaw(&jHat, .3);
      rotateYaw(&kHat, .3);

      rotateYaw(&other1, .3);
      rotateYaw(&other2, .3);
      rotateYaw(&other3, .3);

      rotatePitch(&iHat, .3);
      rotatePitch(&jHat, .3);
      rotatePitch(&kHat, .3);

      rotatePitch(&other1, .3);
      rotatePitch(&other2, .3);
      rotatePitch(&other3, .3);

      delay(.033);

  }

  gfx_FillScreen(gfx_white);


  while (!os_GetCSC());

  free(&iHat);
  free(&jHat);
  free(&kHat);

  free(&other1);
  free(&other2);
  free(&other3);

  gfx_End();
  prgm_CleanUp();
}

/* Put other functions here */
