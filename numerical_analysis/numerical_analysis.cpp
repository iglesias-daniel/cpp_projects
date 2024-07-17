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

        /* 
        Existen distintos criterios aplicables:
        - |fun_m - fun_m_anterior| < tol
        - |func(medio)| < tol
        - |fun_m - fun_m_anterior|/|fun_m| < tol
        */

        //Actualiza el intervalo
        if (fun_i*fun_m < 0){
            lim_sup = medio;
        } else {
            lim_inf = medio;
        }
    }
}

// Funcion para encontrar raiz por metodo de falsa posicion
double falsa_posicion(double (*func)(double), double lim_sup, double lim_inf, int n, double tol){
    int i = 0;
    double solucion = 0;
    double fun_i, fun_m, fun_s, x_F;

    //Aplicabilidad del metodo de falsa posicion
    if (func(lim_inf)*func(lim_sup) >= 0){
        LOG("Error: La multiplicacion de las imagenes de los intervalos es mayor o igual a 0.");
        return -1;
    } 
    LOG("La funcion es compatible con la biseccion.");

    //Metodo de falsa posicion
    while (true) {
        i++;

        fun_i = func(lim_inf);
        fun_s = func(lim_sup);
        
        x_F = lim_inf - fun_s * (lim_sup - lim_inf)/(fun_s-fun_i);
        
        fun_m = func(x_F);
        
        
        //Comprobar si se debe parar
        if (error_absoluto(fun_m,0) <= tol){
            LOG("Se obtuvo la tolerancia deseada");
            return x_F;
        }
        if (i == n) {
            LOG("Se alcanzo el numero de iteraciones maxima");
            return x_F;
        }

        /* 
        Existen distintos criterios aplicables:
        - |fun_m - fun_m_anterior| < tol
        - |func(medio)| < tol
        - |fun_m - fun_m_anterior|/|fun_m| < tol
        */

        //Actualiza el intervalo
        if (fun_i*fun_m < 0){
            lim_sup = x_F;
        } else {
            lim_inf = x_F;
        }
    }
}

// Funcion para encotnrar un punto fijo en una función con un unico punto fijo
double punto_fijo(double (*func)(double), double pun_inicial, int n, double tol){
   //Metodo de punto fijo
    double x_n = pun_inicial;
    double x_ant;
    int i = 0;
    
    while (true) {
        i++;
        x_ant = x_n;
        x_n = func(x_n);

        //Comprobar si se debe parar
        if (error_absoluto((x_n - x_ant),0) <= tol){
            LOG("Se obtuvo la tolerancia deseada");
            return x_n;
        }
        if (i == n) {
            LOG("Se alcanzo el numero de iteraciones maxima");
            return x_n;
        }
        
    } 

};


