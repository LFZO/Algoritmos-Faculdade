#include <iostream>
#include <iomanip>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int k;
int cont = 0;
const int QtdParque = 4;
const int QtdPlanta = 4;



enum PARQUE {Regia = 0, Botanico, Buracao, Povo};
enum PLANTA {Eucalipto = 0, Pinus, Flamboyant, Praia};

string nparque[4] = {"Vitoria Regia", "Jardim Botanico", "Parque Buracao", "Parque do Povo"};
string planta [4] = {"Eucaliptos", "Pinus", "Flamboyants", "Praias"};

int parque[QtdParque][QtdPlanta];

int main()
{


    cout << "\n-----------------------------------------------------------------------------------\n";

    //ler de forma automatica as especies de arvores nos seus devidos parques
    unsigned seed = time(0);
    srand(seed);
    setlocale(LC_ALL, "pt-BR.UTF-8");
    for(int i = 0 ; i < QtdParque; i++ ){
          for(int j = 0 ; j < QtdPlanta ; j++ ){
                parque[i][j] = 1+rand()%250;
                cout << "\n\tNo parque "<< nparque[i] << " possuem " << parque[i][j] << " " << planta[j];
          }
          cout << "\n";
    }



    //informa os parques com menos de 200 especies de arvores
    cout << "\n-----------------------------------------------------------------------------------\n";
    cout << "\nPossuem parques com menos de 200 arvores? \n";
    cout << "\n-----------------------------------------------------------------------------------\n";
    for(int i = 0 ; i < QtdParque; i++ ){
        for(int j = 0 ; j < QtdPlanta; j++ ){
            if(parque[i][j] < 200){
                cout << "\t" << nparque[i] << " possuem "<< parque[i][j] << " " << planta[j] << "\n" ;
                cont++;

            }
        }
            cout << "\n";
    }

    if(cont > 0){
        cout << "\n-----------------------------------------------------------------------------------\n";
        cout << "\nA quantia de especies de arvores abaixo de 200: " << cont << "\n";
        cout << "\n-----------------------------------------------------------------------------------\n";
    }else{
        cout << "\n-----------------------------------------------------------------------------------\n";
        cout << "\nNao possuem  menos de 200 especies de arrvores \n";
        cout << "\n-----------------------------------------------------------------------------------\n";
    }

    //informa um parque em especifico para saber
    cont = 0;
    cout << "\n\nInforme um parque para saber se possuem mais de 50 arvores: "; cin >> k; cout << "\n";
    for(int j = 0 ; j < QtdPlanta; j++ ){
        if(parque[k][j] > 50){
            cout << "\n\t" << planta[j] ;
            cont++;
            }
    }



    if(cont > 0){
        cout << "\n\nA quantia de especies de arvores a cima de 50 sao: " << cont << "\n";
    }else{
        cout << "\nNao possuem especies de arovres a cima de 50\n";
    }
    cout << "\n-----------------------------------------------------------------------------------\n";
}
