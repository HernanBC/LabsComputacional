#include <iostream>
#include <complex>
#include <vector>

// Función para determinar si un número c está fuera o dentro del conjunto
// de Maldenbrot con la cantidad de iteraciones máximas
int mandelbrot(const std::complex<double> &c, const int &maxits){
  std::complex<double> z = 0;
  int n = 0;
  while(abs(z) <= 2 && n < maxits){
    z = z * z + c;
    ++n;
  }
    
  return n;
}

int main(){

  // Ancho y alto de la salida del programa
  int width = 150;
  int height = 45;
  // Número máximo de iteraciones (corte)
  int max_iter = 1000;
  // Coordenadas en el plano complejo máximas y mínimas
  double minX = -2.0, maxX = 1.0;
  double minY = -1.0, maxY = 1.0;

  std::vector<std::vector<char>> grap(height, std::vector<char>(width)); // <------- Cambio para paralelización: vector de vectores para crear una grilla con los resultados


  // Rutina principal para generar e imprimir el conjunto
  #pragma omp parallel for// <------- Cambio para paralelización: Se hace la paralelización 
  for(int y = 0; y < height; ++y){
      for(int x = 0; x < width; ++x){
        // Mapeo de pixeles a número complejo
        std::complex<double> c( minX + (maxX - minX) * x / width,
                                minY + (maxY - minY) * y / height );
  
        // Cálculo del número de iteraciones
        int n = mandelbrot(c, max_iter);
  
        // Se guardan los resultados en los puntos discretizados de una malla que simboliza el espacio de la grafica
        if(n == max_iter){
          grap[y][x] = '#';
        } else{
          grap[y][x] = '.';
        }
      }
    }
  // Se imprime el resultado correspondiente de la malla
  for(int y = 0; y < height; ++y){
    for(int x = 0; x < width; ++x){
      std::cout << grap[y][x];
    }
    std::cout << std::endl;
  }

  return 0;
}
