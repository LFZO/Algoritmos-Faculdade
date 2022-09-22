//llsPessoa.cpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <clocale>
using namespace std;

//definição de tipo

struct Aluno{
    int id;
    string nome;
    string curso;
    float nota;
};

//definição de constantes
const int N=4;

//Definição de variáveis
Aluno lista[N];
Aluno val;
int fim;
char conf;
bool sinal;


//prototipação das funções
void lls1_IsereFim();
void lls6_ImprimirLista();


int main(){
    fim = -1 ; //inicia a lista vazia
    setlocale(LC_ALL, "Portuguese");
    char op = 'x';
    while (op != '0'){
        system("cls");
        cout << "\t\tPrograma exemplo Lista Sequencia Aluno\n";
        cout << "\t\tMenu de opções\n\n";
        cout << "\t\t0 - Sair\n";
        cout << "\t\t1 - Inserir Nó no fim da lista\n";
        cout << "\t\t2 - Imprimir a lista\n";

        fflush(stdin);
        cout << "\n\n\t\tInforme a sua escolha:";
        op = getchar();

        switch(op){
            case '0': {cout << "\n\nBom descanso!!!\n\n"; break;}
            case '1': {lls1_IsereFim(); break;}
            case '2': {lls6_ImprimirLista(); break;}
            default : {cout << "Opção invalida"; break;}
        }
        system("pause");
    }
}

//corpo das funçoes
void lls1_IsereFim(){
    sinal = false;
    system("cls");

    cout << "\t\tPrograma lista sequencial Aluno \n\n";
    cout << "\t\t Inserir um novo NÓ no fim da lista\n\n";
    if((fim+1) < N){
        cout << "\tInforme o ID: "; cin >> val.id;
        fflush(stdin);
        cout << "\tInforme o nome: "; getline(cin, val.nome);
        fflush(stdin);
        cout << "\tInforme o curso: "; getline(cin, val.curso);
        fflush(stdin);
        cout << "\tInforme a nota: "; cin >> val.nota;
        fflush(stdin);
        cout << "\tConfirma (S/N): "; cin >> conf;
        fflush(stdin);
        conf = toupper(conf);
        if(conf == 'S'){
            fim++;
            lista[fim] = val;
            sinal = true;
        }else{
            cout << "\n\nDados não confirmados";
        }

    }else{
        cout << "\n\nLista Cheia - Overflow\n";
    }
        system("pause");
}

void lls6_ImprimirLista(){
    sinal = false;
    system("cls");
    cout << "\t\tPrograma lista sequencial Aluno \n\n";
    cout << "\t\tImprimir a lista\n\n";
    if(fim > -1){
        cout << setw(5) << "ID" << setw(22) << "NOME" << setw(15) << "CURSO" << setw(8) << "Nota" << endl;
        for(int i=0; i<50; i++) cout << "-";
        cout << endl;
        int aux = 0;
        while(aux <= fim){
            val = lista[aux];
            cout << setw(5) << val.id << setw(22) << val.nome << setw(15) << val.curso << setw(8) << val.nota << endl;
            aux++;
        }
        sinal = true;
    }else{
        cout << "\n\nLista Vazia\n";
    }
}
