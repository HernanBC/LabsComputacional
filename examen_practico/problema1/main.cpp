#include "tuple.hpp"
#include <iostream>

int main(){
	Tuple c1(5); // Creo un objeto de la clase Tuple bajo la variable c1
	std::cout<<"c1 ="<<std::endl;
	c1.print(); // Uso el método print de la clase para mostrar la tupla

	Tuple c2; // Segundo objeto de Tuple, probando el constructor por defecto. No se usa parentesis para dejar claro que estoy llamando al constructor y que
	std::cout<<"\n"<<"c2 ="<<std::endl;
	c2.print(); // C++ comprenda que estoy haciendo eso y no haciendo un llamado a una función c2(). Otra forma de escribirlo puede ser: Tuple c2 = Tuple()

	Tuple c3(4);
	std::cout<<"\n"<<"c3 ="<<std::endl;
	c3.print();


	Tuple c4(4);
	std::cout<<"\n"<<"c4 ="<<std::endl;
	c4.print();
	

	/////////////////////////////////////
	// Prueba de Metodos
	std::cout<<"\n"<<"Probando los métodos de la clase Tuple"<<std::endl;

	std::cout<<"\n"<<"En la sección anterior se crearon c3 y c4 como arrays que contienen ceros, usemos el método [] para cambiar los valores de las tuples"<<std::endl;
	c3[0] = 0.0;
	c3[1] = 1.0;
	c3[2] = 2.0;
	c3[3] = 3.0;
	std::cout<<"\n"<<"Cambiamos las entradas de c3"<<std::endl;
	std::cout<<"c3 ="<<std::endl;
	c3.print();

	c4[0] = 0.0;
	c4[1] = 1.0;
	c4[2] = 2.0;
	c4[3] = 3.0;
	std::cout<<"\n"<<"Cambiamos las entradas de c4"<<std::endl;
	std::cout<<"c4 ="<<std::endl;
	c4.print();

	std::cout<<"\n"<<"Ahora observemos una entrada específica"<<std::endl;
	std::cout<<"\n"<<"c3[2] = "<<c3[2]<<std::endl;

	std::cout<<"\n"<<"El número de elementos que contiene la tupla"<<std::endl;
	std::cout<<"\n"<<"c3.get_size() = "<<c3.get_size() <<std::endl;

	////////////////////////////////////
	// Prueba de Operaciones Aritméticas
	std::cout<<"\n"<<"Operaciones Aritméticas"<<"\n"<<std::endl;

	std::cout<<"Sumando c3 y c4"<<std::endl;
	Tuple c5 = c3 + c4;
	std::cout<<"c5 ="<<std::endl;
	c5.print();

	std::cout<<"\n"<<"Restando c3 y c4"<<std::endl;
	Tuple c6 = c3 - c4;
	std::cout<<"c6 ="<<std::endl;
	c6.print();

	std::cout<<"\n"<<"Multiplicando c3 y c4"<<std::endl;
	std::cout<<"c7 ="<<std::endl;
	Tuple c7 = c3 * c4;
	c7.print();

	std::cout<<"\n"<<"Dividiendo c4 y c3"<<std::endl;
	Tuple c8 = c4 / c3;
	std::cout<<"c8 ="<<std::endl;
	c8.print();
	
	// Ahora sin que la división dé error
	std::cout<<"\n"<<"Cambiamos el primer elemento de c3, de cero a uno"<<std::endl;
	c3[0] = 1.0;
	std::cout<<"Tratamos de hacer la división nuevamente"<<std::endl;
	Tuple c9 = c4 / c3;
	std::cout<<"c9 ="<<std::endl;
	c9.print();
	return 0;
}