#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;


enum TANOS {a2017 ,a2018, a2019, a2020, a2021,};
enum TMESES {Jan, Fev, Mar, Abr, Mai, Jun, Jul, Ago, Set, Out, Nov, Dez};

const int TANO = 5, TMES = 12, TFUN = 5;

string vAnos[TANO] = {"2017", "2018", "2019", "2020", "2021"};
string vMeses[TMES] = {"Janeiro", "Fevereiro", "Marco", "Abril",
 "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

string vFunc[TFUN];
float CBSFunc[TANO][TMES][TFUN]={0};
int ano, mes, func;


void inicia();
void imprime();

void inicia(){
    system("cls");
    cout << "\t\t\tPrograma Funcionarios CBS";
    cout << "\t\t\tIniciar Dados de funcionarios e matriz salarios";
    cout << "Iniciando funcionario...\n\n";
    stringstream saida;
    for(func=0; func < TFUN; func++){
        saida.str("");
        saida << "Funcionario - " << func +1;
        vFunc[func] = saida.str();
    }
    cout << "\n\nInciando os metodos de uma Matriz CBSFunc...\n\n";
    srand(time(NULL));
    for(ano = a2017; ano < TANO; ano++)
        for(mes = Jan; mes < TMES; mes++)
            for(func = 0; func < TFUN; func ++){
                CBSFunc[ano][mes][func] = (rand()%10000)+1000;
                cout << "CBSFunc["<< ano <<"]"<< "["<< mes <<
                 "]" << "[" << func << "]" << CBSFunc[ano][mes][func]<<endl;
            }
}

void imprime(){
    system ("cls");
    cout << fixed << setprecision(2);
    cout << "Programa imprimir dados\n";
    for(func = 0; func < TFUN; func ++){
            cout << "\n\n" << vFunc[func] << endl;
        for(ano = a2017; ano < TANO; ano++){
                cout << "ANO: " << vAnos[ano] << endl;
            for(mes = Jan; mes < TMES; mes++){
                cout << setw(12)<< vMeses [mes] << ": ";
                cout << "R$" << setw(7) <<CBSFunc[ano][mes][func]
                << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    inicia();
    imprime();
}
