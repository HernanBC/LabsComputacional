#include <iostream>

double integrando(double x){
	return 4.0/(1.0+x*x); // Función que va a ser integrada
}


double SumaRiemann(double (*integrando)(double),double x_inf, double x_sup, int NumeroCuadrados){
	double h = (x_sup - x_inf)/NumeroCuadrados; // Base de los rectangulos 

	double I =0.0; //Acumulador
	for (int i = 0; i < NumeroCuadrados; ++i){ // ciclo para iterar de i =0 hasta i = N-1, sumando i de 1 en 1
		I += integrando(x_inf+(i+0.5)*h) ; // Evaluando la función del integrando en el límite interior + (i+0.5)*h
	}
	return I*h; // Devolviendo el acumulador multiplicado por h
} 


int main(){
	std::cout.precision(8); // El output va a tener 8 decimales de presición
	std::cout << SumaRiemann(integrando, 0.0,1.0,1000) << std::endl; // printeando el resultado
	return 0;
}