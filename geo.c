#include <stdio.h>
#include <stdlib.h>


struct point
{
  int x;
  int y;
};


struct rectangle
{
  int x;
  int y;

}


typedef struct point point_t;


void translate(point_t *p1, point_t *p2)
{
  p1->x += p2->x;
  p1->y += p2->y;
}

void print_point(point_t p){
    printf("point(x=%d,y=%d)\n", p.x, p.y);

}

point_t make_point(int a, int b){
  point_t p = { .x = a, .y = b};
  return p;
}

int main(int argc, char *argv[])
{


 
  print_point(make_point(atoi(argv[1]), atoi(argv[2])));
 
 return 0;
}
