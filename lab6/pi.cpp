#include <iostream>

double integrando(double x){ // Se define que la función devuelve un double y depende de una variable double llamada x
	return 4.0/(1.0+x*x); // Función que va a ser integrada
}


double SumaRiemann(double (*integrando)(double),double x_inf, double x_sup, int NumeroCuadrados){ 
	// Se define una función que realice la Suma de Riemman para cualquier función matematica tipo double y dependiente de una variable tipo double.
	// La función requiere de input de límite inferior y superior para la integral y el número de rectangulos que se van a utilizar en la aproximación.

	double h = (x_sup - x_inf)/NumeroCuadrados; // Base de los rectangulos 

	double I =0.0; //Acumulador
	for (int i = 0; i < NumeroCuadrados; ++i){ // ciclo para iterar de i =0 hasta i = N-1, sumando i de 1 en 1
		I += integrando(x_inf+(i+0.5)*h) ; // Evaluando la función del integrando en el límite interior + (i+0.5)*h y acumulando el resultado en la variable I
	}
	return I*h; // Devolviendo el acumulador multiplicado por h
} 


int main(){
	std::cout.precision(8); // El output va a tener 8 decimales de presición
	std::cout << SumaRiemann(integrando, 0.0,1.0,1000) << std::endl; 
	// printeando el resultado de integrar una función llamada integrando de 0 a 1 y usando 1000 rectangulos
	return 0;
}