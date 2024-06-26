//#include "numerical_analysis.c"

#ifndef NUMERICAL_ANALYSIS_H // Verifica que la biblioteca no se haya incluido anteriormente
#define NUMERICAL_ANALYSIS_H // Lo crea para que este incluido

double error_relativo(double aprox, double real, bool log);
double error_absoluto(double aprox, double real);

#endif