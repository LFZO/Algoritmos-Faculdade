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
//constantes
const int N=10;

//variáveis do tipo da struct
livro lista[N];
livro val;



//variáveis
string Nome, livro;
int fim;
char conf;
bool sinal;
int aux, x, y;
int k;


//Funções
void inserirInicio();
void inserirK();
void consultarInicio();
void imprimirLista();
void imprimirPares();
void imprimirInversa();
void removerK();
void alterarNo();
void classificarOrdemCres();


int main(){
    fim = -1 ; //inicia a lista vazia
    setlocale(LC_ALL, "Portuguese");
    char op = 'x';
    while (op != '0'){
        system("cls");
        cout << "\t\tLista Sequencial de Livros\n\n";


        cout << "\t\t\t|Menu de opcoes|\n";
        cout << "\t\t[0] - [Sair]\n";
        cout << "\t\t[1] - [Iserir no inicio]\n";
        cout << "\t\t[2] - [Inserir na posicao K]\n";
        cout << "\t\t[3] - [Consultar Inicio]\n";
        cout << "\t\t[4] - [Imprimir a lista]\n";
        cout << "\t\t[5] - [Imprimir posicoes pares]\n";
        cout << "\t\t[6] - [Imprimir lista inversa]\n";
        cout << "\t\t[7] - [Remover na posicao (K+3)]\n";
        cout << "\t\t[8] - [Alterar no do livro de nome Y]\n";
        cout << "\t\t[9] - [Classificar lista por ordem crescente de Pag]\n";

        fflush(stdin);
        cout << "\n\n\t\tInforme a sua escolha: ";
        op = getchar();

        switch(op){
            case '0': {cout << "\n\nSaindo...\n\n"; break;}
            case '1': {inserirInicio(); break;}
            case '2': {inserirK();break;}
            case '3': {consultarInicio();break;}
            case '4': {imprimirLista();break;}
            case '5': {imprimirPares();break;}
            case '6': {imprimirInversa();break;}
            case '7': {removerK();break;}
            case '8': {alterarNo();break;}
            case '9': {classificarOrdemCres();break;}
        }
        system("pause");
    }
}

void inserirInicio(){
	sinal = false;
    system("cls");
    cout << "\t\tLista Sequencial de Livros \n\n";
    cout << "\t\tInserir um novo livro no inicio da lista\n\n";

    if(fim < N-1){
        fflush(stdin);
        cout << "\tInforme o id: "; cin >> val.id;
        fflush(stdin);
        cout << "\tInforme o nome: "; getline(cin, val.nome);
        fflush(stdin);
        cout << "\tInforme o genero: "; getline(cin, val.genero);
        fflush(stdin);
        cout << "\tInforme a pagina: "; cin >> val.pag;
        fflush(stdin);
        cout << "\tEsta reservado? ";cin >> val.reservado;
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
            cout << "\t\tDados nao confirmados\n\n";
        }
    }else{
        cout << "Overflow\n\n";
    }
}

void inserirK(){
	sinal = false;
    system("cls");
    cout << "\t\tLista Sequencial de Livros\n\n";
    cout << "\t\tInserir um novo livro na posicao K\n\n";

    if(fim < N - 1){
    	cout << "Informe a posicao K: "; cin >> k;
    	if(k >= 0 && k <= fim){
			fflush(stdin);
        	cout << "\tInforme o id: "; cin >> val.id;
	        fflush(stdin);
	        cout << "\tInforme o nome: "; getline(cin, val.nome);
	        fflush(stdin);
	        cout << "\tInforme o genero: "; getline(cin, val.genero);
	        fflush(stdin);
	        cout << "\tInforme a pagina: "; cin >> val.pag;
	        fflush(stdin);
	        cout << "\tEsta reservado? ";cin >> val.reservado;
	        fflush(stdin);
	        cout << "\tConfirma (S/N): "; cin >> conf;
			fflush(stdin);
        	conf = toupper(conf);
        	if(conf == 'S'){
        		fim++;
        		aux = fim;
        		while(aux != k){
        			lista[aux] = lista[aux-1];
        			aux --;
				}
				lista[k] = val;
				sinal = true;
			}else{
				cout << "\t\tDados nao confirmados\n\n";
			}
		}else{
			cout << k << " nao pertence a lista\n\n";
		}
	}else{
		cout << "Overflow\n\n";
	}
}

