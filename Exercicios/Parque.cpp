#include <iostream>
#include <iomanip>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int k;
int cont = 0;
const int QtdParque = 2;
const int QtdPlanta = 2;



enum PARQUE {Regia, Botanico, Buracao,Povo};
enum PLANTA {Eucalipto, Pinus, Flamboyant, Praia};

string nparque[4] = {"Vitoria Regia", "Jardim Botanico", "Parque Buracao", "Parque do Povo"};
string planta [4] = {"Eucalipto", "Pinus", "Flamboyant", "Praia"};

int parque[QtdParque][QtdPlanta];

int main()

{
    setlocale(LC_ALL, "pt-BR.UTF-8");
    for(int i = 0 ; i < QtdParque; i++ ){
          for(int j = 0 ; j < QtdPlanta ; j++ ){
                cout << "\nLeia: ";
                cin >> parque[i][j];
          }
    }


    for(int i = 0 ; i < QtdParque; i++ ){
        for(int j = 0 ; j < QtdPlanta; j++ ){
            if(parque[i][j] < 200){
                nparque[cont] ;
                cout << nparque[cont] << " | ";
                cont++;

            }
        }
    }
    if(cont > 0){
        cout << "\nA quantia de parques que possuem menos de 200 arvores sao: " << cont << "\n";
    }else{
        cout << "\nNao possuem parques com menos de 200 arvores\n";
    }
     cont = 0;
     cout << "Informe qual parque: "; cin >> k;
     for(int j = 0 ; j < QtdPlanta; j++ ){
        if(parque[k][j] > 50){
            planta[cont];
            cout << planta[cont] << " | ";
            cont++;

        }
     }

      if(cont > 0){
        cout << "\n a quantia de especies com mais de 50 arvores: " << cont << "\n";
    }else{
        cout << "\nNao possuem especies com mais de 50 arvores\n";
    }

}
