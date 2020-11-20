#include <stdio.h>
#include <string.h>

struct RegEst
{
  char Nome[30],End[40];
  int NCred;
  float MF;
  int RA;
};
struct RegEst Est,Melhor;

void Inic_Dados()
{
  strcpy(Est.Nome,"Fujiro Nakombi");
  strcpy(Est.End,"Av. Liberdade, 65");
  Est.MF = 7;
  Est.NCred = 25;
  Est.RA = 3901;

  strcpy(Melhor.Nome,"Bruce Waine");
  strcpy(Melhor.End,"R. Gotan City, 50");
  Melhor.MF = 6.5;
  Melhor.NCred = 30;
  Melhor.RA = 3920;
}


int main()
{
  Inic_Dados();
  if ( Est.MF >= 5 ) printf("\nAprovado: %s",Est.Nome);
  if ( Est.MF > Melhor.MF )
  {
    strcpy(Melhor.Nome,Est.Nome);
    strcpy(Melhor.End,Est.End);
    Melhor.NCred = Est.NCred;
    Melhor.MF = Est.MF;  Melhor.RA = Est.RA;
  }
  printf("\nMelhor aluno: %d - %s - %s",Melhor.RA,Melhor.Nome,Melhor.End);
}

