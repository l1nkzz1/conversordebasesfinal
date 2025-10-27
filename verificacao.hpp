#include <iostream>
#include <string>

 using namespace std;


 inline string baseentrada, basesaida;

inline void verificacaovalores(void){

  do{

    cout << "Informe a base de entrada: ";
    cin >> baseentrada;

  }while(baseentrada < 2 || baseentrada > 16);

  do{

    cout << "Informe a base de saída: ";
    cin >> basesaida;

  }while(basesaida < 2 || baseentrada > 16);

  
}
