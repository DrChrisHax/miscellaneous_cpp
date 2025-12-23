#include "Fraction.hpp"

#include <iostream>


int main(int argc, char* argv[]) {

    (void)argc;
    (void)argv;

    Fraction<int> f1 = {1, 5};
    
    //Fraction<int> f2 = (f1 * true);

    std::cout << to_string(f1) << std::endl;
    //std::cout << to_string(f2) << std::endl;
    
    return 0;
}