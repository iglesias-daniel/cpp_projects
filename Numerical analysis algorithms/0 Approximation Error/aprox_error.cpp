#include <stdio.h>

int main() {
    float aprox, ref; // Aproximación y valor real
    float e_rel, e_abs; // Error relativo y absoluto
    bool error = false; // Flag de valor real = 0

    printf("Ingresa la aproximacion: ");
    scanf("%f", &aprox);
    printf("Ingresa el valor real: ");
    scanf("%f", &ref);

    if (ref != 0) {
        e_rel = (aprox - ref)/(ref); // Calculo error relativo
    } else {
        printf("No se puede dividir por 0.\n");
        e_rel = 0;
        error = true;
    }

    e_abs = aprox - ref; // Calculo error absoluto

    if (error) {
        printf("Error relativo: Indeterminado");
    } else {
        printf("Error relativo: %f", e_rel);
    }

    printf("\nError absoluto: %f", e_abs);

    return 0;
}