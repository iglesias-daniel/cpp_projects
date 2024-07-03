#ifndef NUMERICAL_ANALYSIS_H // Verifica que la biblioteca no se haya incluido anteriormente
#define NUMERICAL_ANALYSIS_H // Lo crea para que este incluido

#ifdef LOG_EN
    #include <stdio.h>
    #define LOG(message) printf("Log: %s\n", message)
#else
    #define LOG(message)
#endif

double error_relativo(double aprox, double real);
double error_absoluto(double aprox, double real);
double biseccion(double (*func)(double), double lim_sup, double lim_inf, int n, double tol);

#endif