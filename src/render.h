#ifndef RENDER_H
#define RENDER_H

#define SCREEN_CENTER_X 160
#define SCREEN_CENTER_Y 120

typedef struct pixel {
  uint16_t x;
  uint16_t y;
} pixel_t;

typedef pixel_t* (*projection_t)(vector_t, pixel_t, float*);

pixel_t *newPixel(uint16_t x, uint16_t y);
void drawAxes(pixel_t center, uint16_t length, projection_t projection,
    float *params);

void connect(pixel_t point1, pixel_t point2, uint8_t color);
void drawVector(vector_t vector, uint8_t color, pixel_t center,
    projection_t projection, float *params);

pixel_t *projectOrthographic(vector_t point, pixel_t origin, float *params);
pixel_t *projectPerspective(vector_t point, pixel_t origin, float *params);

void rotateYaw(vector_t *point, double yaw);
void rotatePitch(vector_t *point, double pitch);
void rotateRoll(vector_t *point, double roll);

#endif
