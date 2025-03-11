enum xt {INTEGER = 0, FLOAT = 1};

struct x {
  enum xt type;
  union {
    int xi;
    float xf;
  } u;
};

union u {
  struct {
    int type;
  } n;
  struct {
    int type;
    int x;
  } ni;
  struct {
    int type;
    float x;
  } nf;
};
    
int main(int argc, char *argv[])
{
  struct x x0;

  x0.type = FLOAT;
  x0.u.xf = 1.0;

  union u u0;
  u0.n.type = 1;
  u0.nf.x = 1.0;
  
  return 0;
}
    
