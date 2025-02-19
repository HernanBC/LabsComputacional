#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>

// Ecuación diferencial
double func(double x, double y){
	return sin(x+y) - cos(x-y);
}

// Implementación del Runge-Kutta 4
// Esta función es la instrucción que se debe realizar en cada punto del intervalo a solucionar
double rk4(double (*func)(double,double),double var_independiente, double var_dependiente, double paso){
	double k1 = func(var_independiente,var_dependiente);
	double k2 = func(var_independiente + 0.5*paso,var_dependiente + 0.5*k1);
	double k3 = func(var_independiente + 0.5*paso,var_dependiente + 0.5*k2);
	double k4 = func(var_independiente + paso,var_dependiente + k3);

	return var_dependiente + paso*(k1 + 2*k2 + 2*k3 + k4)*(1.0/6.0);
}

// EXTRA: No se solicita pero con esto obtengo los datos para graficar posteriormente

// Función para escribir múltiples vectores en un archivo CSV
void escribirCSV(const std::string& nombre_archivo, const std::vector<std::string>& encabezados, const std::vector<std::vector<double>>& datos) {
    // Abrir el archivo en modo escritura
    std::ofstream archivo(nombre_archivo);

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << nombre_archivo << std::endl;
        return;
    }

    // Verificar que haya al menos un vector de datos y que todos tengan el mismo tamaño
    if (datos.empty()) {
        std::cerr << "No hay datos para escribir en el archivo." << std::endl;
        return;
    }
    
    size_t filas = datos[0].size();
    for (const auto& vec : datos) {
        if (vec.size() != filas) {
            std::cerr << "Error: Todos los vectores deben tener la misma longitud." << std::endl;
            return;
        }
    }

    // Escribir los encabezados si están disponibles
    if (!encabezados.empty()) {
        for (size_t i = 0; i < encabezados.size(); ++i) {
            archivo << encabezados[i];
            if (i < encabezados.size() - 1) archivo << ",";
        }
        archivo << "\n";
    }

    // Escribir los datos fila por fila
    for (size_t i = 0; i < filas; ++i) {
        for (size_t j = 0; j < datos.size(); ++j) {
            archivo << datos[j][i];
            if (j < datos.size() - 1) archivo << ",";
        }
        archivo << "\n";
    }

    // Cerrar el archivo
    archivo.close();
    std::cout << "Datos guardados en " << nombre_archivo << std::endl;
}


int main(){

	double paso = 0.025; // Paso
	double var_independ_inicial = 0.0; // Valor inicial de la variable independiente x
	double var_independ_final = 25.0; // Valor final de la variable independiente x

	double var_depend_inicial = 0.0; // Valor inicial o condición inicial de la variable dependiente y ||||| y(x=0) = 0

	// Numero de iteraciones a realizar
	int ncasillas = std::floor((var_independ_final - var_independ_inicial)/paso);
	std::vector<double> y(ncasillas+1); // Vector donde se guardaran los valores solución de la ecuación difencial
	std::vector<double> x(ncasillas+1); // Vector donde se guardaran todos lo valores de la variable independiente
	for (int i =0; i < ncasillas+1; ++i){
		x[i] = var_independ_inicial +i*paso;
		//std::cout<<x[i]<<std::endl;
	}

	y[0] = var_depend_inicial; // Se le asigna a la solución la condición inicial de la ecuación diferencia y(x=0) = y0
	for (int i =0; i < ncasillas; ++i){
		y[i+1] = rk4(func, x[i], y[i], paso);
		//std::cout<<y[i]<<std::endl;
	}
	std::vector<std::string> encabezados = {"x","y"} ;
	escribirCSV("solution.csv",encabezados, {x, y});


	return 0;
}