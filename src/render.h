#ifndef RENDER_H
#define RENDER_H

#define SCREEN_CENTER_X 160
#define SCREEN_CENTER_Y 120

typedef struct pixel {
  uint16_t x;
  uint16_t y;
} pixel_t;

pixel_t *newPixel(uint16_t x, uint16_t y);
void drawAxes(uint16_t centerX, uint16_t centerY, uint16_t length);

void connect(pixel_t point1, pixel_t point2, uint8_t color);
void drawVector(vector_t vector, uint8_t color, pixel_t center, uint16_t scale,
    pixel_t* (*projection)(vector_t, uint16_t, float, uint16_t, uint16_t));

pixel_t *projectOrthographic(vector_t point, uint16_t scale, float focalLength,
    uint16_t offsetX, uint16_t offsetY);
pixel_t *projectPerspective(vector_t point, uint16_t cameraDist,
    float focalLength, uint16_t offsetX, uint16_t offsetY);

void rotateYaw(vector_t *point, double yaw);
void rotatePitch(vector_t *point, double pitch);
void rotateRoll(vector_t *point, double roll);

#endif
