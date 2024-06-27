#include <iostream>
#include "numerical_analysis.h"

double funcion_matematica(double x){
    return x*x*x + 4*x*x - 10;
}

int main() {

    double resultado;
    double (*func)(double) = &funcion_matematica;
    resultado = biseccion(func,1,2,true,0,0.001,false);
    std::cout << "Solucion: " << resultado;
    return 0;
}