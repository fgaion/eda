//Maze - caminho num labirinto
//matriz de 0s e 1s -- 0 e' caminho, 1 e' parede

#include <conio.h>
#include <iostream.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int A[5][5] = { {0, 0, 0, 0, 1},
		{1, 0, 1, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 1, 1, 1},
		{1, 0, 0, 0, 0} };

void maze(int A[5][5], int lini, int coli, int linf, int colf, int &ok)
{
  int k;
  if ( (lini == linf) && (coli == colf))
  {
    ok = TRUE;
    return;    
  }

  if (!ok && A[lini][coli+1] == 0 )
  {
    A[lini][coli+1] = 2;
    maze(A,lini,coli+1,linf,colf,ok);
	 if ( ok ) { cout << lini << "," << coli+1 << "  "; return; }
    else A[lini][coli+1]=0;
  }

  if (!ok && A[lini+1][coli] == 0 )
  {
    A[lini+1][coli] = 2;
	 maze(A,lini+1,coli,linf,colf,ok);
	 if ( ok ) { cout << lini+1 << "," << coli << "  "; return; }
    else A[lini+1][coli]=0;
  }
  if (!ok && A[lini][coli-1] == 0 )
  {
    A[lini][coli-1] = 2;
    maze(A,lini,coli-1,linf,colf,ok);
	 if ( ok ) { cout << lini << "," << coli-1 << "  "; return; }
    else A[lini][coli-1]=0;
  }
  if (!ok && A[lini-1][coli] == 0 )
  {
    A[lini-1][coli] = 2;
    maze(A,lini-1,coli,linf,colf,ok);
	 if ( ok ) { cout << lini-1 << "," << coli << "  "; return; }
    else A[lini-1][coli]=0;
  }
}

void main()
{
  int k,n,ok=FALSE;

  clrscr();
  for(k=0;k<5;k++)
  {
	 for(n=0;n<5;n++) cout << A[k][n] << " ";
	 cout << endl;
  }
  cout << endl;

  maze(A,0,0,4,4,ok);
  if ( ok ) cout << "\nExiste pelo menos um caminho possivel a partir de (0,0)\n";
  else cout << "\nNao existe caminho possivel.\n";


  for(k=0;k<5;k++)
  {
    for(n=0;n<5;n++) cout << A[k][n] << " ";
    cout << endl;
  }
}