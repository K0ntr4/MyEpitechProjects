//
// Created by Luca on 1/27/22.
//

#include "Stack.hpp"

void Stack::push(double value) {
    this->stack.push(value);
}

double Stack::pop() {
    if (this->stack.empty())
        throw Error("Empty stack");
    auto top = double(this->stack.top());
    this->stack.pop();
    return top;
}

double Stack::top() const {
    if (this->stack.empty())
        throw Error("Empty stack");
    return this->stack.top();
}

void Stack::add() {
    if (this->stack.size() < 2)
        throw Error("Not enough operands");
    double one = this->pop();
    double two = this->pop();
    this->push(one + two);
}

void Stack::sub() {
    if (this->stack.size() < 2)
        throw Error("Not enough operands");
    double one = this->pop();
    double two = this->pop();
    this->push(one - two);

}

void Stack::mul() {
    if (this->stack.size() < 2)
        throw Error("Not enough operands");
    double one = this->pop();
    double two = this->pop();
    this->push(one * two);
}

void Stack::div() {

    if (this->stack.size() < 2)
        throw Error("Not enough operands");
    double one = this->pop();
    double two = this->pop();
    if (two == 0) {
        this->push(two);
        this->push(one);
        throw std::logic_error ("Division by zero");
    }
    this->push(one / two);
}

Stack::Error::Error(const std::string &message) {
    this->_message = message;
}
