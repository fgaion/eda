#include <iostream.h>
void funcB(int b);
void funcA(int a)
{
  if ( a < 20 )
  {
    a = a + 1;
    funcB(a);
  }
  cout << " a=" <<a;
}

void funcB(int b)
{
  if ( b < 20 )
  {
    b = b + 1;
    funcA(b);
  }
  cout << " b=" << b;
}
void main()
{
  funcA(0);
}