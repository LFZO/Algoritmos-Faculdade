#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <clocale>


using namespace std;

struct livro{
    int id;
    string nome;
    string genero;
    int pag;
    char reservado;
};

    const int N=10;
    livro lista[N];
    livro val;
    int fim;
    char conf;
    bool sinal;
    int aux;
    int k;


void inserirInicio();
void imprimirLista();

int main(){
    fim = -1 ; //inicia a lista vazia
    setlocale(LC_ALL, "Portuguese");
    char op = 'x';
    while (op != '0'){
        system("cls");
        cout << "\t\tLista Sequencial de Livros de tamanho\n\n";


        cout << "\t\t\t|Menu de opções|\n";
        cout << "\t\t[0] - [Sair]\n";
        cout << "\t\t[1] - [Iserir no inicio]\n";
        cout << "\t\t[2] - [Inserir aluno no fim da lista]\n";
        cout << "\t\t[3] - [Remover primeiro aluno da lista]\n";
        cout << "\t\t[4] - [Imprimir a lista]\n";


        fflush(stdin);
        cout << "\n\n\t\tInforme a sua escolha: ";
        op = getchar();

        switch(op){
            case '0': {cout << "\n\nSaindo...\n\n"; break;}
            case '1': {inserirInicio(); break;}
            case '2': {imprimirLista();break;}
        }
        system("pause");
    }
}

void inserirInicio(){
	sinal = false;
    system("cls");
    cout << "\t\tLista Sequencial de Livros de tamanho: " << N << "\n\n";
    cout << "\t\tInserir um novo livro no inicio da lista\n\n";

    if(fim < N-1){
        val.id +=1;
        fflush(stdin);
        cout << "\tInforme o nome: "; getline(cin, val.nome);
        fflush(stdin);
        cout << "\tInforme o genero: "; getline(cin, val.genero);
        fflush(stdin);
        cout << "\tInforme a pagina: "; cin >> val.pag;
        fflush(stdin);
        cout << "\tEstá reservado? ";cin >> val.reservado;
        fflush(stdin);
        cout << "\tConfirma (S/N): "; cin >> conf;
        fflush(stdin);
        conf = toupper(conf);
        if(conf == 'S'){
            fim++;
            aux = fim;
            while(aux != 0){
                lista[aux] = lista[aux-1];
                aux--;
            }
            lista[aux] = val;
            sinal = true;
        }else{
            cout << "Dados nao confirmados";
        }
    }else{
        cout << "Overflow...";
    }
}

void imprimirLista(){
    sinal = false;
    system("cls");
    cout << "\t\tLista Sequencial de Alunos de tamanho: " << N << "\n\n";
    cout << "\t\tImprimir a lista\n\n";
    if(fim > -1){
        cout << setw(5) << "ID" << setw(10) << "NOME" << setw(15) << "GENERO" << setw(8) << "PAGINA" << setw(15) << "RESERVADO" << endl;
        for(int i=0; i<61; i++) cout << "-";
        cout << endl;
        aux = 0;
        while(aux <= fim){
            val = lista[aux];
            cout << setw(5) << val.id << setw(10) << val.nome << setw(15) << val.genero << setw(8) << val.pag << setw(13) << val.reservado << endl;
            aux++;
        }
        sinal = true;
    }else{
        cout << "\n\nLista Vazia\n";
    }
}

