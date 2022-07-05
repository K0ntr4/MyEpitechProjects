//
// Created by Luca on 1/25/22.
//
#include <stdexcept>
#include <cassert>
#include "RefPtr.hpp"
#include "Oxygenator.hpp"

int main()
{
    try {
        RefPtr oxygenator = new Oxygenator;
        BaseComponent *raw = oxygenator.get();
        RefPtr other(raw);
        RefPtr useless;
        RefPtr lastOne;
        lastOne = other;
        assert(lastOne.get() == raw);
        (void)useless;
        throw std:: runtime_error("An error occured here!");
    }
    catch (...) { }
    return 0;
}
