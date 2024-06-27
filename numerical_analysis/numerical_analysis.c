#include "numerical_analysis.h"
#include <stdio>

#ifdef LOG_EN
    #define LOG(message) printf("Log: %s\n", message)
#else
    #define LOG(message)
#endif

// Funcion que obtiene el error relativo.
double error_relativo(double aprox,double real){
    double e_relativo;
    
    if (real != 0) {
        e_rel = (aprox - real)/(real); // Calculo de error relativo
        if (e_rel < 0) e_rel = -e_rel; // Calculo de valor absoluto
    } else {
        LOG("Error: División por cero.");
        e_rel = -1;
    }
    
    return e_rel;
}

// Funcion para obtener el error absoluto.
double error_absoluto(double aprox, double real){
    double e_abs;
    
    e_abs = real - aprox; // Calculo de error absoluto
    if (e_abs < 0) e_abs = -e_abs; // Calculo de valor absoluto
    
    return e_abs;
}

// Funcion para encontrar raiz por metodo de biseccion
double biseccion(double (*func)(double), double lim_sup, double lim_inf, int n, double tol){
    int i = 0;
    double solucion = 0;
    double fun_i, fun_m, fun_s, medio;

    //Aplicabilidad del metodo de biseccion
    if (func(lim_inf)*func(lim_sup) >= 0){
        LOG("Error: La multiplicacion de las imagenes de los intervalos es mayor o igual a 0.");
        return solucion = -1;
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
            return solucion = medio;
        }
        if (i == n) {
            LOG("Se alcanzo el numero de iteraciones maxima");
            return solucion = medio;
        }
        
        //Actualiza el intervalo
        if (fun_i*fun_m < 0){
            lim_sup = medio;
        } else {
            lim_inf = medio;
        }
    }
}
