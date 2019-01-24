#ifndef RENDER_H
#define RENDER_H

typedef struct pixel {
  double x;
  double y;
} pixel_t;

void drawAxes(uint16_t centerX, uint16_t centerY, uint16_t length);
void connect(pixel_t point1, pixel_t point2, uint8_t color);
void drawVector(vector_t vector, uint8_t color);

pixel_t *projectOrthographic(vector_t point, uint16_t scale,
    uint16_t offsetX, uint16_t offsetY);
vector_t rotateEuler(vector_t *point, double alpha, double beta, double gamma);

#endif
