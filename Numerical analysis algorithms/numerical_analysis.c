#include "numerical_analysis.h"
#include <iostream>

// Funcion que obtiene el error relativo. 'log = true' para mostrar detalles de la ejecucion.
double error_relativo(double aprox,double real,bool log){
    double e_rel;
    if (real != 0) {
        e_rel = (aprox - real)/(real); // Calculo error relativo
    } else {
        if (log) {
            std::cout << "Error: División por cero.\nAsignando -1 como salida.\n";
        }
        e_rel = -1;
    }
    return e_rel;
}

// Funcion para obtener el error absoluto.
double error_absoluto(double aprox, double real){
    double e_abs;
    return e_abs = aprox - real;
}

// Funcion