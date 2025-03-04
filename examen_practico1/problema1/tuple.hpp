#ifndef TUPLE_HPP // Queremos evitar que el archivo sea incluido más de una vez a la hora de compilar
#define TUPLE_HPP // por eso usamos este "include guard" para evitar errores de multiples inclusiones

#include <stdexcept> // Para realizar el manejo de excepciones

class Tuple { 			// Defino una clase con el nombre de Tuple
	private:			// La clase tiene la data y la cantidad de valores guardados como atributo de clase y son privados.No es posible acceder a estos con métodos externos a la clase
		double *data; 	// Puntero que contiene la ubicación de los objetos en memoria
		size_t size;		// Tamaño del array tupla
	public:
		// Constructores
		Tuple(); // Declaro constructor por defecto de la clase, si se crea un objeto de clase Tuple (0.0)
		Tuple(size_t size); // Declaro el constructor personalizada para asignar una tupla con un size de ceros dentro
		Tuple(const Tuple &other); // Declaro el constructor copia

		// Destructor
		~Tuple(); // Declaro el destructor de la clase

		// Operador asignación
		Tuple &operator=(const Tuple &other);

		// Sobrecarga +
		Tuple operator+(const Tuple &other) const;

		// Sobrecarga -
		Tuple operator-(const Tuple &other) const;

		// Sobrecarga *
		Tuple operator*(const Tuple &other) const;

		// Sobrecarga /
		Tuple operator/(const Tuple &other) const;

		//Métodos
		void print() const; // Declaración de un método de la clase para observar la tuple, el parametro "const" hace que no modifique atributos de la clase
		size_t get_size() const; // Declaración de un método de la clase para observar el tamaño de la tuple	
		double &operator[](size_t i); // Declaración de un método para alterar el valor de un elemento en el array
		const double &operator[](size_t i) const; //Declaración de un método para obtener el valor de un elemento sin alterarlo
		
}; // Las clases sí requieren de cerrar la llave con un ;
#endif