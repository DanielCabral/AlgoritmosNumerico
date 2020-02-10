#include <iostream>
#include <string.h>
#include <math.h>



//prototipos das funções
using namespace std;
void sistemasLinearesMenu();
void interpolacaoDeNewton();

int main() {
	sistemasLinearesMenu();
	system("pause");
	return 0;
}


void sistemasLinearesMenu() {
	int escolha = -1;
	while (escolha != 0) {
		cout << "1- Interpolação de Newton" << endl;
		cout << "2- Metodo de Gauss Seidel" << endl;
		cout << "3- Fatoracao LU" << endl;
		cout << "4- Decomposicao LDLt" << endl;
		cout << "5- Decomposicao de Cholesky" << endl;
		cout << "0- Voltar" << endl;
		cout << "digite uma opcao: ";
		cin >> escolha;
		switch (escolha) {
		case 1:
			interpolacaoDeNewton();
			break;
		default:
			break;
		}
	}
}
void interpolacaoDeNewton() {
	int qtdPontos,n;
	cout << "Quantidade de pontos: ";
	cin >> qtdPontos;
	double *x = new double[qtdPontos];
	double *fx = new double[qtdPontos];

	//leitura do vetor x
	for (n = 0; n < qtdPontos; n++) {
			cout << "Digite o x" << n << ": ";
			cin >> x[n];
	}
	//leitura do vetor fx
	for (n = 0; n < qtdPontos; n++) {
		cout << "Digite o fx" << n << ": ";
		cin >> fx[n];
	}

	double **tabelaDiferencasDivididas;
	// Array de n ponteiros double:
	tabelaDiferencasDivididas = new double *[qtdPontos];
	// Cada elemento do array é um array de n doubles 
	for (n = 0; n < qtdPontos; n++)
		tabelaDiferencasDivididas[n] = new double[qtdPontos];
	//preencher tabela diferenças divididas
	for (n = 0; n < qtdPontos; n++) {
		for (int j = 0; j < qtdPontos; j++) {
			if (j == 0) {
				tabelaDiferencasDivididas[n][j] = fx[n];
			}
			else {
				tabelaDiferencasDivididas[n][j] = 0;
			}
		}
	}
	
	for (n = 0; n < qtdPontos-1; n++) {
		for (int j = 0; j < qtdPontos-n-1; j++) {
			tabelaDiferencasDivididas[j][n+1] = (tabelaDiferencasDivididas[j+1][n]- tabelaDiferencasDivididas[j][n])/(x[j+n+1]-x[j]);
			cout <<j<<" " <<n+1<<"= ("<< j+1 << ""<<n<<" - "<<j<<""<<n<<") / ("<<j+n+1<<" - "<<j<<")"<<endl;
		}
	}

	for (int i = 0; i < qtdPontos; i++) {
		for (int j = 0; j < qtdPontos-i; j++) {
			cout << tabelaDiferencasDivididas[i][j]<<" ";
		}
		cout<< endl;
	}
	/*string polinomio = "p" + qtdPontos;
	polinomio += "(x)" + std::to;
	for (int i = 0; i < qtdPontos-1; i++) {
		for (int j = 0; j < qtdPontos - i; j++) {
			
		}
	}
	*/
	//Exibir polinomio interpolador
}