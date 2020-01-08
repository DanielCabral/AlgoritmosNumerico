#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 255
#define ALG 17

//prototipos das funções
using namespace std;
void conversoesMenu();
void zeroDeFuncoesMenu();
void sistemasLinearesMenu();
void decToBase(int, int);
void baseToDec(char*, int);
double calcularFuncao(double);
double calcularFuncao2(double);
void biseccao();
void posicaoFalsa();
void pontoFixo();
double funcao(double);
double funcaoDerivada(double);
void metodoNewton();
void metodoSecante();
void normas();
void eliminacaoGaussiana();
void sistemaLinearTriangularSuperior();
void sistemaLinearTriangularInferior();


int main() {
	int escolha=-1;
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
	int number;
	int opt=-1;
	while (opt != 0) {
	
	cout<<"Conversor De Bases Numericas"<<endl << endl;
	cout<<"1 - Binário     ->  Decimal      " << endl;
	cout<<"2 - Decimal     ->  Binário      " << endl;
	cout<<"3 - Octal       ->  Decimal      " << endl;
	cout<<"4 - Decimal     ->  Octal        " << endl;
	cout<<"5 - Hexadecimal ->  Decimal      " << endl;
	cout<<"6 - Decimal     ->  Hexadecimal " << endl;
	cout<<"0 - voltar" << endl;
	cout << "digite uma opcao: ";
	cin >> opt;

		char str[SIZE];
		switch (opt) {
		case 0:
			break;
		case 1:
			printf("Binário: ");
			cin>> str;
			baseToDec(str, 2);
			break;
		case 2:
			printf("Decimal: ");
			cin >> number;
			decToBase(number, 2);
			break;
		case 3:
			printf("Octal = ");
			cin >> str;
			baseToDec(str, 8);
			break;
		case 4:
			printf("Decimal = ");
			cin >> number;
			decToBase(number, 8);
			break;
		case 5:
			printf("Hexadecimal = ");
			cin >> str;
			baseToDec(str, 16);
			break;
		case 6:
			printf("Decimal: ");
			cin>>number;
			decToBase(number, 16);
			break;
		default:
			printf("OPCAO NAO PERMITIDA!\nTENTE NOVAMENTE\n");
			break;
		}
	}
}
// Esta função converte um número decimal para a base 2, 8 ou 16.
void decToBase(int num_dec, int base) {
	char resto[ALG] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' }, num_conv[SIZE];
	int indx = 0;

	// Este loop realiza as operações de divisão. Os restos são guardados no vetor 'num_conv'
	while (num_dec > 0) {
		num_conv[indx] = resto[num_dec % base];
		num_dec /= base;
		indx++;
	}

	// Exclui o caractere especial '\0' do final da string
	indx -= 1;

	// Utilizado para identificar a saída do programa
	switch (base) {
	case 2: printf("Binário: "); break;
	case 8: printf("Octal: "); break;
	case 16: printf("Hexadecimal: "); break;
	}

	// Inverte a string contida no vetor num_conv
	for (indx; indx >= 0; indx--)
		printf("%c", num_conv[indx]);
	printf("\n");

}

