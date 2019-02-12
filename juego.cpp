
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>     /* srand, rand ,cls*/
#include<ctime> /*tiempo para random*/
using namespace std;
using std::cout;





int GenerarTablero(int jugador1,int jugador2,int filas,int columnas){
    int v[filas][columnas];
    //numero es el numero que se va a imprimir en el tablero incialmente

    int numero=0;
    for(int i = 0; i < columnas; ++i) {
        for(int j = 0; j < filas; ++j) {
            if (jugador1==numero && jugador2!=numero){
                v[i][j]=2000;
                cout<<" @ ";
            }
            if (jugador2==numero&&jugador1!=numero){
                v[i][j]=3000;
                cout<<" * ";
            }
            //cout<<jugador1<<" "<<jugador2;
            if(jugador1==numero&&jugador2==numero){
                v[i][j]=1000;
                cout<<" # ";
                //cout<<v[i][j];
            }
            else if(jugador1!=numero&&jugador2!=numero){


                v[i][j]=numero;
                cout << v[ i ][ j ] <<" ";
            }



            numero+=1;

        }
        cout<<" " <<endl;
    }
};
int turno(int jugador,int f,int c,int num_jugador){
    string lanzar;
    string figuraJ;
    switch(num_jugador){
        case 1:
            figuraJ= "@";
            break;
        case 2:
            figuraJ="*";
            break;
    }
    cout<<"ingrese una tecla para tirar dado jugador "<<figuraJ<<" :"<<endl;
    cin>>lanzar;
    srand(time(NULL));
    //rango de 1 a 6
    int dado=rand()%6+1;
    //la ultimas 3 casillas deben sacar el numero exactos


    if((jugador+dado)<(f*c)-3){
        cout<<"entra"<<endl;
        jugador+=dado;
    }
    else if(jugador+dado==(f*c)-1){
        cout<<"el jugador "<<figuraJ<<" saco en el dado el numero "<<dado<<endl;
        cout<<"usted ha ganado"<<endl;
        exit(0);
    }
    system("CLS");
    cout<<f*c<<" f*c "<<jugador+dado<<"  jugador+dado "<<endl;
    cout<<"el jugador "<<figuraJ<<" saco en el dado el numero "<<dado<<endl;


    return jugador;
}
int jugar(int jugador1,int jugador2,int f,int c){
    while(jugador1!=f*c || jugador2!=f*c ){
        jugador1=turno(jugador1,f,c,1);
        GenerarTablero(jugador1,jugador2,f,c);
        jugador2=turno(jugador2,f,c,2);
        GenerarTablero(jugador1,jugador2,f,c);

    }


}


int main(){
    int jugador1=0;
    int jugador2=0;
    int columnas=0;
    int filas=0;
    cout<<"ingrese las columnas del arreglo"<<endl;
    cin>>columnas;
    cout<<"ingrese las filas del arreglo"<<endl;
    cin>>filas;


    GenerarTablero(jugador1,jugador2,filas,columnas);
    jugar(jugador1,jugador2,filas,columnas);

    return 0;
}
