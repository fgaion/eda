#include <iostream.h>
int a,b,c;
void R(int &a, int b, int c)
{
  a += 8; b += 8; c += 8;
  cout << "\nFuncao R: a="<< a << " b="<< b << " c=" << c;
}
void Q(int &a, int &b, int c)
{
  a += 5; b += 5; c += 5;
  R(a,b,c);
  cout << "\nFuncao Q: a="<< a << " b="<< b << " c=" << c;
}
void P(int &a, int &b, int &c)
{
  a += 3; b += 3; c += 3;
  Q(a,b,c);
  cout << "\nFuncao P: a="<< a << " b="<< b << " c=" << c;
}
void main()
{
  a = 1; b = 1; c = 1;
  cout << "\nFuncao main, antes de P(a,b,c): a="<< a << " b="<< b << " c=" << c;
  P(a,b,c);
  cout << "\nFuncao main, depois de P(a,b,c): a="<< a << " b="<< b << " c=" << c;
}

