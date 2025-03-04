#include <iostream>
#include <algorithm> 	// Incluyo biblioteca para usar copy
#include "tuple.hpp" // Incluye el archivo header para la implementación de sus métodos aquí, solo se incluye en este archivo porque el .hpp solo contiene declaraciones


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CONSTRUCTORES

Tuple::Tuple(): size(1){		 // Inicialización del constructor por defecto
	data = new double[size]; 	// Se coloca el size(1) en la lista de inicialización con el propósito de inicializar antes de que se ejecute el constructor. De no ser así, se cae en la asignación de un objeto temporal y luego se asignaría.
	data[0] = 0.0;				// Asigno un espacio de memoria para un array double, en este caso un array que tiene solo un miembro y le asigno a ese elemento el valor 0.0;
}

Tuple::Tuple(size_t size) : size(size) { // Inicialización del constructor personalizado
	data = new double[size];			// Se asigna un espacio de memoria para un array de double con un tamaño dado al llamar el constructor
	for (size_t i = 0; i < size; ++i){ // Se llenan todos los elementos del array con el valor cero.
		data[i] = 0.0;
	}
}

Tuple::Tuple(const Tuple &other) : size(other.size) { 	// Inicialización del constructor copia
	data = new double[size];							// Asigna a memoria dinámica para un nuevo objeto data
	std::copy(other.data, other.data+ size, data);	// Copia un rango de elementos de una secuencia a otra
}														// La combinación de las líneas anteriores da como resultado una deep copy del objeto original

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DESTRUCTOR

Tuple::~Tuple(){
	delete[] data; // Libera la memoria existente
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OPERADOR ASIGNACION
// Se sobrecarga el operador para reasignar la forma y contenidos de un tuple en otro
Tuple &Tuple::operator=(const Tuple &other){  // Sobrecarga del operador asignación
	if (this != &other){ 			  // Es necesario verificar que no estamos asignando un objeto así mismo
		Tuple temp(other);
		std::swap(size, temp.size); // Intercambio de atributos
		std::swap(data, temp.data); // Intercambio de atributos
	}
	return *this;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOBRECARGA DE OPERADORES ARITMETICOS

// Para realizar las operaciones aritméticas, los objetos deben tener el mismo tamaño, por lo que esta será una restricción que se encontrará en todas las
// sobrecargas

// SUMA +
// Se sobrecarga al operador para sumar elemento a elemento entre dos tuples
Tuple Tuple::operator+(const Tuple &other) const {
	if (size != other.size){				// Verificación de tamaños
		throw std::invalid_argument("Los arreglos a operar no poseen el mismo tamaño"); // Mensaje de error
	}
	Tuple result(size); // Se genera un nuevo objeto con el constructor personalizado y que contiene un size de ceros
	for (size_t i =0; i < size; ++i){
		result.data[i] = data[i] + other.data[i]; // Mediante el ciclo se van reasignando las entradas de result, una a una, a partir de la suma
	}											  // de elementos individuales de los objetos originales
	return result;	// Se retorna el resultado de la suma de elementos 1 a 1
}

// RESTA -
// Se sobrecarga al operador para restar elemento a elemento entre dos tuples
Tuple Tuple::operator-(const Tuple &other) const {
	if (size != other.size){				// Verificación de tamaños
		throw std::invalid_argument("Los arreglos a operar no poseen el mismo tamaño"); // Mensaje de error
	}
	Tuple result(size); // Se genera un nuevo objeto con el constructor personalizado y que contiene un size de ceros
	for (size_t i =0; i < size; ++i){
		result.data[i] = data[i] - other.data[i]; // Mediante el ciclo se van reasignando las entradas de result, una a una, a partir de la resta
	}											  // de elementos individuales de los objetos originales
	return result;	// Se retorna el resultado de la resta de elementos 1 a 1
}

// MULTIPLICACION *
// Se sobrecarga al operador para multiplicar elemento a elemento entre dos tuples
Tuple Tuple::operator*(const Tuple &other) const {
	if (size != other.size){				// Verificación de tamaños
		throw std::invalid_argument("Los arreglos a operar no poseen el mismo tamaño"); // Mensaje de error
	}
	Tuple result(size); // Se genera un nuevo objeto con el constructor personalizado y que contiene un size de ceros
	for (size_t i =0; i < size; ++i){
		result.data[i] = data[i] * other.data[i]; // Mediante el ciclo se van reasignando las entradas de result, una a una, a partir de la multiplicación
	}											  // de elementos individuales de los objetos originales
	return result;	// Se retorna el resultado de la multiplicación de elementos 1 a 1
}

// Luego de los anteriores, la división es un caso espacial, dado que no se puede dividir entre cero, por lo que hay que condicionar la posibilidad de que
// alguno de los elementos del array divisor sea un cero

// DIVISION /
// Se sobrecarga al operador para dividir elemento a elemento entre dos tuples
Tuple Tuple::operator/(const Tuple &other) const {
	if (size != other.size){				// Verificación de tamaños
		throw std::invalid_argument("Los arreglos a operar no poseen el mismo tamaño"); // Mensaje de error
	}
	for (size_t i=0; i<size; ++i){ // Antes de crear cualquier objeto con los resultados, se verifica si el divisor es apto
		if (other.data[i] == 0.0){
			throw std::invalid_argument("El arreglo divisor contiene al menos un cero");
		}
	}
	Tuple result(size); // Se genera un nuevo objeto con el constructor personalizado y que contiene un size de ceros
	for (size_t i=0; i<size; ++i){
		result.data[i] = data[i] / other.data[i];
	}
	return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// METODOS

void Tuple::print() const { 		// Implementación del método para imprimir el array
	std::cout.precision(5);
	std::cout<<"[ ";
	for (size_t i =0; i<size; ++i){
		std::cout<< data[i] << " ";
	}
	std::cout<<" ]"<<std::endl;
}

size_t Tuple::get_size() const { 		// Implementación del método que devuelve la cantidad de elementos del array
	return size;						// Se retorna el tamaño del array
}

// Sobrecarga extra, es necesario asignar valores a los elementos de la tuple para ejemplificar correctamente los métodos

double &Tuple::operator[](size_t i) { // Implementación del método que contiene de forma NO CONST el elemento de un array según su índice
	if (i >= size) {				  // No exiten elemetos con índices mayores al rango
		throw std::out_of_range("Índice fuera del rango");
	}
	return data[i];
}

const double &Tuple::operator[](size_t i) const { // Implementación del método que contiene de forma NO CONST el elemento de un array según su índice

	if (i >= size) { 							  // No exiten elemetos con índices mayores al rango
		throw std::out_of_range("Índice fuera del rango");
	}
	return data[i];
}