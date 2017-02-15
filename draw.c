#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"



void drawOctant15(int x0, int y0, int x1, int y1, screen s, color c){
  int A, B, y, x;
  A = y1-y0;
  B = -1*(x1-x0);
  y = y0;
  x = x0;
  d = 2*A+B;
  while (x<=x1){
    plot(x, y);
    if (d > 0){
      y++;
      d+=2*B;
    }
    x++;
    d+=2*A;
  }
  printf("drawn octant 1 or 5");
}

void drawOctant26(int x0, int y0, int x1, int y1, screen s, color c){
  int A, B, y, x;
  A = y1-y0;
  B = -1*(x1-x0);
  y = y0;
  x = x0;
  d = A+2*B;
  while (y<=y1){
    plot(x, y);
    if (d < 0){
      x++;
      d+=A;
    }
    y++;
    d+=2*B;
  }
  printf("drawn octant 2 or 6");
}

void drawOctant37(int x0, int y0, int x1, int y1, screen s, color c){
  int A, B, y, x;
  A = y1-y0;
  B = -1*(x1-x0);
  y = y0;
  x = x0;
  d = A-2*B;
  while (y<=y1){
    plot(x, y);
    if (d > 0){
      x++;
      d+=A;
    }
    y--;
    d-=2*B;
  }
  printf("drawn octant 3 or 7");
}


void drawOctant48(int x0, int y0, int x1, int y1, screen s, color c){
  int A, B, y, x;
  A = y1-y0;
  B = -1*(x1-x0);
  y = y0;
  x = x0;
  d = 2*A+B;
  while (x>=x1){
    plot(x, y);
    if (d < 0){
      y--;
      d-=2*B;
    }
    x++;
    d+=2*A;
  }
  printf("drawn octant 1 or 5");
}

    
    
//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int A, B;
  A = y1-y0;
  B = -1*(x1-x0);
  y = y0;
  x = x0;
  if(A/B>0 && A/B<1){//narrow it to octants 1 or 5
    if (x0>x1)
      drawOctant15(x1,y1,x0,y0,s,c);//if x0 is greater
    else
      drawOctant15(x0,y0,x1,y1,s,c);
  }
  else if(A/B>0 && A/B>=1){//narrow it to octants 1 or 5
    if (y0>y1)
      drawOctant26(x1,y1,x0,y0,s,c);//if y0 is greater
    else
      drawOctant26(x0,y0,x1,y1,s,c);
  }
  else if(A/B<0 && A/B<1){//narrow it to octants 1 or 5
    if (x0>x1)
      drawOctant26(x1,y1,x0,y0,s,c);//if y0 is greater
    else
      drawOctant26(x0,y0,x1,y1,s,c);
  }
  else{
    if (x0>x1)
      drawOctant26(x1,y1,x0,y0,s,c);//if y0 is greater
    else
      drawOctant26(x0,y0,x1,y1,s,c);
    
    printf("Special cases now");    
}

