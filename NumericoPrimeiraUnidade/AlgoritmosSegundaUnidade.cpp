#include <iostream>
#include <math.h>



//prototipos das funções
using namespace std;
void conversoesMenu();
void zeroDeFuncoesMenu();
void sistemasLinearesMenu();
void normas();
void metodoDeJacobi();
void metodoDeGaussSeidel();
void DecomposiçãoDeCholesky();
void metodoFatoracaoLU();
void DecomposicaoLDLt();
int main() {
	int escolha = -1;
	while (escolha != 0) {
		cout << "1- Conversao" << endl;
		cout << "2- Zero de funcoes" << endl;
		cout << "3- Sistemas lineares" << endl;
		cout << "0- Sair" << endl;
		cout << "digite uma opcao: ";
		cin >> escolha;
		switch (escolha) {
		case 1:
			conversoesMenu();
			break;
		case 2:
			zeroDeFuncoesMenu();
			break;
		case 3:
			sistemasLinearesMenu();
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}

void conversoesMenu() {
	int opt = -1;
	while (opt != 0) {

		cout << "Conversor De Bases Numericas" << endl << endl;
		cout << "1 - Binário     ->  Decimal      " << endl;
		cout << "2 - Decimal     ->  Binário      " << endl;
		cout << "3 - Octal       ->  Decimal      " << endl;
		cout << "4 - Decimal     ->  Octal        " << endl;
		cout << "5 - Hexadecimal ->  Decimal      " << endl;
		cout << "6 - Decimal     ->  Hexadecimal " << endl;
		cout << "0 - voltar" << endl;
		cout << "digite uma opcao: ";
		cin >> opt;

		switch (opt) {
		case 0:
			break;
		default:
			printf("OPCAO NAO PERMITIDA!\nTENTE NOVAMENTE\n");
			break;
		}
	}
}

void zeroDeFuncoesMenu() {
	int escolha = -1;
	while (escolha != 0) {
		cout << endl << "1- Metodo da biseccao" << endl;
		cout << "2- Posicao Falsa" << endl;
		cout << "3- Ponto Fixo" << endl;
		cout << "4- Secante" << endl;
		cout << "5- Newton" << endl;
		cout << "0- Voltar" << endl;
		cout << "digite uma opcao: ";
		cin >> escolha;
		switch (escolha) {
		case 0:
			break;
		default:
			break;
		}
	}
}

void sistemasLinearesMenu() {
	int escolha = -1;
	while (escolha != 0) {
		cout << "1- Calculo de norma matricial" << endl;
		cout << "2- Sistema linear triangular superior" << endl;
		cout << "3- Sistema linear triangular inferior" << endl;
		cout << "4- Sistema linear por eliminação gaussiana" << endl;
		cout << "5- Metodo de Jacobi" << endl;
		cout << "6- Metodo de Gauss Seidel" << endl;
		cout << "7- Fatoracao LU" << endl;
		cout << "8- Decomposicao LDLt" << endl;
		cout << "9- Decomposicao de Cholesky" << endl;
		cout << "0- Voltar" << endl;
		cout << "digite uma opcao: ";
		cin >> escolha;
		switch (escolha) {
		case 5: 
			metodoDeJacobi();
			break;
		case 6:
			metodoDeGaussSeidel();
			break;
		case 7:
			metodoFatoracaoLU();
			break;
		case 8:
			DecomposicaoLDLt();
			break;
		case 9:
			DecomposiçãoDeCholesky();
			break;
		default:
			break;
		}
	}
}

void metodoFatoracaoLU() {
	cout.precision(6);
	cout << fixed;
	int ordem, maxInt = 0;
	cout << "Digite a ordem da matriz: ";
	cin >> ordem;

	//criar vetor de b
	double *b = new double[ordem];
	// criar vetor de y
	double *y = new double[ordem];
	//matriz de a
	double **a;
	double **lu;
	int n;

	// Array de n ponteiros double:
	a = new double *[ordem];
	// Cada elemento do array é um array de n doubles
	for (n = 0; n < ordem; n++)
		a[n] = new double[ordem];
	// Array de n ponteiros double:
	lu = new double *[ordem];
	// Cada elemento do array é um array de n doubles
	for (n = 0; n < ordem; n++)
		lu[n] = new double[ordem];

	//leitura do vetor a
	for (n = 0; n < ordem; n++) {
		for (int j = 0; j < ordem; j++) {
			cout << "Digite o a" << (n + 1) << (j + 1) << ":";
			cin >> a[n][j];
		}
	}
	//iniciar lu
	for (n = 0; n < ordem; n++) {
		for (int j = 0; j < ordem; j++) {
			if (n == j)
				lu[n][j] = 1;
			else
				lu[n][j] = 0;
		}
	}
	//leitura do vetor b
	for (n = 0; n < ordem; n++) {
		cout << "Digite o b" << (n + 1) << ":";
		cin >> b[n];
	}
	bool elementoNulo = false;
	for (int i = 0; i < ordem - 1; i++) {
		if (a[i][i] == 0) {
			elementoNulo = true;
		}
	}

	if (!elementoNulo) {
		//triangularização da matriz
		for (int k = 0; k < ordem - 1; k++) {
			for (int i = k + 1; i < n; i++) {
				double m = a[i][k] / a[k][k];
				a[i][k] = 0;
				lu[i][k] = m;
				lu[k][k] = 1;
				for (int j = k + 1; j < n; j++) {
					a[i][j] = a[i][j] - m * a[k][j];
				}
			}
		}
		//criar vetor de y
		double soma = 0;
		y[0] = b[0] ;
		//calcular valores de y; ly=b
		for (int k = 1; k < ordem; k++) {
			double soma = 0;
			for (int i = 0; i < k; i++) {
				soma = soma + (lu[k][i] * y[i]);
			}
			y[k] = (b[k] - soma) / lu[k][k];
		}

		//criar vetor de x
		double *x = new double[ordem];
		soma = 0;
		x[ordem - 1] = y[ordem - 1] / a[ordem - 1][ordem - 1];

		//calcular valores de x, ux=y
		for (int k = ordem - 2; k >= 0; k--) {
			for (int i = k + 1; i < ordem; i++) {
				soma += a[k][i] * x[i];
			}
			x[k] = (y[k] - soma) / a[k][k];
			soma = 0;
		}


		cout << "Solucoes: " << endl;
		//imprimir x
		for (n = 0; n < ordem; n++) {
			cout << "x" << (n + 1) << ": " << x[n] << endl;
		}
		delete x;
		cout << endl;
	}
	//liberar memoria
	for (n = 0; n < ordem; n++)
		delete[] a[n];

	delete[] a;
	delete b;
	//liberar memoria
	for (n = 0; n < ordem; n++)
		delete[] lu[n];

	delete[] lu;
	delete y;
}

void DecomposicaoLDLt() {
	
	cout.precision(6);
	cout << fixed;
	int ordem, maxInt = 0;
	cout << "Digite a ordem da matriz: ";
	cin >> ordem;
	double precisao;
	cout << "Digite a precisao: ";
	cin >> precisao;

	//criar vetor de b
	double *b = new double[ordem];
	//matriz de a
	double **a;
	double **l;
	double **d;
	double **lt;
	int n;

	// Array de n ponteiros double:
	a = new double *[ordem];
	// Cada elemento do array é um array de n doubles
	for (n = 0; n < ordem; n++)
		a[n] = new double[ordem];
	// Array de n ponteiros double:
	l = new double *[ordem];
	// Cada elemento do array é um array de n doubles
	for (n = 0; n < ordem; n++)
		l[n] = new double[ordem];
	d = new double *[ordem];
	// Cada elemento do array é um array de n doubles
	for (n = 0; n < ordem; n++)
		d[n] = new double[ordem];
	lt = new double *[ordem];
	// Cada elemento do array é um array de n doubles
	for (n = 0; n < ordem; n++)
		lt[n] = new double[ordem];

	//leitura do vetor a
	for (n = 0; n < ordem; n++) {
		for (int j = 0; j < ordem; j++) {
			cout << "Digite o a" << (n + 1) << (j + 1) << ":";
			cin >> a[n][j];
		}
	}
	//iniciar lu
	for (n = 0; n < ordem; n++) {
		for (int j = 0; j < ordem; j++) {
			if (n == j) {
				l[n][j] = 1;
				lt[n][j] = 1;
			}
			else {
				l[n][j] = 0;
				lt[n][j] = 0;
			}
			d[n][j] = 0;
		}
	}
	//leitura do vetor b
	for (n = 0; n < ordem; n++) {
		cout << "Digite o b" << (n + 1) << ":";
		cin >> b[n];
	}
	bool elementoNulo = false;
	for (int i = 0; i < ordem - 1; i++) {
		if (a[i][i] == 0) {
			elementoNulo = true;
		}
	}

	if (!elementoNulo) {
		bool ehSimetrica=true;
		//teste de simetria
		for (int i = 0; i < ordem; i++) {
			for (int j = i + 1; j < ordem; j++) {
				if (a[i][j] != a[j][i])
					ehSimetrica = false;
			}
		}
		if (ehSimetrica) {
			//triangularização da matriz
			for (int k = 0; k < ordem - 1; k++) {
				for (int i = k + 1; i < n; i++) {
					double m = a[i][k] / a[k][k];
					a[i][k] = 0;
					l[i][k] = m;
					l[k][k] = 1;
					for (int j = k + 1; j < n; j++) {
						a[i][j] = a[i][j] - m * a[k][j];
					}
				}
			}
			//preencher D
			for (int i = 0; i < ordem; i++) {
				d[i][i] = a[i][i];
			}
			//preencher Lt
			for (int i = 0; i < ordem; i++) {
				for (int j = i + 1; j < ordem; j++) {
					lt[i][j] = l[j][i];
				}
			}
			cout << "L="<<endl;
			for (int k = 0; k < ordem; k++) {
				for (int i = 0; i < ordem; i++) {
					cout << l[k][i] << " ";
				}
				cout << endl;
			}
			cout << endl<<endl;
			cout << "D=" << endl;
			for (int k = 0; k < ordem ; k++) {
				for (int i = 0; i < ordem; i++) {
					cout << d[k][i] << " ";
				}
				cout << endl;
			}

			cout << endl << endl;
			cout << "Lt=" << endl;
			for (int k = 0; k < ordem; k++) {
				for (int i = 0; i < ordem; i++) {
					cout << lt[k][i] << " ";
				}
				cout << endl;
			}
		}
	}
}

void DecomposiçãoDeCholesky() {
	
	cout.precision(6);
	cout << fixed;
	int ordem, maxInt = 0;
	cout << "Digite a ordem da matriz: ";
	cin >> ordem;

	//criar vetor de b
	double *b = new double[ordem];
	//matriz de a 
	double **a;
	double **g;
	int n;

	// Array de n ponteiros double:
	a = new double *[ordem];
	// Cada elemento do array é um array de n doubles 
	for (n = 0; n < ordem; n++)
		a[n] = new double[ordem];

	g = new double *[ordem];
	// Cada elemento do array é um array de n doubles 
	for (n = 0; n < ordem; n++)
		g[n] = new double[ordem];

	//leitura do vetor a
	for (n = 0; n < ordem; n++) {
		for (int j = 0; j < ordem; j++) {
			cout << "Digite o a" << (n + 1) << (j + 1) << ":";
			cin >> a[n][j];
		}
	}

	//leitura do vetor b
	for (n = 0; n < ordem; n++) {
		cout << "Digite o b" << (n + 1) << ":";
		cin >> b[n];
	}
	//iniciar g
	for (n = 0; n < ordem; n++) {
		for (int j = 0; j < ordem; j++) {
			g[n][j] = 0;
		}
	}
	bool elementoNulo = false;
	for (int i = 0; i < ordem - 1; i++) {
		if (a[i][i] == 0) {
			elementoNulo = true;
		}
	}
	if (!elementoNulo) {
		bool ehSimetrica = true;
		//teste de simetria
		for (int i = 0; i < ordem; i++) {
			for (int j = i + 1; j < ordem; j++) {
				if (a[i][j] != a[j][i])
					ehSimetrica = false;
			}
		}
		if (ehSimetrica) {
			int k;
			for (k = 0; k < ordem; k++) {
				double somaG = 0;
				for (int j = 0; j < k-1; j++) {
					somaG += pow(g[k][j], 2);
				}
				double r = a[k][k] - somaG;
				if (r <= 0)
					//break;

				g[k][k] = sqrt(r);
				cout << "G= "<<sqrt(r)<<" "<<g[k][k] << endl;
				for (int i = 0; i < ordem; i++) {
					for (int j = 0; j < ordem; j++) {
						cout << g[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl << endl;
				for (int i = k+1; i <= k; i++) {
					somaG = 0;
					for (int j = 0; j < k - 1; j++) {
						somaG  += g[i][j] * g[k][j];
					}
					cout << (a[i][k] - somaG) / g[k][k]<<endl;
					g[i][k] = (a[i][k] - somaG) / g[k][k];
				}

			}
			cout << "G=" << endl;
			for (int i = 0; i < ordem; i++) {
				for (int j = 0; j < ordem; j++) {
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl << endl;
		}

	}
	//liberar memoria
	for (n = 0; n < ordem; n++)
		delete[] a[n];

	delete[] a;
	for (n = 0; n < ordem; n++)
		delete[] g[n];

	delete[] g;
	delete b;
}

void metodoDeJacobi() {
	cout.precision(6);
	cout << fixed;
	int ordem, maxInt=0;
	cout << "Digite a ordem da matriz: ";
	cin >> ordem;
	double precisao;
	cout << "Digite a precisao: ";
	cin >> precisao;

	//criar vetor de b
	double *b = new double[ordem];
	//matriz de a 
	double **a;
	int n;

	// Array de n ponteiros double:
	a = new double *[ordem];
	// Cada elemento do array é um array de n doubles 
	for (n = 0; n < ordem; n++)
		a[n] = new double[ordem];

	//leitura do vetor a
	for (n = 0; n < ordem; n++) {
		for (int j = 0; j < ordem; j++) {
			cout << "Digite o a" << (n + 1) << (j + 1) << ":";
			cin >> a[n][j];
		}
	}

	//leitura do vetor b
	for (n = 0; n < ordem; n++) {
		cout << "Digite o b" << (n + 1) << ":";
		cin >> b[n];
	}
	bool elementoNulo = false;
	for (int i = 0; i < ordem - 1; i++) {
		if (a[i][i] == 0) {
			elementoNulo = true;
		}
	}

	if (!elementoNulo) {
		//teste M diagonal dominante
		bool ehMatrizDominante = true;
		for (int i = 0; i < ordem; i++) {
			double somaModulo = 0;
			for (int j = 0; j < ordem; j++) {
				if (a[i][j] != a[i][i]) {
					somaModulo += abs(a[i][j]);
				}
			}
			if (a[i][i] < somaModulo) {
				ehMatrizDominante = false;
			}
		}
		if (ehMatrizDominante) {
			//criar vetor de x
			double *x = new double[ordem];
			double *x0 = new double[ordem];
			//valores iniciais de x = 0;
			for (int i = 0; i < ordem; i++) {
				x[i] = b[i]/a[i][i];
			}
			//calcular xs
			double teste = 1;
			while (teste > precisao && maxInt<50) {
				maxInt++;
				for (int i = 0; i < ordem; i++) {
					x0[i] = x[i];
				}
				for (int i = 0; i < ordem; i++) {
					//x[1]=(b1-a12*x2-a13*x3-a1n*xn)/a11;
					//...
					x[i] = b[i];
					for (int j = 0; j < ordem; j++) {
						if (a[i][j] != a[i][i]) {
							x[i] -= a[i][j] * x0[j];
						}
					}
					x[i] /= a[i][i];
				}
				cout << "Interacao " << maxInt<<endl;
				for (int i = 0; i < ordem; i++) {
					cout << "x" << i << " = " << x[i] << endl;
				}
				cout << endl;
				//teste de parada
				double maxModXi = 0;
				double maxD = 0;
				for (int i = 0; i < ordem; i++) {
					double modX1MenosX0 = abs(x[i]) - abs(x0[i]);
					if (modX1MenosX0 > maxD) {
						maxD = modX1MenosX0;
					}
					if (abs(x[i]) > maxModXi) {
						maxModXi = abs(x[i]);
					}
				}
				teste = maxD / maxModXi;
				cout << "d=  " << maxD << " / " << maxModXi << " = " << teste << endl;

			}
			//exibir raizes
			cout << "As raizes sao: " << endl;
			for (int i = 0; i < ordem; i++) {
				cout << "x"<<i<<" = "<<x[i] << endl;
			}
			cout <<endl<< "Foram necessarias  "<<maxInt<<" interacoes." << endl<<endl;
			delete x;
		}
		else {
			cout << "A matriz não é diagonal dominante." << endl;
		}
	}
	else {
		cout << "Elemento nulo na diagonal, matriz não pode ser triangularizada" << endl;
	}
	//liberar memoria
	for (n = 0; n < ordem; n++)
		delete[] a[n];

	delete[] a;
	delete b;
}
void metodoDeGaussSeidel() {
	cout.precision(6);
	cout << fixed;
	int ordem, maxInt = 0;
	cout << "Digite a ordem da matriz: ";
	cin >> ordem;
	double precisao;
	cout << "Digite a precisao: ";
	cin >> precisao;

	//criar vetor de b
	double *b = new double[ordem];
	//matriz de a 
	double **a;
	int n;

	// Array de n ponteiros double:
	a = new double *[ordem];
	// Cada elemento do array é um array de n doubles 
	for (n = 0; n < ordem; n++)
		a[n] = new double[ordem];

	//leitura do vetor a
	for (n = 0; n < ordem; n++) {
		for (int j = 0; j < ordem; j++) {
			cout << "Digite o a" << (n + 1) << (j + 1) << ":";
			cin >> a[n][j];
		}
	}

	//leitura do vetor b
	for (n = 0; n < ordem; n++) {
		cout << "Digite o b" << (n + 1) << ":";
		cin >> b[n];
	}
	bool elementoNulo = false;
	for (int i = 0; i < ordem - 1; i++) {
		if (a[i][i] == 0) {
			elementoNulo = true;
		}
	}

	if (!elementoNulo) {
		//teste M diagonal dominante
		bool ehMatrizDominante = true;
		for (int i = 0; i < ordem; i++) {
			double somaModulo = 0;
			for (int j = 0; j < ordem; j++) {
				if (a[i][j] != a[i][i]) {
					somaModulo += abs(a[i][j]);
				}
			}
			if (a[i][i] < somaModulo) {
				ehMatrizDominante = false;
			}
		}
		if (ehMatrizDominante) {
			//criar vetor de x
			double *x = new double[ordem];
			double *x0 = new double[ordem];
			//valores iniciais de x = 0;
			for (int i = 0; i < ordem; i++) {
				x[i] = 0;
			}
			//calcular xs
			double teste = 1;
			while (teste > precisao && maxInt < 50) {
				maxInt++;
				for (int i = 0; i < ordem; i++) {
					x0[i] = x[i];
				}
				for (int i = 0; i < ordem; i++) {
					//x[1]=(b1-a12*x2-a13*x3-a1n*xn)/a11;
					//...
					x[i] = b[i];
					for (int j = 0; j < ordem; j++) {
						if (a[i][j] != a[i][i]) {
							x[i] -= a[i][j] * x[j];
						}
					}
					x[i] /= a[i][i];
				}
				cout << "Interacao " << maxInt << endl;
				for (int i = 0; i < ordem; i++) {
					cout << "x" << i << " = " << x[i] << endl;
				}
				cout << endl;
				//teste de parada
				double maxModXi = 0;
				double maxD = 0;
				for (int i = 0; i < ordem; i++) {
					double modX1MenosX0 = abs(x[i]) - abs(x0[i]);
					if (modX1MenosX0 > maxD) {
						maxD = modX1MenosX0;
					}
					if (abs(x[i]) > maxModXi) {
						maxModXi = abs(x[i]);
					}
				}
				teste = maxD / maxModXi;
				cout << "d=  " << maxD << " / " << maxModXi << " = " << teste << endl;

			}
			//exibir raizes
			cout << "As raizes sao: " << endl;
			for (int i = 0; i < ordem; i++) {
				cout << "x" << i << " = " << x[i] << endl;
			}
			cout << endl << "Foram necessarias  " << maxInt << " interacoes." << endl << endl;
			delete x;
		}
		else {
			cout << "A matriz não é diagonal dominante." << endl;
		}
	}
	else {
		cout << "Elemento nulo na diagonal, matriz não pode ser triangularizada" << endl;
	}
	//liberar memoria
	for (n = 0; n < ordem; n++)
		delete[] a[n];

	delete[] a;
	delete b;
}