#include <iostream>
#include <sys/time.h>
#include <omp.h>

double seconds()
{
	struct timeval tmp;
	double sec;
	gettimeofday( &tmp, (struct timezone *)0 );
	sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
	return sec;
}

double integrando(double x){ // Se define que la función devuelve un double y depende de una variable double llamada x
	return 4.0/(1.0+x*x); // Función que va a ser integrada
}


double SumaRiemann(double (*integrando)(double),double x_inf, double x_sup, int NumeroCuadrados){ 
	// Se define una función que realice la Suma de Riemman para cualquier función matematica tipo double y dependiente de una variable tipo double.
	// La función requiere de input de límite inferior y superior para la integral y el número de rectangulos que se van a utilizar en la aproximación.

	double h = (x_sup - x_inf)/NumeroCuadrados; // Base de los rectangulos 

	int num_procs;
	
	
	double I =0.0; //Acumulador
	double time_1 = seconds();
	#pragma omp parallel
	{
	num_procs = omp_get_num_threads();
	#pragma omp for reduction(+: I)
		
	for (int i = 0; i < NumeroCuadrados; ++i){ // ciclo para iterar de i =0 hasta i = N-1, sumando i de 1 en 1
		I += integrando(x_inf+(i+0.5)*h) ; // Evaluando la función del integrando en el límite interior + (i+0.5)*h y acumulando el resultado en la variable I
	}
	}

	double time_2 = seconds();
	std::cout<<"Tiempo: "<< time_2 - time_1 << std::endl;
	std::cout<<"Threads: "<< num_procs<<std::endl;
	return I*h; // Devolviendo el acumulador multiplicado por h
}


int main(){
	std::cout.precision(8); // El output va a tener 8 decimales de presición
	std::cout << SumaRiemann(integrando, 0.0,1.0,1000) << std::endl; 
	// printeando el resultado de integrar una función llamada integrando de 0 a 1 y usando 1000 rectangulos
	return 0;
}