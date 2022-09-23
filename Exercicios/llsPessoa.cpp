//llsPessoa.cpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <clocale>
#include <bits/stdc++.h>
using namespace std;


# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
//definição de tipo


struct Aluno{
    int id;
    string nome;
    string curso;
    float nota;
};

//definição de constantes
const int N=10;

//Definição de variáveis
Aluno lista[N];
Aluno val;
int fim;
char conf;
bool sinal;


//prototipação das funções
void IserirFim();
void ImprimirLista();
void removerPrimeiro();

int main(){
    fim = -1 ; //inicia a lista vazia
    setlocale(LC_ALL, "Portuguese");
    char op = 'x';
    while (op != '0'){
        system("cls");
        cout << "\t\tLista Sequencial de Alunos de tamanho: " << N << "\n\n";


        cout << "\t\t\t|Menu de opções|\n";
        cout << "\t\t[0] - [Sair]\n";
        cout << "\t\t[1] - [Inserir aluno no fim da lista]\n";
        cout << "\t\t[2] - [Remover primeiro aluno da lista]\n";
        cout << "\t\t[3] - [Imprimir a lista]\n";

        fflush(stdin);
        cout << "\n\n\t\tInforme a sua escolha: ";
        op = getchar();

        switch(op){
            case '0': {cout << "\n\nSaindo...\n\n"; break;}
            case '1': {IserirFim(); break;}
            case '2': {removerPrimeiro(); break;}
            case '3': {ImprimirLista(); break;}
            default : {cout << "Opção invalida"; break;}
        }
        system("pause");
    }
}

//corpo das funçoes
void IserirFim(){
    sinal = false;
    system("cls");

    cout << "\t\tLista Sequencial de Alunos de tamanho: " << N << "\n\n";
    cout << "\t\tInserir um novo aluno no fim da lista\n\n";
    if((fim+1) < N){
        val.id +=1;
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
}

void ImprimirLista(){
    sinal = false;
    system("cls");
    cout << "\t\tLista Sequencial de Alunos de tamanho: " << N << "\n\n";
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

void removerPrimeiro(){
    int aux;
    sinal = false;
    system("cls");
    cout << "\t\tLista Sequencial de Alunos de tamanho: " << N << "\n\n";
    cout << "\t\Remover aluno da lista\n\n";

    if(fim != -1){

        val = lista[0];
        cout << setw(5) << "ID" << setw(22) << "NOME" << setw(15) << "CURSO" << setw(8) << "Nota" << endl;
        cout << endl;
        cout << setw(5) << val.id << setw(22) << val.nome << setw(15) << val.curso << setw(8) << val.nota << endl;
        cout << "Confirma (S/N): "; cin >> conf;
        fflush(stdin);
        conf = toupper(conf);
        if(conf == 'S'){
           aux = 0;
           while(aux != fim){
            lista[aux] = lista[aux + 1];
            aux++;
           }
           fim--;
           sinal = true;
        }else{
            cout << "\n\nDados não confirmados";
        }
    }else{
        cout << "\n\nLista Vazia\n";
    }

}
