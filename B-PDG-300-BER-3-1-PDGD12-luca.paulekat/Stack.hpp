//
// Created by Luca on 1/27/22.
//

#ifndef B_PDG_300_BER_3_1_PDGD12_LUCA_PAULEKAT_STACK_HPP
#define B_PDG_300_BER_3_1_PDGD12_LUCA_PAULEKAT_STACK_HPP

#include <stack>
#include <stdexcept>

class Stack {
private:
    std::stack<double> stack;
public:
    class Error : public std::exception {
        private:
            std::string _message;
        public:
            explicit Error(std::string const &message);
            [[nodiscard]] const char * what() const noexcept { return _message.c_str(); };
    };
    void push (double value);
    double pop();
    [[nodiscard]] double top() const;
    void add();
    void sub();
    void mul();
    void div();
};

#endif //B_PDG_300_BER_3_1_PDGD12_LUCA_PAULEKAT_STACK_HPP
