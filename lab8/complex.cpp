#include <iostream>
#include "complex.hpp" // Incluye el archivo header para la implementación de sus métodos aquí

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CONSTRUCTORES

Complex::Complex(){		 // Inicialización del constructor por defecto
	real = 0.0; 		 // Asigno los atributos tal que se inicie el objeto como z = 0.0 + 0.0*i
	imaginario = 0.0;
}

Complex::Complex(double _real, double _imaginario){ // Inicialización del constructor personalizado
	real = _real; 									// Asigno los atributos a la correspondiente variable inicializada
	imaginario = _imaginario;
}

Complex::Complex(const Complex &other){ 	// Inicialización del constructor copia
	real = other.real;						// Asigna a un nuevo objeto los valores de los atributos del objeto original, hace un shallow copy
	imaginario = other.imaginario;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DESTRUCTOR

Complex::~Complex(){

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OPERADOR ASIGNACION
Complex &Complex::operator=(const Complex &other){  // Sobrecarga del operador asignación
			if (this != &other){ 					// Es necesario verificar que no estamos asignando un objeto así mismo
				real = other.real;
				imaginario = other.imaginario;
			}
			return *this;
		}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// METODOS

void Complex::print() const { 		// Implementación del método para imprimir un número complejo en su forma z = z +y*i
	std::cout.precision(5);
	std::cout<< real << " + " << imaginario <<" * i"<< std::endl;
}

double Complex::norma() const { 		// Implementación del método que devuelve la norma de un número complejo
	return real*real + imaginario*imaginario;
}

Complex Complex::conjugado()const{  	//Implementación de un método que devuelve un objeto de Complex que corresponde al conjugado complejo
	return Complex(real,-imaginario); 	//del vector al que se le aplicó el método.
}