#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>


using namespace std;

int valor_do_digito(char digito) {
    if (digito >= '0' && digito <= '9') {
        return digito - '0';
    } else if (digito >= 'A' && digito <= 'F') {
        return digito - 'A' + 10;
    } else if (digito >= 'a' && digito <= 'f') {
        return digito - 'a' + 10;
    }
    return -1;
}

char digito_do_valor(int valor) {
    if (valor >= 0 && valor <= 9) {
        return valor + '0';
    } else if (valor >= 10 && valor <= 15) {
        return valor - 10 + 'A';
    }
    return '?';
}


long long para_decimal(string numero_str, int base_origem) {
    long long decimal = 0;
    int potencia = 0;


    reverse(numero_str.begin(), numero_str.end());

    for (char digito_char : numero_str) {
        int valor = valor_do_digito(digito_char);

        if (valor == -1 || valor >= base_origem) {
            return -1;
        }

        decimal += (long long)valor * round(pow(base_origem, potencia));
        potencia++;
    }

    return decimal;
}

string de_decimal(long long decimal, int base_destino) {
    if (decimal == 0) return "0";

    string resultado = "";

    while (decimal > 0) {
        int resto = decimal % base_destino;
        char digito = digito_do_valor(resto);
        resultado += digito;
        decimal /= base_destino;
    }

    reverse(resultado.begin(), resultado.end());
    return resultado;
}

int main() {
    string numero_str;
    int base_origem, base_destino;

    cout << "Conversor de Bases Numericas (2 a 16)\n";

  // Base de entrada de 2 até 16
  do{
    cout << "Digite a base de origem (2 a 16): ";
    cin >> base_origem;
    if (base_origem < 2 || base_origem > 16) {
        cerr << "Erro: Base de origem invalida.\n";
    }
  }while(base_origem < 2 || base_origem > 16);


  // Usuario informa o valor para ser convertido
informar_base:
    cout << "Digite o numero na base " << base_origem << ": ";
    cin >> numero_str;

   long long decimal = para_decimal(numero_str, base_origem);

  // valida se o valor informado condiz com a base escolhida
    if (decimal == -1) {
      cerr << "Erro: O numero digitado contem digitos invalidos para a base " << base_origem << ".\n";
    goto informar_base;
    }

 // Base de saida de 2 até 16
  do{
    cout << "Digite a base de destino (2 a 16): ";
    cin >> base_destino;
   if (base_destino < 2 || base_destino > 16){
      cerr << "Erro: Base de origem inválida.\n";
    } 
  }while(base_destino < 2 || base_destino > 16);


    string resultado_final = de_decimal(decimal, base_destino);

    cout << "\nResultado da conversao:\n";
    cout << numero_str << " (Base " << base_origem << ") = " 
         << resultado_final << " (Base " << base_destino << ")\n";

    return 0;
}
