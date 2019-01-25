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
void drawVector(vector_t vector, uint8_t color);

pixel_t *projectOrthographic(vector_t point, uint16_t scale,
    uint16_t offsetX, uint16_t offsetY);
void rotateYaw(vector_t *point, double yaw);

#endif
