#include <mpi.h>
#include <vector>
#include <iostream>

int main(int argc, char** argv) {

	// Inicializando el ambiente MPI
    int size, rank;
    MPI_Init(&argc, &argv);

    // Tamaño y rango
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Número total de procesos
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Identificador del proceso
    
    const int N = 1000; // Tamaño de los vectores

	// Se declaron los 4 vectores a utilizar
    std::vector<double> a, b, local_a, local_b; 
	// Se llenan los vectores a y b
    if (rank == 0) {
        // Inicio los vectores en el proceso 0
        a.resize(N); 
        b.resize(N);
        for (int i = 0; i < N; ++i) {
            a[i] = b[i] = i + 1; // a = [1,2,3,...] y b = [1,2,3,...]
        }
    }
    
	// Asignación local de memoria
    int nlocal = N / size; // Tamaño de los vectores locales
    local_a.resize(nlocal);
    local_b.resize(nlocal);
    
    // Distribución de secciones de los vectores a cada proceso
    MPI_Scatter(a.data(), nlocal, MPI_DOUBLE, local_a.data(), nlocal, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Scatter(b.data(), nlocal, MPI_DOUBLE, local_b.data(), nlocal, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    
    double local_dot = 0.0;
    // Calculando el producto punto local
    for (int i = 0; i < nlocal; ++i) {
        local_dot += local_a[i] * local_b[i];
    }
    
    double global_dot = 0.0;
    // Reduce los productos locales al proceso raíz para obtener el producto punto global
    MPI_Reduce(&local_dot, &global_dot, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    
    if (rank == 0) {
        // Imprimiendo en el proceso 0 el resultado
        std::cout << "a*b = : " << global_dot << std::endl;
    }
    
    // Cierro el entorno MPI
    MPI_Finalize();
    return 0;
}