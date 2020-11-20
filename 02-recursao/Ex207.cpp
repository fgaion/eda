#include <iostream.h>
int  a,b,c;
float f;
void P(int x, int y, int &z)
{
  z = x + y + z;
}
float Q(int &x, int y)
{
  x += y;
  y = 3;
  return((float) x/7);
}
void main()
{
  a = 5; b = 8; c = 4;
  cout << "\nAntes de P(a,b,c): a=" << a << " b=" << b << " c=" << c;
  P(a,b,c);
  cout << "\nDepois de P(a,b,c): a=" << a << " b=" << b << " c=" << c;
  cout << "\nAntes de Q(b,c):  b=" << b << " c=" << c;
  f = Q(b,c);
  cout << "\nDepois de Q(b,c):  b=" << b << " c=" << c << " f=" << f;
  cout << "\nAntes de P(7,a+b+c,a): a=" << a << " b=" << b << " c=" << c;
  P(7, a + b + c, a);
  cout << "\nDepois de P(7,a+b+c,a): a=" << a << " b=" << b << " c=" << c;
}
