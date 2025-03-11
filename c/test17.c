#include <stdio.h>

struct s1 {
  int x;
  int y;
};

struct s1 m_s1(int x, int y)
{
  struct s1 s = {x, y};
  return s;
}

void p_s1(struct s1 *s)
{
  printf("x %d\n", s->x);
  printf("y %d\n", s->y);
  printf("x %d\n", (*s).x);
  printf("y %d\n", (*s).y);
}

void p_s1_0(struct s1 s)
{
  printf("x %d\n", s.x);
  printf("y %d\n", s.y);
}

typedef struct s2_ {
  int x;
  int y;
} s2_t;

void p_s2(s2_t *s)
{
  printf("x %d\n", s->x);
  printf("y %d\n", s->y);
}

void p_s2_0(s2_t s)
{
  printf("x %d\n", s.x);
  printf("y %d\n", s.y);
}

struct s1 _s11 = {0, 1};

int main(int argc, char *argv[])
{
  struct s1 _s1 = {0, 1};
  s2_t _s2 = {2, 3};
  
  p_s1(&_s1);
  p_s2(&_s2);

  _s1.x = 4;
  _s1.y = 5;
  p_s1(&_s1);

  p_s1_0(_s1);
  p_s2_0(_s2);

  struct s1 _s1_0 = m_s1(6, 7);
  p_s1_0(_s1_0);

  struct s1 _s1a[10];
  struct s1 *_s1ap;

  _s1a[0].x = 0;
  _s1a[0].y = 1;
  _s1a[1].x = 2;
  _s1a[1].y = 3;

  printf("\n");
  _s1ap = &_s1a[0];
  p_s1(_s1ap);
  _s1ap++;
  p_s1(_s1ap);
  
  return 0;
}
