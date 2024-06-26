#include "numerical_analysis.h"
#include <iostream>

// Funcion que obtiene el error relativo. 'log = true' para mostrar detalles de la ejecucion.
double error_relativo(double aprox,double real,bool log){
    double e_rel;
    if (real != 0) {
        e_rel = (aprox - real)/(real); // Calculo error relativo

        if (e_rel < 0) {
            e_rel = -e_rel;
        }

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

    e_abs = real - aprox;

    if (e_abs < 0) {
        e_abs = -e_abs;
    }

    return e_abs;
}

// Funcion busqueda por biseccion
// La funcion debe ser continua, y la multiplicacion de la imagen en los limites debe ser negativa.
// Usar 'n_stop = true' para que se detenga en n iteraciones, usar 'n_stop =false' para usar el error
// relativo como señal de parada. La función debe estar punteada: double (*func)() = &funcion;
double biseccion(double (*func)(double), double lim_sup, double lim_inf, bool log, int n, double e_rel, bool n_stop){

    bool keep = true;
    int i = 0;
    double solucion = 0;
    double fun_i, fun_m, fun_s, medio;

    //Comprobacion de biseccion y soluciones
    if (func(lim_inf)*func(lim_sup) > 0){

        if (log) std::cout << "La multiplicacion de las imagenes de los intervalos es mayor a 0. No se puede aplicar biseccion.\n Se asigno solucion = -1.";
        
        return solucion = -1;

    } else {

        if (func(lim_inf) == 0 || func(lim_sup) == 0){

            if (log) std::cout << "Un limite es la solucion\n";

            if (func(lim_inf) == 0){
                return solucion = lim_inf;
            } else {
                return solucion = lim_sup;
            }

        }
    }

    if (log) std::cout << "La funcion es compatible con la biseccion.\n";


    //Ejecucion iterativa
    while (keep) {
        
        i++;

        medio = (lim_sup + lim_inf)/2;

        fun_i = func(lim_inf);
        fun_m = func(medio);
        fun_s = func(lim_sup);

        if (log) std::cout << "Resultado del medio: "<<fun_m<<"\n";
        
        //Comprobar si se debe parar
        if (n_stop) {
            if (i == n) {
                return solucion = medio;
            }
        } else {
            if (error_absoluto(fun_m,0) <= e_rel){
                return solucion = medio;
            }
        }

        //Actualiza el intervalo
        if (fun_i*fun_m < 0){
            lim_sup = medio;
        } else {
            lim_inf = medio;
        }
    }

    return solucion;

}