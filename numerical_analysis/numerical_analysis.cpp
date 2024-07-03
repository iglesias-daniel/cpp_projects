#include "numerical_analysis.h"

// Funcion que obtiene el error relativo.
double error_relativo(double aprox,double real){
    double e_relativo;
    
    if (real != 0) {
        e_relativo = (aprox - real)/(real); // Calculo de error relativo
        if (e_relativo < 0) e_relativo = -e_relativo; // Calculo de valor absoluto
    } else {
        LOG("Error: División por cero.");
        e_relativo = -1;
    }
    
    return e_relativo;
}

// Funcion para obtener el error absoluto.
double error_absoluto(double aprox, double real){
    double e_absoluto;
    
    e_absoluto = real - aprox; // Calculo de error absoluto
    if (e_absoluto < 0) e_absoluto = -e_absoluto; // Calculo de valor absoluto
    
    return e_absoluto;
}

// Funcion para encontrar raiz por metodo de biseccion
double biseccion(double (*func)(double), double lim_sup, double lim_inf, int n, double tol){
    int i = 0;
    double solucion = 0;
    double fun_i, fun_m, fun_s, medio;

    //Aplicabilidad del metodo de biseccion
    if (func(lim_inf)*func(lim_sup) >= 0){
        LOG("Error: La multiplicacion de las imagenes de los intervalos es mayor o igual a 0.");
        return -1;
    } 
    LOG("La funcion es compatible con la biseccion.");

    //Metodo de la biseccion
    while (true) {
        i++;
        
        medio = (lim_sup + lim_inf)/2;
        fun_i = func(lim_inf);
        fun_m = func(medio);
        fun_s = func(lim_sup);
        
        //Comprobar si se debe parar
        if (error_absoluto(fun_m,0) <= tol){
            LOG("Se obtuvo la tolerancia deseada");
            return medio;
        }
        if (i == n) {
            LOG("Se alcanzo el numero de iteraciones maxima");
            return medio;
        }
        
        //Actualiza el intervalo
        if (fun_i*fun_m < 0){
            lim_sup = medio;
        } else {
            lim_inf = medio;
        }
    }
}
