#include "matriz.h"

matriz::matriz(int a, int b)
{
    fil = a;
    col = b;
    mat = new int* [fil];
    for(int f=0; f<fil; f++) mat[f] = new int[col];
}


void matriz::generar_mapa()
{
    muro= new escenario();
    for(int f=0; f<fil; f++){
        for(int c=0; c<col; c++){
            if(nivel1[f][c]==1){

                muro->CambiarOriginal(":/escenario/escenario/muro1.png");
            }
            else if(nivel1[f][c]==2){
                muro->CambiarOriginal(":/escenario/escenario/muro1.png");
            }
            //if(f*c==0 || f==fil-1 || c==col-1 || (f%2==0 && c%2==0)) mat[f][c]=0;
           // else if(f+c==3 || f+c==2) mat[f][c]=8;
           // else if(aleatorio()) mat[f][c]=1;
            //else mat[f][c]=8;

        }
    }
}

int **matriz::get_matriz()
{
    return mat;
}

matriz::~matriz()
{
    delete mat;
}
