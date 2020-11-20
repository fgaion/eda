#include <iostream.h>
int x,y,z;
void P1()
{
  int x=2;                // x e' da funcao P1
  x = z; z = y; y = x;    // y e z sao globais
}
void P2(int x)
{
  int y=0;                //x e y sao de P2
  while ( x <= z ) y++;   //z e' global
}
void main()
{
  cin >> x >> y >> z;   // x,y,z sao globais
  if (x >= y) P1;
  else P2(x);
}
