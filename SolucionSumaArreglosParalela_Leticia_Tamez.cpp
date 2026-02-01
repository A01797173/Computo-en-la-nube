// Programación de una solución paralela.cpp. Suma de los dos arreglos A Y B//

#include <iostream>
#include <vector>
#include <omp.h>    // Librería obligatoria para OpenMP
#include <cstdlib>  // Para números aleatorios
#include <ctime>    // Para la semilla de aleatoriedad

#define N 1000  // Cantidad de elementos en cada arreglo A y B

int main() {
    // Inicializar semilla de aleatoriedad
    std::srand(std::time(0));

    // Crear los arreglos (Vectores en C++)
    std::vector<int> A(N);
    std::vector<int> B(N);
    std::vector<int> R(N);

    // Se Asignan los valores aleatorios
    std::cout << "Generando " << N << " valores aleatorios...\n";
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100; // Solo se asignan némeros entre 0 y 99 para el arreglo A
        B[i] = rand() % 100; // Solo se asignan némeros entre 0 y 99 para el arreglo B
    }

    // Se Realiza uel FOR paralelo usando OpenMP
    std::cout << "Realizando suma en paralelo con OpenMP...\n";

    // Se divide el trabajo entre los núcleos del CPU
#pragma omp parallel for
    for (int i = 0; i < N; i++) {
        R[i] = A[i] + B[i];
    }

    // Validación: Se imprimen solo los 10 primeros arreglos
    std::cout << "\n--- Resultados parciales (Primeros 10) ---\n";
    std::cout << "Indice\tA\t+\tB\t=\tR\n";
    std::cout << "------------------------------------------\n";
    for (int i = 0; i < 10; i++) {
        std::cout << i << "\t" << A[i] << "\t+\t" << B[i] << "\t=\t" << R[i] << "\n";
    }

    std::cout << "\nProceso terminado exitosamente.\n";
    return 0;
}
