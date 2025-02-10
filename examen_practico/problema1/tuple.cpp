#include <iostream>
#include <cstring> 	// Incluyo biblioteca para usar memcpy
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
	std::memcpy(data, other.data, size*sizeof(double));	// La copia superficial se realiza mediante std::memcpy que es una función que copia un bloque de memoria de un lugar a otro
}														// La combinación de las líneas anteriores da como resultado una deep copy del objeto original

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DESTRUCTOR

Tuple::~Tuple(){
	delete[] data; // Libera la memoria existente
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OPERADOR ASIGNACION
Tuple &Tuple::operator=(const Tuple &other){  // Sobrecarga del operador asignación
	if (this != &other){ 			  // Es necesario verificar que no estamos asignando un objeto así mismo
		delete[] data;
		size = other.size;
		data = new double[size];
		std::memcpy(data, other.data, size*sizeof(double));
		}
		return *this;
		}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOBRECARGA DE OPERADORES ARITMETICOS

// Para realizar las operaciones aritméticas, los objetos deben tener el mismo tamaño, por lo que esta será una restricción que se encontrará en todas las
// sobrecargas

// SUMA +
Tuple Tuple::operator+(const Tuple &other) const {
	try {
		if (size != other.size){				// Verificación de tamaños
			throw std::invalid_argument("Los arreglos a operar no poseen el mismo tamaño"); // Mensaje de error
		}
		Tuple result(size); // Se genera un nuevo objeto con el constructor personalizado y que contiene un size de ceros
		for (size_t i =0; i < size; ++i){
			result.data[i] = data[i] + other.data[i]; // Mediante el ciclo se van reasignando las entradas de result, una a una, a partir de la suma
		}											  // de elementos individuales de los objetos originales
		return result;	// Se retorna el resultado de la suma de elementos 1 a 1
	}
	catch (const std::invalid_argument &e){
		std::cout<<"ERROR: "<< e.what()<<std::endl;
		return Tuple();								// Devuelve un objeto Tuple con el constructor por defecto
	}
}

// RESTA -
Tuple Tuple::operator-(const Tuple &other) const {
	try {
		if (size != other.size){				// Verificación de tamaños
			throw std::invalid_argument("Los arreglos a operar no poseen el mismo tamaño"); // Mensaje de error
		}
		Tuple result(size); // Se genera un nuevo objeto con el constructor personalizado y que contiene un size de ceros
		for (size_t i =0; i < size; ++i){
			result.data[i] = data[i] - other.data[i]; // Mediante el ciclo se van reasignando las entradas de result, una a una, a partir de la resta
		}											  // de elementos individuales de los objetos originales
		return result;	// Se retorna el resultado de la resta de elementos 1 a 1
	}
	catch (const std::invalid_argument &e){
		std::cout<<"ERROR: "<< e.what()<<std::endl;
		return Tuple();								// Devuelve un objeto Tuple con el constructor por defecto
	}
}

// MULTIPLICACION *
Tuple Tuple::operator*(const Tuple &other) const {
	try {
		if (size != other.size){				// Verificación de tamaños
			throw std::invalid_argument("Los arreglos a operar no poseen el mismo tamaño"); // Mensaje de error
		}
		Tuple result(size); // Se genera un nuevo objeto con el constructor personalizado y que contiene un size de ceros
		for (size_t i =0; i < size; ++i){
			result.data[i] = data[i] * other.data[i]; // Mediante el ciclo se van reasignando las entradas de result, una a una, a partir de la multiplicación
		}											  // de elementos individuales de los objetos originales
		return result;	// Se retorna el resultado de la multiplicación de elementos 1 a 1
	}
	catch (const std::invalid_argument &e){
		std::cout<<"ERROR: "<< e.what()<<std::endl;
		return Tuple();								// Devuelve un objeto Tuple con el constructor por defecto
	}
}

// Luego de los anteriores, la división es un caso espacial, dado que no se puede dividir entre cero, por lo que hay que condicionar la posibilidad de que
// alguno de los elementos del array divisor sea un cero

// DIVISION /
Tuple Tuple::operator/(const Tuple &other) const {
	try{
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
	catch (const std::invalid_argument &e){
		std::cout<<"ERROR: "<< e.what()<<std::endl;
		return Tuple();								// Devuelve un objeto Tuple con el constructor por defecto
	}
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

double &Tuple::operator[](size_t i) { // Implementación del método que contiene de forma NO CONST el elemento de un array según su índice
	try {
		if (i >= size) {				  // No exiten elemetos con índices mayores al rango
			throw std::out_of_range("Índice fuera del rango");
		}
		return data[i];
	}
	catch (const std::out_of_range &e) {
		std::cout<<"ERROR: "<< e.what() << std::endl;
		static double invalid_value = 0.0;		// Se requiere declarar 0.0 como static para que obtenga una dirección de memoria
		return invalid_value;
	}
}

const double &Tuple::operator[](size_t i) const { // Implementación del método que contiene de forma NO CONST el elemento de un array según su índice
	try{
		if (i >= size) { 							  // No exiten elemetos con índices mayores al rango
			throw std::out_of_range("Índice fuera del rango");
		}
		return data[i];
	}
	catch (const std::out_of_range &e) {
		std::cout<<"ERROR: "<< e.what() << std::endl;
		static double invalid_value = 0.0;			// Se requiere declarar 0.0 como static para que obtenga una dirección de memoria
		return invalid_value;
	}
}