void imprimirLista(){
    sinal = false;
    system("cls");
    cout << "\t\tLista Sequencial de Livros \n\n";
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

void consultarInicio(){
    sinal = false;
    system("cls");
    cout << "\t\tLista Sequencial de Livros \n\n";
    cout << "\t\tConsultar o Inicio da Lista\n\n";
    if(fim > -1){
        cout << setw(5) << "ID" << setw(10) << "NOME" << setw(15) << "GENERO" << setw(8) << "PAGINA" << setw(15) << "RESERVADO" << endl;
        for(int i=0; i<61; i++){
			cout << "-";
		}
        cout << endl;
        val = lista[0];
        cout << setw(5) << val.id << setw(10) << val.nome << setw(15) << val.genero << setw(8) << val.pag << setw(13) << val.reservado << endl;
		sinal = true;
    }else{
        cout << "\n\nLista Vazia\n";
    }


}

void imprimirPares() {
	sinal = false;
    system("cls");
    cout << "\t\tLista Sequencial de Livros \n\n";
    cout << "\t\tImprimir a lista\n\n";
    if(fim > -1){
        cout << setw(5) << "ID" << setw(10) << "NOME" << setw(15) << "GENERO" << setw(8) << "PAGINA" << setw(15) << "RESERVADO" << endl;
        for(int i=0; i<61; i++) cout << "-";
        cout << endl;
		for (aux = 0; aux <= fim; aux++) {
			if (aux % 2 == 0) {
			val = lista[aux];
		 	cout << setw(5) << val.id << setw(10) << val.nome << setw(15) << val.genero << setw(8) << val.pag << setw(13) << val.reservado << endl;
			sinal = true;
			}
		}
    } else {
    	cout << "\n\nLista vazia";
	}


}

void imprimirInversa() {
	sinal = false;
    system("cls");
    cout << "\t\tLista Sequencial de Livros \n\n";
    cout << "\t\tImprimir a lista\n\n";
    if(fim > -1){
        cout << setw(5) << "ID" << setw(10) << "NOME" << setw(15) << "GENERO" << setw(8) << "PAGINA" << setw(15) << "RESERVADO" << endl;
        for(int i=0; i<61; i++) cout << "-";
        cout << endl;
        for (aux = fim; aux >=0; aux --) {
            val = lista[aux];
            cout << setw(5) << val.id << setw(10) << val.nome << setw(15) << val.genero << setw(8) << val.pag << setw(13) << val.reservado << endl;
        }
        sinal = true;
    }else{
        cout << "\n\nLista Vazia\n";
    }
}

void removerK(){
	sinal = false;
    system("cls");
    cout << "\t\tLista Sequencial de Livros \n\n";
    cout << "\t\tRemover a posicao (K+3)\n\n";
    if(fim > -1){
    	cout << "\tInforme a posicao (K+3): "; cin >> k;
    	k += 3;
    	if(k >= 0 && k <= fim){
    		cout << setw(5) << "ID" << setw(10) << "NOME" << setw(15) << "GENERO" << setw(8) << "PAGINA" << setw(15) << "RESERVADO" << endl;
        	for(int i=0; i<61; i++) cout << "-";
        	cout << endl;

    		val = lista[k];

    		cout << setw(5) << val.id << setw(10) << val.nome << setw(15) << val.genero << setw(8) << val.pag << setw(13) << val.reservado << endl;

			cout << "\n\tDeseja mesmo remover? (S/N): "; cin >> conf;
			fflush(stdin);
        	conf = toupper(conf);
        	if(conf == 'S'){
				while( k != fim){
					lista[k] = lista[k + 1];
					k++;
				}
				fim--;
				sinal = true;
			}else{
				cout << "\n\nDados nao confirmados\n\n";
			}
		}else{
			cout << k << " nao pertence a lista\n\n";
		}
	}else{
		cout << "\n\nLista Vazia\n";
	}
}

void alterarNo(){
    aux = 0;
    sinal = false;
    system("cls");
    cout << "\t\tLista Sequencial de Livros\n\n";
    cout << "\t\tAlterar o no na posição do livro com nome igual a 'Y' \n\n";
    if(fim > -1){
    cout << "\tInforme o nome: ";cin >> Nome;
    while(lista[aux].nome != Nome && aux < fim) aux ++;

            if(lista[aux].nome == Nome){
                cout << "\t\tLIVRO LOCALIZADO\n\n";
                cout << setw(5) << "ID" << setw(10) << "NOME" << setw(15) << "GENERO" << setw(8) << "PAGINA" << setw(15) << "RESERVADO" << endl;
                for(int i=0; i<61; i++) cout << "-";
                cout << endl;
                cout << setw(5) << lista[aux].id << setw(10) << lista[aux].nome << setw(15) << lista[aux].genero << setw(8) << lista[aux].pag << setw(13) << lista[aux].reservado << endl;
                fflush(stdin);
                cout << "\t\tInforme o ID: "; cin >> val.id;
                fflush(stdin);
                cout << "\t\tInforme o Nome: "; getline(cin, val.nome);
                fflush(stdin);
                cout << "\t\tInforme o Genero: "; getline(cin, val.genero);
                fflush(stdin);
                cout << "\t\tInforme o Paginas: "; cin >> val.pag;
                fflush(stdin);
                cout << "\t\tEsta Reservado: "; cin >> val.reservado;
                fflush(stdin);
                cout << "\t\tConfirma (S/N): "; cin >> conf;
                conf = toupper(conf);
                if(conf == 'S'){
                  lista[aux] = val;
                  sinal = true;
                }else{
                    cout << "\t\tDADOS NAO CONFIRMADOS\n\n";
                    }
            }
        }else{
        cout << "\t\tLISTA VAZIA\n\n";}
    }

void classificarOrdemCres(){
    sinal = false;
    system("cls");
    cout << "\t\tLista Sequencial de Livros\n\n";
    cout << "\t\tClassificar a lista em ordem crescente de pag\n\n";
    if(fim > -1){
        cout << "\t\tConfirma (S/N): "; cin >> conf;
                conf = toupper(conf);
                if(conf == 'S'){
                for(y=0;y<=fim;y++){
                    for(x=0;x<=fim;x++){
                            if(lista[x].pag > lista[y].pag){
                                val = lista[y];
                                lista[y] = lista[x];
                                lista[x] = val;
                            }

                    }
                }
                }else{
                cout << "/t/tNAO CONFIRMADO";}
    }else{
    cout << "\t\tLISTA VAZIA\n\n";
    }
}
