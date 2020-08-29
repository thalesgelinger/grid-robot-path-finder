#include <stdio.h>

typedef struct Position {
    char value;
    char label;
    int x;
    int y;
    int costToEnd;
    int costToBegin;
    int cost;
} Position;
