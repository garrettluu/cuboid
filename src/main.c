/*
 *--------------------------------------
 * Program Name:
 * Author:
 * License:
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

/* CE Libraries */
#include <keypadc.h>
#include <graphx.h>
#include <fileioc.h>

#include "vector.h"
#include "render.h"

/* Put your function prototypes here */

/* Put all your globals here */
vector_t iHat = {1, 0, 0};
vector_t jHat = {0, 1, 0};
vector_t kHat = {0, 0, 1};

void main(void) {
  prgm_CleanUp();
  gfx_Begin();

  //Test drawing axes
  drawVector(iHat, 0);
  drawVector(jHat, 0);
  drawVector(kHat, 0);

  while (!os_GetCSC());

  gfx_FillScreen(gfx_white);

  //Test rotation
  rotateYaw(&iHat, 3);
  rotateYaw(&jHat, 3);
  rotateYaw(&kHat, 3);

  //Redraw
  drawVector(iHat, 0);
  drawVector(jHat, 0);
  drawVector(kHat, 0);

  while (!os_GetCSC());

  gfx_End();
  prgm_CleanUp();
}

/* Put other functions here */
