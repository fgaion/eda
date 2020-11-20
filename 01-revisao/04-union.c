#include <stdio.h>

int main()
{
  union exemplo
  {
    int reg;
    char cod;
    float sal;
  } ex;

  printf("\n\nsizeof(union exemplo) = %d",sizeof(union exemplo));
  ex.reg = 107;
  printf("\nreg = %d  endereco = %x",ex.reg,&ex.reg);
  ex.cod = 'E';
  printf("\ncod = %c  endereco = %x",ex.cod,&ex.cod);
  //cout << "\ncod = " << ex.cod << " Endereco: " << (int*) &ex.cod;
  ex.sal = 874.65;
  printf("\nsal = %f  endereco = %x\n\n",ex.sal,&ex.sal);
}
