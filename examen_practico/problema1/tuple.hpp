#ifndef TUPLE_HPP // Queremos evitar que el archivo sea incluido más de una vez a la hora de compilar
#define TUPLE_HPP // por eso usamos este "include guard" para evitar errores de multiples inclusiones

class Complex { 			// Defino una clase con el nombre de Complex
	private:				// La clase tiene la parte real e imaginaria del numero complejo como atributo de clase y son privados
		double real; 		// No es posible acceder a real e imaginario con metodos/funciones externas a la clase Complex
		double imaginario;
	public:
		// Constructores
		Complex(); // Declaro constructor por defecto de la clase, si se crea un objeto de clase Complex sin elementos sera 0 +i*0
		Complex(double real, double imaginario); // Declaro el constructor personalizada para asignar valores específicos a la parte real e imaginaria
		Complex(const Complex &other); // Declaro el constructor copia

		// Destructor
		~Complex(); // Declaro el destructor de la clase, notese que no hay uso de memoria dinámica

		// Operador asignación
		Complex &operator=(const Complex &other);

		// Sobrecarga +
		Complex operator+(const Complex &other) const;

		// Sobrecarga -
		Complex operator-(const Complex &other) const;

		// Sobrecarga *
		Complex operator*(const Complex &other) const;

		// Sobrecarga /
		Complex operator/(const Complex &other) const;

		//Métodos
		void print() const; // Declaración de un método de la clase para observar el número complejo, el parametro "const" hace que no modifique atributos de la clase
		double norma() const; //Declaración de un método para obtener el valor de la norma de un número complejo
		Complex conjugado() const; // Declaración de un método para obtener el conjugado complejo de un número complejo

}; // Las clases sí requieren de cerrar la llave con un ;

#endif