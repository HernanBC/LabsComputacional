#include <iostream>
#include <omp.h>
#include <sys/time.h>
#include <vector>
#include <cstdio>
#include <cstdlib>

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

// Se va a usar GNUPLOT para realizar la gráfica

void plot_graph(const std::vector<int>& threads, const std::vector<double>& times) {
	FILE* gnuplot = popen("gnuplot -persistent", "w");
	if (gnuplot) {
		fprintf(gnuplot, "set title 'Escalabilidad con OpenMP'\n");
		fprintf(gnuplot, "set xlabel 'Número de hilos'\n");
		fprintf(gnuplot, "set ylabel 'Speed-up'\n");
		fprintf(gnuplot, "plot '-' with linespoints title 'Escalabilida vs Hilos'\n");
		for (size_t i = 0; i < threads.size(); ++i) {
			fprintf(gnuplot, "%d %f\n", threads[i], times[i]);
		}
		fprintf(gnuplot, "e\n"); // Finaliza la entrada de datos
		fclose(gnuplot);
	} else {
		std::cerr << "Error al abrir gnuplot." << std::endl;
	}
}


int main(){
	// std::cout.precision(8); // El output va a tener 8 decimales de presición
	// std::cout << SumaRiemann(integrando, 0.0,1.0,1000) << std::endl; 
	// printeando el resultado de integrar una función llamada integrando de 0 a 1 y usando 1000 rectangulos

	std::vector<int> threads_list = {1, 2, 3, 4}; // Número de hilos a probar
    std::vector<double> times;                        // Almacenar los tiempos de ejecución

    // Probar diferentes números de hilos
    for (int num_threads : threads_list) {
        omp_set_num_threads(num_threads); // Configura el número de hilos
        double time_1 = seconds();
        SumaRiemann(integrando, 0.0, 1.0, 1000000000);
        double time_2 = seconds();
        double total_time = time_2 - time_1;
        times.push_back(total_time);
        
        std::cout << "Threads: " << num_threads << " Time: " << total_time << " seconds" << std::endl;
    }

	std::vector<double> speed_up = times;
    for (size_t i = 0; i < times.size(); ++i) {
    speed_up[i] = times[0]/speed_up[i];
    }


	// Grafica de escalabilidad
    plot_graph(threads_list, speed_up);
	return 0;
}

// Nota: Mi computadora solo tiene 2 cores, por lo que al solicitar números más gran de 2 para los threads a probar genera resultados extraños