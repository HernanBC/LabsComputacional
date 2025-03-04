// Elmer Hernán Barquero Chaves C10896
#include <iostream>
#include <mpi.h>

int main(int argc, char* argv[]) {
    // Inicialización del entorno MPI
    MPI_Init(&argc, &argv);

    // Variables para almacenar el identificador (rango) del proceso actual
    // y el número total de procesos en el comunicador
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Obtener el rango del proceso actual
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Obtener el número total de procesos

    // Se define una variable buffer en cada proceso para almacenar un valor entero
    int buffer;
    buffer = rank; // Se inicializa el buffer con el valor del rango del proceso

    // Inicio del bucle para la comunicación circular.
    // Se realizarán "size" iteraciones para asegurar que el mensaje pase por todos los procesos.
    for (int i = 0; i < size; ++i) {
        // Variable auxiliar para almacenar el valor a enviar
        int send_rank = buffer;

        // Caso especial: Si el proceso es el último (rank = size - 1), debe enviar su valor al primer proceso (rank = 0)
        if (rank == size - 1) {
            MPI_Send(&send_rank, 1, MPI_INT, 0, 0, MPI_COMM_WORLD); // Envío bloqueante al proceso 0
            MPI_Recv(&buffer, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); // Recepción bloqueante desde el proceso anterior (rank - 1)
        } else {
            // Para todos los demás procesos (rank < size - 1):
            // 1. Se envía el valor actual al siguiente proceso (rank + 1)
            MPI_Send(&send_rank, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD); // Envío bloqueante |||| Se hace primero esto para no perder el valor de rank
            // 2. Se recibe el valor desde el proceso anterior (rank - 1)
            MPI_Recv(&buffer, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); // Recepción bloqueante|||| Una vez movido el valor de rank al rank +1, no hay problema en recibir el valor de rank -1
        }

        // En cada iteración, el proceso 0 imprime el contenido de su buffer
        if (rank == 0) {
            std::cout << "Iteración " << i << " --> Proceso 0 ----> Buffer: " << buffer << std::endl;
        }
    }

    // Después de recorrer todo el círculo (size iteraciones), el rank 0 (proceso 0) imprime su valor final en el buffer.
    if (rank == 0) {
        std::cout << "ÚLTIMA ITERACIÓN: Proceso 0 ----> Buffer: " << buffer << std::endl;
    }

    // Finalización del entorno MPI
    MPI_Finalize();
    return 0;
}