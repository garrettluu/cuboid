/*
 *--------------------------------------
 * File: main.c
 * Author: Garrett Luu
 * Description:
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

/* Put your function prototypes here */

/* Globals */
vector_t iHat = {1, 0, 0};
vector_t jHat = {0, 1, 0};
vector_t kHat = {0, 0, 1};

vector_t other1 = {1, 0, 1};
vector_t other2 = {0, 2, 3};
vector_t other3 = {-3, 0, -5};

void main(void) {
  sk_key_t key;

  prgm_CleanUp();
  gfx_Begin();
  gfx_SetDrawBuffer();

  key = os_GetCSC();
  while (key != sk_2nd) {
    key = os_GetCSC();

    gfx_FillScreen(gfx_white);

    drawVector(iHat, 0, &projectOrthographic);
    drawVector(jHat, 0, &projectOrthographic);
    drawVector(kHat, 0, &projectOrthographic);

    // drawVector(other1, gfx_green, &projectOrthographic);
    // drawVector(other2, gfx_green, &projectOrthographic);
    // drawVector(other3, gfx_green, &projectOrthographic);

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

  //Test drawing axes
  // drawVector(iHat, 0);
  // drawVector(jHat, 0);
  // drawVector(kHat, 0);

  gfx_FillScreen(gfx_white);

  //Test rotation
  // rotateYaw(&iHat, 3);
  // rotateYaw(&jHat, 3);
  // rotateYaw(&kHat, 3);

  //Redraw
  // drawVector(iHat, 0);
  // drawVector(jHat, 0);
  // drawVector(kHat, 0);

  while (!os_GetCSC());

  gfx_End();
  prgm_CleanUp();
}

/* Put other functions here */
