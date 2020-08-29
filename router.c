#include <stdio.h>
#include <stdlib.h>
#include "map.c"

#define HEIGHT 4
#define WIDTH 4
#define LETRA_A 65

void build_position(Position *position, int x, int y, char label) {
  position->value = '+';
  position->label = label;
  position->x = x;
  position->y = y;
}

void build_map(Map *map) {

  map->size = HEIGHT * WIDTH;
  map->positions = (Position *)malloc(map->size*sizeof(Position));
  char label = LETRA_A;
  int index = 0;

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      build_position(&map->positions[index++], i, j, label++); 
    }
  }
}

int main() {

  Map map;
  build_map(&map);
}