// Esta função permite converter um número na base 2, 8 ou 16 para a base decimal. 
void baseToDec(char* num_base, int base) {
	int indx = 0, exp = 0, len = 0, dec = 0, num = 0;

	// Este loop determina o tamanho da string
	while (num_base[len] != '\0') {
		len++;
	}

	// Neste loop, a string é percorrida de trás para frente. Cada caractere é convertido
	for (exp, indx = (len - 1); exp < len; exp++, indx--) {
		if (base == 16) {
			switch (num_base[indx]) {
			case 'A': num = 10; break;
			case 'a': num = 10; break;
			case 'B': num = 11; break;
			case 'b': num = 11; break;
			case 'C': num = 12; break;
			case 'c': num = 12; break;
			case 'D': num = 13; break;
			case 'd': num = 13; break;
			case 'E': num = 14; break;
			case 'e': num = 14; break;
			case 'F': num = 15; break;
			case 'f': num = 15; break;
			default: num = (int)num_base[indx] - (int)'0';
			}
		}
		else
			num = (int)num_base[indx] - (int)'0';

		// Aqui avalia se o usuário digitou um número válido ou não!
		if (num > (base - 1) || num < 0) {
			printf("Voce informou um numero invalido!\n");
			exit(0);
		}
		dec += num * pow(base, exp);
	}

	// O número convertido para decimal é exibido
	printf("DECIMAL: %d\n", dec);
}
void zeroDeFuncoesMenu() {
	int escolha = -1;
	while (escolha != 0) {
		cout <<endl<< "1- Metodo da biseccao" << endl;
		cout << "2- Posicao Falsa" << endl;
		cout << "3- Ponto Fixo" << endl;
		cout << "4- Secante" << endl;
		cout << "5- Newton" << endl;
		cout << "0- Voltar" << endl;
		cout << "digite uma opcao: ";
		cin >> escolha;
		switch (escolha) {
		case 1:
			biseccao();
			break;
		case 2:
			posicaoFalsa();
			break;
		case 3:
			pontoFixo();
			break;
		case 4:
			metodoSecante();
			break;
		case 5:
				metodoNewton();
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
		cout << "0- Voltar" << endl;
		cout << "digite uma opcao: ";
		cin >> escolha;
		switch (escolha) {
		case 1:
			normas();
			break;
		case 2:
			sistemaLinearTriangularSuperior();
			break;
		case 3:
			sistemaLinearTriangularInferior();
			break;
		case 4:
			eliminacaoGaussiana();
			break;
		default:
			break;
		}
	}
}
void biseccao() {
	double a = 1, b = 1,precisao;
	int numInteracoes = 0;
	//Ler a0 e b0 e precisao
	cout << "Digite o valor de a: " << endl;
	cin >> a;
	cout << "Digite o valor de b: " << endl;
	cin >> b;
	cout << "Digite o valor da precisao: " << endl;
	cin >> precisao;
	double fa = calcularFuncao(a);
	double fb = calcularFuncao(b);
	//testar se f(a)*f(b)<0
	if ((fa*fb) < 0) {
		cout << ""<<endl;
		while ((b - a > precisao)) {
			cout << "Iteracao " << numInteracoes + 1 << endl;
			//Calcular xn
			double x = (a + b) / 2;
			cout << "x" << numInteracoes + 1 << " = (" << a << "+" << b << ")/2= " << x << endl;
			//calcular valor do x aplicado na funcao 
			double fx = calcularFuncao(x);
			cout << "f(x)= " << fx;
			if (fx < 0) {
				cout << ", x>0" << endl;
				cout << "a" << numInteracoes + 1 << " = a" << numInteracoes << " = " << a << endl;
				cout << "b" << numInteracoes + 1 << " = x" << numInteracoes + 1 << " = " << x << endl;
				b = x;
			}
			else {
				cout << ", x<0" << endl;
				cout << "a" << numInteracoes + 1 << " = x" << numInteracoes + 1 << " = " << x << endl;
				cout << "b" << numInteracoes + 1 << " = b" << numInteracoes << " = " << b << endl;
				a = x;
				
			}
			cout << endl;
			numInteracoes++;
			if (numInteracoes > 100) {
				cout << "Dentro do intervalo informado, para a função definida, não houve convergência." << endl << endl;
				break;
			}
		}
		
	}
	else {
		cout << "Não existem raizes reais dentro do intervalo inserido." << endl;
	}
}
void posicaoFalsa() {
	double a = 1, b = 1, precisao;
	int numInteracoes = 0;
	//Ler a0 e b0
	cout << "Digite o valor de a: " << endl;
	cin >> a;
	cout << "Digite o valor de b: " << endl;
	cin >> b;
	cout << "Digite o valor da precisao: " << endl;
	cin >> precisao;
	double fa = calcularFuncao(a);
	double fb = calcularFuncao(b);	
	double fx=0;

	//testar se f(a)*f(b)<0
	if ((fa*fb) < 0) {
		cout << "" << endl;
		double modFa, modFb;
		do{
			cout << "Iteracao " << numInteracoes + 1 << endl;
			//Calcular xn
			fa = calcularFuncao(a);
			fb = calcularFuncao(b);
			modFa = fa;
			modFb = fb;
			if (fa < 0)
				modFa *= -1; 
			if (fb < 0)
				modFb *= -1;

			double x = (((a*fb -b*fa)) / (fb-fa));
			cout << "x" << numInteracoes + 1 << " = (" << a<<"*"<<modFb << "+" << b<<"*"<<modFa << ")/("<<modFb<<" + "<<modFa <<")= " << x << endl;
			//calcular valor do x aplicado na funcao 
			fx = calcularFuncao(x);
			cout << "f(x)= " << fx;
			if (fa*fx < 0) {
				cout << ", x>0" << endl;
				cout << "a" << numInteracoes + 1 << " = a" << numInteracoes << " = " << a << endl;
				cout << "b" << numInteracoes + 1 << " = x" << numInteracoes + 1 << " = " << x << endl;
				b = x;
			}
			else {
				cout << ", x<0" << endl;
				cout << "a" << numInteracoes + 1 << " = x" << numInteracoes + 1 << " = " << x << endl;
				cout << "b" << numInteracoes + 1 << " = b" << numInteracoes << " = " << b << endl;
				a = x;
				
			}
			cout << endl;
			numInteracoes++;
			if (numInteracoes > 100) {
				cout << "Dentro do intervalo informado, para a função definida, não houve convergência." << endl << endl;
				break;
			}
			if (fx < 0)
				fx *= -1;
		} while ((b - a > precisao) && fx>precisao);

	}
	else {
		cout << "Não existem raizes reais dentro do intervalo inserido." << endl;
	}
}

void pontoFixo() {
	double precisao, precisao2,aux,valorx,aux2;
	int numInteracoes = 0;
	//Ler a0 e b0
	cout << "Digite o valor de x: " << endl;
	cin >> valorx;
	cout << "Digite o valor de precisao de |x1-x0|: " << endl;
	cin >> precisao;
	cout << "Digite o valor da precisao |f(x)|: " << endl;
	cin >> precisao2;
	double fx=calcularFuncao2(valorx);
	double erro=1;
	//se |f(x0|>precisao
	if (abs(fx)>precisao2) {
		do {
			//calcular função é a fi  de x
			//calcular função 2 é a f(x)
			//para testar, mudar o retorno da função
			aux = (calcularFuncao(valorx));
			aux2 = valorx;
			valorx = aux;
			numInteracoes++;
		} while ((abs(calcularFuncao2(aux)) > precisao2) && (abs(aux - aux2) > precisao) && numInteracoes < 90);

		if (numInteracoes > 90) { // Quando não é possivel obter uma raiz convergente dentro do limite de iteração
			cout << "Nao foi possivel obter a convergencia!!!" << endl << endl;
		}
		else {// resultado
			cout << endl;
			cout << "Raiz da equacao: " << aux << endl;
			cout << "Numero de iteracoes: " << numInteracoes << endl;

		}
	}
	else {
		cout << "Raiz: " <<valorx<< endl;
	}
}
void metodoNewton() {
	double x0, k, eps;

	cout << "digite o x0 inicial :";
	cin >> x0;
	cout << "digite a precisao:";
	cin >> eps;
	cout << "digite o numero maximo de iteracoes:";
	cin >> k;
	int cont;
	for (cont = 0; cont < k; cont++) {
		double x = x0 - (funcao(x0) / funcaoDerivada(x0));
		cout << "k = " << cont << "; x = " << x << "\n";
		//Condição de parada:
		if ((fabs(x - x0) < eps) || fabs(x - x0) / fabs(x) < eps || fabs(x0) < eps) {
			cout << "Raiz encontrada: " << x << "\n";
			break;
		}
		x0 = x;
	}
	cout << "encontrada em " << cont+1 << " iteracoes. \n";
}

void metodoSecante() {
	float a, b, eps, eps2;

	cout << "\nDigite o valor de 'a':" << endl;
	cin >> a;
	cout << "\nDigite o valor de 'b':" << endl;
	cin >> b;
	cout << "\nInforme a precisao desejada:" << endl;
	cin >> eps;
	cout << "\nInforme a precisao desejada para |f(x)|:" << endl;
	cin >> eps2;

	double c, erro, i = 0;
	if (a == b) {
		cout << "\nOs valores devem ser diferentes. Digite um novo valor para B:" << endl;
		cin >> b;
	}

	else {
		c = (a*funcao(b) - b * funcao(a)) / (funcao(b) - funcao(a));

		erro = fabs(b - a);
		i++;
		while (erro > eps && abs(funcao(c))>eps2) {

			a = b;
			b = c;

			c = (a*funcao(b) - b * funcao(a)) / (funcao(b) - funcao(a));
			erro = fabs(b - a);
			i++;
		}
		cout << "\n raiz encontrada:" << c << endl;
		cout << "\n em : " << i << " iteracoes";
	}
}

//função metodo de newton
double funcao(double x) {
	//Se desejar utilizar outra f(x), alterar essa função x0=0.5 precisao=10^-4
	return (x*x*x) - (9 * x) + 3;
}

//função derivada para o metodo de newton
double funcaoDerivada(double x) {
	//se alterar f(x), alterar a derivada aqui tbm
	return 3 *(x*x) - 9; //Derivada da funcao
}

double calcularFuncao(double x) {
	//biseccao e posicao falsa[0,1] precisao=10^-3 e 5*10-4
	//para secante, x0=0,x1=1  precisao= 5*10-4
	//double res = (x*x*x)-(9*x)+3;
	//double res = 1/2*sqrt((10-pow(x,3)));
	//double res=x*x+x-6 x0=1.5
	//ponto fixo raiz(x^3/9)+1/3 x0=0.5 precisao=^*10-4
	double res = (pow(x, 3.0) / 9.0) + (1 / 3.0);
	return res;
}
double calcularFuncao2(double x) {
	//pontofixo
	double res = (x*x*x)-(9*x)+3;
	return res;
}
void normas() {
	cout.precision(6);
	cout << fixed;
	int ordem;
	cout << "Digite a ordem da matriz: ";
	cin >> ordem;

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
	double max=0;
	//Norma infinito ou norma do máximo
	for (int i = 0; i < ordem; i++) {
		double soma = 0;
		for (int j = 0; j < ordem; j++) {
			soma += abs(a[i][j]);
		}
		if (soma > max) {
			max = soma;
		}
	}
	cout << "Norma infinito ou norma do maximo: " << max<<endl;
	max = 0;
	//Norma infinito ou norma do máximo
	for (int i = 0; i < ordem; i++) {
		double soma = 0;
		for (int j = 0; j < ordem; j++) {
			soma += abs(a[j][i]);
		}
		if (soma > max) {
			max = soma;
		}
	}
	cout << "Norma 1: " << max <<endl;

	double s = 0;
	for (int i = 0; i < ordem; i++) {
		for (int j = 0; j < ordem; j++) {
			s =s + pow(abs(a[i][j]), 2);
		}
	}
	s = sqrt(s);
	cout << "Norma de Frobenius: " << s << endl << endl;

}
void sistemaLinearTriangularInferior() {
	cout.precision(6);
	cout << fixed;
	int ordem;
	cout << "Digite a ordem da matriz: ";
	cin >> ordem;

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

	//testar se é triangular superior
	//Para isso, todos os elementos abaixo da diagonal principal devem ser igual a zero
	bool ehTriangularInferior = true;
	for (int i = 0; i < ordem-1; i++) {
		for (int j = i+1; j < ordem; j++) {
			if (a[i][j] != 0) {
				cout << i << j << " ";
				ehTriangularInferior = false;
			}
		}
		cout << endl;
	}
	if (ehTriangularInferior) {
		//criar vetor de x
		double *x = new double[ordem];
		x[0] = b[0] / a[0][0];

		//calcular valores de x
		for (int k = 1; k < ordem; k++) {
			double soma = 0;
			for (int i = 0; i <k; i++) {
				soma =soma+ (a[k][i] * x[i]);
			}
			x[k] = (b[k] - soma) / a[k][k];
		}
		//imprimir matriz final
		for (n = 0; n < ordem; n++) {
			for (int j = 0; j <= ordem; j++) {
				if (j == ordem) {
					cout << b[n] << " ";
				}
				else {
					cout << a[n][j] << " ";
				}
			}
			cout << endl;
		}
		cout << "Solucoes: " << endl;
		//imprimir x
		for (n = 0; n < ordem; n++) {
			cout << "x" << (n + 1) << ": " << x[n] << endl;
		}
		delete x;
	}
	else {
		cout << "Sistema nao eh triangular inferior, nao foi possivel resolver." << endl;
	}
	//liberar memoria
	for (n = 0; n < ordem; n++)
		delete[] a[n];

	delete[] a;
	delete b;

}
void sistemaLinearTriangularSuperior() {
	cout.precision(6);
	cout << fixed;
	int ordem;
	cout << "Digite a ordem da matriz: ";
	cin >> ordem;

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

	//testar se é triangular superior
	//Para isso, todos os elementos abaixo da diagonal principal devem ser igual a zero
	bool ehTriangularSuperior = true;
	for (int i = 1; i < ordem; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i][j] != 0)
				ehTriangularSuperior = false;
		}
		cout<<endl;
	}
	if (ehTriangularSuperior) {
		//criar vetor de x
		double *x = new double[ordem];
		double soma = 0;
		x[ordem - 1] = b[ordem - 1] / a[ordem - 1][ordem - 1];

		//calcular valores de x
		for (int k = ordem - 2; k >= 0; k--) {
			for (int i = k + 1; i < ordem; i++) {
				soma += a[k][i] * x[i];
			}
			x[k] = (b[k] - soma) / a[k][k];
			soma = 0;
		}
		
		//imprimir matriz final
		for (n = 0; n < ordem; n++) {
			for (int j = 0; j <= ordem; j++) {
				if (j == ordem) {
					cout << b[n] << " ";
				}
				else {
					cout << a[n][j] << " ";
				}
			}
			cout << endl;
		}
		cout << "Solucoes: " << endl;
		//imprimir x
		for (n = 0; n < ordem; n++) {
			cout << "x" << (n + 1) << ": " << x[n] << endl;
		}
		delete x;
	}
	else {
		cout << "Sistema nao eh triangular superior, nao foi possivel resolver." << endl;
	}
	//liberar memoria
	for (n = 0; n < ordem; n++)
		delete[] a[n];

	delete[] a;
	delete b;

}
void eliminacaoGaussiana() {
	cout.precision(2);
	cout << fixed;
	int ordem;
	cout << "Digite a ordem da matriz: ";
	cin >> ordem;

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
			cout << "Digite o a"<<(n+1)<<(j+1)<<":";
			cin >> a[n][j];
		}
	}

	//leitura do vetor b
	for (n = 0; n < ordem; n++) {
		cout << "Digite o b" << (n + 1)<< ":";
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
				for (int j = k + 1; j < n; j++) {
					a[i][j] = a[i][j] - m * a[k][j];
				}
				b[i] = b[i] - m * b[k];
			}
		}

		//criar vetor de x
		double *x = new double[ordem];
		double soma = 0;
		x[ordem - 1] = b[ordem - 1] / a[ordem - 1][ordem - 1];
		//calcular valores de x
		for (int k = ordem - 2; k >= 0; k--) {
			for (int i = k + 1; i <= ordem - 1; i++) {
				soma += a[k][i] * x[i];
			}
			x[k] = (b[k] - soma) / a[k][k];
			soma = 0;
		}
		//imprimir matriz final
		for (n = 0; n < ordem; n++) {
			for (int j = 0; j <= ordem; j++) {
				if (j == ordem) {
					cout << b[n] << " ";
				}
				else {
					cout << a[n][j] << " ";
				}
			}
			cout << endl;
		}
		//imprimir x
		for (n = 0; n < ordem; n++) {
			cout << "x" << (n + 1) << ": " << x[n] << endl;
		}
		delete x;
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