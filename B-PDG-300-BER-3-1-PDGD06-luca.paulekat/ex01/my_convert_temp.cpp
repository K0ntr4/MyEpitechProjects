#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

int main(){
    double input1;
    std::string input2;
    double output;
    std::string output2;

    std::cin >> input1;
    std::cin >> input2;
    if (input2 == "Celsius") {
        output = input1 / (5.0 / 9.0) + 32;
        output2 = "Fahrenheit";
    } else if (input2 == "Fahrenheit") {
        output = 5.0 / 9.0 * ( input1 - 32 );
        output2 = "Celsius";
    } else {
        std::cerr << "invalid input: " << input2 << std::endl;
    }
    std::cout << std::setw(16) << std::setprecision(3) << std::fixed << output << std::setw(16) << output2 << std::endl;
}