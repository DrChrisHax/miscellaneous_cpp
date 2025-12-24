#include "Fraction.hpp"

#include <iostream>

int main(int argc, char* argv[]) {

    (void)argc;
    (void)argv;

    
    std::istringstream iss("7");
    Fraction<int> f;
    iss >> f;
    
    std::string expected = "7";
    std::string result = to_string(f);
    
    std::cout << expected << std::endl;
    std::cout << result << std::endl;




    return 0;
}