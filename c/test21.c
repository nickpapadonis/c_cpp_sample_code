typedef struct {
    int a;
} x_t;

struct x {
  int a;
};

typedef struct x xx_t;

int main(int argc, char *argv[])
{
  struct x p;
  xx_t p2;
  
  p.a = 1;
  p2.a = 1;
  
  x_t z;
  z.a = 1;
  
  return 0;
}
