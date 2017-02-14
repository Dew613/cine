#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"


int checkOctant(int x0, int x1, int y0, int y1){
  float n;
  n=(y1-y0)/(x1-x0);
  if (n<1 && n>0){
    return 1;
  return 0;
}

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int A, B, y, x, o;
  A = y1-y0;
  B = -1*(x1-x0);
  y = y0;
  x = x0;
  o =  checkOctant(x0,x1,y0,y1);
  printf("you're working on checkOctant right now\n"    
}

