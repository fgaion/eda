#include <iostream.h>
int x,y;
int G(int &a, int &b)
{
  int z, ret;
  z = a-1;
  if ( b == 0 ) ret = a;
  else ret = 2 * G(b,z);
  a = b;
  b = z;
  return(ret);
}
void main()
{ int a;
  x = 2; y = 4; a = G(x,y);
  cout << "\nx = " << x << " y = " << y << " G(2,4) = " << a;
}
