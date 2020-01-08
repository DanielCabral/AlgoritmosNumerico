#include <iostream>
using namespace std;
void conversao();
void conversaoDecimalBinario();
int main() {
	cout << "1- Conversão" << endl;
	cout << "2- Erros" << endl;
	cout << "3- Polinomio de Taylor" << endl;
	cout << "4- Zero de funcoes" << endl;
	int escolha;
	cin >> escolha;
	switch (escolha) {
		case 1:
			conversao();
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			break;
	}
	system("pause");																																					
	return 0;
}
void conversao() {
	cout << "1- Conversão de decimal para binario" << endl;
	cout << "2- Conversão de binario para decimal" << endl;
	int escolha;
	cin >> escolha;
	switch (escolha) {
	case 1:
		conversaoDecimalBinario();
		break;
	case 2:
	default:
		break;
	}
}
void conversaoDecimalBinario() {
	cout << "Digite o numero binario: " << endl;
	int num;
	cin >> num;
	int temp = num;
	int dec = 0;
	int i = 1;
	while (temp) {
		int ultimoDig = temp % 10;
		temp /= 10;
		dec += ultimoDig * i;
		i *= 2;
	}
	cout << " dec: " << dec;
}

void conversaoBinarioDecimal() {
	cout << "Digite o numero em binario: " << endl;
	int numero;
}