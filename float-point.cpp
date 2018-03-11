#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <math.h>
#define BASE 10

using namespace std;

void SistemaDeAritimeticaDePontoFlutuante(int precisao, int limLower, int limUpper){

	int maxValores = 2*( (BASE-1) * (pow(BASE,(precisao-1))) * (limUpper-limLower+1) ) + 1 ;

	float arrayValores[ maxValores ];
	
	stringstream arrayConcat[ maxValores ];

	string arrayString[ maxValores ];

	int indice = 0;

	cout << "Valor: " << maxValores << endl << endl;
	
	for( int i = 1 ; i <= 9 ; i++ ){

		for( int j = 0 ; j <= 9 ; j++ ){

			for( int k = 0 ; k <= 9 ; k++ ){

				for( int z = limLower ; z <= limUpper ; z++ ){

					// CONCATENA OS VALORES NO ARRAY
					arrayConcat[indice] << i << j << k;

					// ESCREVE VALORES EM UM ARRAY DE STRING
					arrayString[indice] = arrayConcat[indice].str();

					// CONVERTE VALOR DO ARRAY DE STRING EM INT E ESCREVE NO ARRAY DE FLOAT
					arrayValores[indice] = atoi( arrayString[indice].c_str() );

					// COMPUTA O VALOR FINAL E ESCREVE NO ARRAY DE FLOAT
					arrayValores[indice] = ((arrayValores[indice])/1000) * (pow(10,z)) ;

					// ESCREVE NA TELA O VALOR
					cout << arrayValores[indice] << "  ";

					// INCREMETA O INDICE
					indice++;

					//cout << "0." << i << j << k << "*10^" << z << "  "; 

				}

			}

		}

	}

	/*
	for ( int i = 0 ; i < maxValores ; i++ ){
		cout << arrayValores[i] << "  ";
	}
	*/

}

int main(){

	SistemaDeAritimeticaDePontoFlutuante(3,-3,3);

	return 0;
}