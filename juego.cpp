
#include <stdio.h>
#include <iostream>
#include <stdlib.h>     /* srand, rand ,cls*/
#include<ctime> /*tiempo para random*/

using namespace std;
using std::cout;
//reglas de juego:

int filas=0;
int columnas=0;
int f,c;




int GenerarTablero(int jugador1,int jugador2){


    int tablero[filas][columnas];
    //numero es el LA CASILLA QUE SE ESTA GENERANDO EN el tablero
    //@jugador 1, jugador 2 * , misma posicion #;
    int casilla=0;
    for(int i = 0; i < filas; ++i) {
        for(int j = 0; j < columnas; ++j) {
            if (jugador1==casilla && jugador2!=casilla){
                tablero[i][j]=2000;
                cout<<" @ ";
            }
            if (jugador2==casilla&&jugador1!=casilla){
                tablero[i][j]=3000;
                cout<<" * ";
            }
            //cout<<jugador1<<" "<<jugador2;
            if(jugador1==casilla&&jugador2==casilla){
                tablero[i][j]=1000;
                cout<<" # ";
                //cout<<v[i][j];
            }

            else if(jugador1!=casilla&&jugador2!=casilla){


                tablero[i][j]=casilla;
                cout << tablero[ i ][ j ] <<" ";
            }



            casilla+=1;

        }
        cout<<" " <<endl;
    }
};
int ValidarMultiplo8(int posJugador){
    cout<<"usted cayo en casilla"<<posJugador<<endl;
    if (posJugador%8==0){
        posJugador=posJugador-8;
        cout<<"usted cayo en un multiplo de 8, retrocede 8 casillas"<<endl;
    }

    return posJugador;

}
int ValidarMultiplo10(int posJugador){
    int primerDigito=posJugador/10;
    if(posJugador%10==0&&(primerDigito)%2==0){
        cout<<"usted cayo en casilla"<<posJugador<<endl;
        posJugador-=2;
        cout<<"usted cayo en un multiplo de 10, retrocede 2 casillas"<<endl;

    }
    return posJugador;
}
int ValidarMultiplo7(int posJugador){

    if(posJugador%7==0){
        cout<<"usted cayo en casilla"<<posJugador<<endl;
        posJugador+=2;
        cout<<"usted cayo en un multiplo de 7, avanza 2 casillas"<<endl;

    }
    return posJugador;
}
int reglas(int posJugador,int dado,string figuraJ){
    //la ultimas 3 casillas deben sacar el numero exactos

    if((posJugador+dado)<(f*c)-3){

        posJugador+=dado;
        posJugador=ValidarMultiplo8(posJugador);
        posJugador=ValidarMultiplo10(posJugador);
        posJugador=ValidarMultiplo7(posJugador);

    }
    else if(posJugador+dado==(f*c)-1){
        cout<<"el jugador "<<figuraJ<<" saco en el dado el numero "<<dado<<endl;
        cout<<"usted ha ganado"<<endl;
        exit(0);
    }




    return posJugador;

    //validar reglas de juego:
    //tabla del 8: se devuelve a la tabla anterior
    //cae en primo  cae al otro primo
    // multilos de 10 y dijito sea par: dado en el siguiente lanzamiento le resta lo que saque en el dado
    //limpiar consola

}

int turno(int posJugador,int num_jugador){
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
    //rango de 1 a 6casilla
    int dado=rand()%6+1;

    system("CLS");

    cout<<"el jugador "<<figuraJ<<" saco en el dado el numero "<<dado<<endl;

    posJugador=reglas(posJugador,dado,figuraJ);



    //cout<<f*c<<" f*c "<<posJugador+dado<<"  jugador+dado "<<endl;



    return posJugador;
}
int jugar(int jugador1,int jugador2){

    while(jugador1!=f*c || jugador2!=f*c ){
        jugador1=turno(jugador1,1);
        GenerarTablero(jugador1,jugador2);
        jugador2=turno(jugador2,2);
        GenerarTablero(jugador1,jugador2);

    }


}

//FUNCION PRINCIPAL
int main(){
    //POSICIONES DE LOS JUGADORES EN EL TABLERO
    int jugador1=0;
    int jugador2=0;


    while((columnas<3||columnas>10)||(filas<3||filas>10) ){
        cout<<"ingrese las columnas del arreglo"<<endl;
        cin>>columnas;
        cout<<"ingrese las filas del arreglo"<<endl;
        cin>>filas;
        f=filas;
        c=columnas;

    }


    GenerarTablero(jugador1,jugador2);
    jugar(jugador1,jugador2);

    return 0;
}
