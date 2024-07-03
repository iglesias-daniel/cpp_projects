#define LOG_EN true
#include "numerical_analysis.h"
#include <stdio.h>


double funcion_matematica(double x){
    return x*x*x + 4*x*x - 10;
}

int main() {
    double resultado;
    double (*func)(double) = &funcion_matematica;
    resultado = biseccion(func,1,2,1000,0.001);
    printf("Solucion: %f\n", resultado);


    double aprox = 3.14;
    double real = 0;

    // Calculando y mostrando el error relativo
    double error_rel = error_relativo(aprox, real);
    printf("Error relativo: %f\n", error_rel);

    // Calculando y mostrando el error absoluto
    double error_abs = error_absoluto(aprox, real);
    printf("Error absoluto: %f\n", error_abs);
    return 0;
}

//g++ -o test.exe test.cpp numerical_analysis.c