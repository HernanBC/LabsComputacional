#include <iostream>
#include <cmath> // Incluimos la biblioteca que contiene la funcion sqrt()
#include "tuple.hpp" // Incluye el archivo header para la implementación de sus métodos aquí, solo se incluye en este archivo porque el .hpp solo contiene declaraciones

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
	return std::sqrt(real*real + imaginario*imaginario);
}

Complex Complex::conjugado()const{  	//Implementación de un método que devuelve un objeto de Complex que corresponde al conjugado complejo
	return Complex(real,-imaginario); 	//del vector al que se le aplicó el método.
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOBRECARGA DE OPERADORES ARITMETICOS

// SUMA +
Complex Complex::operator+(const Complex &other) const {
	return Complex(real + other.real, imaginario + other.imaginario);
}

// RESTA -
Complex Complex::operator-(const Complex &other) const {
	return Complex(real - other.real, imaginario - other.imaginario);
}

// MULTIPLICACION *
Complex Complex::operator*(const Complex &other) const {
	return Complex(real*other.real - imaginario*other.imaginario,real*other.imaginario + other.real*imaginario );
}

// DIVISION /
Complex Complex::operator/(const Complex &other) const {
	double denominador = other.norma()*other.norma();
	if (denominador ==0) throw std::runtime_error("La división por cero no existe");

	Complex num = (*this)*other.conjugado();
	return Complex(num.real/denominador , num.imaginario/denominador);
}