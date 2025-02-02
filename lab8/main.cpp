#include "complex.hpp"





int main(){
	Complex c1(3,4.5); // Creo un objeto de la clase Complex bajo la variable c1
	c1.print(); // Uso el método print de la clase para mostrar el número complejo

	Complex c2; // Segundo objeto de Complex, probando el constructor por defecto. No se usa parentesis para dejar claro que estoy llamando al constructor y que
	c2.print(); // C++ comprenda que estoy haciendo eso y no haciendo un llamado a una función c2(). Otra forma de escribirlo puede ser: Complex c2 = Complex()


	return 0;
}