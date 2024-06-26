#include <iostream>
#include "numerical_analysis.h"

int main() {
    std::cout << error_absoluto(105,100) << std::endl;
    std::cout << error_relativo(105,0,false) << std::endl;
    return 0;
}