#include <stdio.h>
#include <stdlib.h>
#include "map.c"

#define HEIGHT 4
#define WIDTH 4
#define LETTER_A 65

void build_position(Position *position, int x, int y, char label) {
  position->value = '+';
  position->label = label;
  position->x = x;
  position->y = y;
}

void build_map(Map *map) {

  map->size = HEIGHT * WIDTH;
  map->positions = (Position *)malloc(map->size*sizeof(Position));
  char label = LETTER_A;
  int index = 0;

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      build_position(&map->positions[index++], i, j, label++); 
    }
  }
}

int is_on_list(Map *open_list, char label) {

  for (int i = 0; i < open_list->size; i++) {
    if(open_list->positions[i].label == label) {
      return 1;
    }
  }
  return 0;

}

void add_position_to_list(Map *list, Position *position) {
  list->size++;
  list->positions = realloc(list->positions, list->size*(sizeof(Position)));
  list->positions[list->size-1].label = position->label;
  list->positions[list->size-1].value = position->value;
  list->positions[list->size-1].x = position->x;
  list->positions[list->size-1].y = position->y;
}

void find_neighbors(char from, Map *map, Map *open_list) {

  for (int i = 0; i < map->size; i++) {
    if (map->positions[i].label == from && !is_on_list(open_list, map->positions[i].label)) {
      for (int j = 0; j < map->size; j++) {
        if(map->positions[i].x == map->positions[j].x && 
           map->positions[i].y == map->positions[j].y-1 && 
          !is_on_list(open_list, map->positions[j].label)) {
          add_position_to_list(open_list, &map->positions[j]);
        } 
        else if (map->positions[i].x == map->positions[j].x &&
                 map->positions[i].y == map->positions[j].y+1 && 
          !is_on_list(open_list, map->positions[j].label)) {
          add_position_to_list(open_list, &map->positions[j]);
        } 
        else if(map->positions[i].y == map->positions[j].y && 
                map->positions[i].x == map->positions[j].x-1 && 
          !is_on_list(open_list, map->positions[j].label)) {
          add_position_to_list(open_list, &map->positions[j]);
        }  
        else if(map->positions[i].y == map->positions[j].y && 
                map->positions[i].x == map->positions[j].x+1 && 
          !is_on_list(open_list, map->positions[j].label)) {
          add_position_to_list(open_list, &map->positions[j]);
        } 
      }
    }
  }

}

void print_list(Map *list) {

  printf("%d\n", list->size);

  for (int i = 0; i < list->size; i++) {
    printf("Label: %c\n", list->positions[i].label);
  }

}

Map find_route(char from, char to) {
  Map map;
  build_map(&map);

  Map open_list;
  open_list.size = 0;
  open_list.positions = (Position *)malloc(sizeof(Position));
  
  find_neighbors(from, &map, &open_list);

  print_list(&open_list);

  return map;

}


int main() {

  Map route = find_route('I', 'D');

}
