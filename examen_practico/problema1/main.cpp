#include "tuple.hpp"
#include <iostream>

int main(){
	Complex c1(3,4.5); // Creo un objeto de la clase Complex bajo la variable c1
	std::cout<<"c1 ="<<std::endl;
	c1.print(); // Uso el método print de la clase para mostrar el número complejo

	Complex c2; // Segundo objeto de Complex, probando el constructor por defecto. No se usa parentesis para dejar claro que estoy llamando al constructor y que
	std::cout<<"c2 ="<<std::endl;
	c2.print(); // C++ comprenda que estoy haciendo eso y no haciendo un llamado a una función c2(). Otra forma de escribirlo puede ser: Complex c2 = Complex()

	Complex c3(1,0.5);
	std::cout<<"c3 ="<<std::endl;
	c3.print();

	/////////////////////////////////////
	// Prueba de Metodos
	std::cout<<"Probando los métodos de la clase Complex"<<std::endl;

	std::cout<<"CONJUGADO COMPLEJO"<<std::endl;
	std::cout<<"Numero origianl"<<std::endl;
	c1.print();
	std::cout<<"Conjugado"<<std::endl;
	std::cout<<"c4 ="<<std::endl;
	Complex c4 = c1.conjugado();
	c4.print();

	std::cout<<"Norma del número"<<std::endl;
	std::cout<<"La norma de c1 es: "<< c1.norma() <<std::endl;

	////////////////////////////////////
	// Prueba de Operaciones Aritméticas
	std::cout<<"Sumando c1 y c4"<<std::endl;
	Complex c5 = c1 + c4;
	std::cout<<"c5 ="<<std::endl;
	c5.print();

	std::cout<<"Restando c5 y c4"<<std::endl;
	Complex c6 = c5 - c4;
	std::cout<<"c6 ="<<std::endl;
	c6.print();

	std::cout<<"Multiplicando c3 y c4"<<std::endl;
	std::cout<<"c7 ="<<std::endl;
	Complex c7 = c3 * c4;
	c7.print();

	std::cout<<"Dividiendo c1 y c3"<<std::endl;
	Complex c8 = c1 / c3;
	std::cout<<"c8 ="<<std::endl;
	c8.print();

	return 0;
}