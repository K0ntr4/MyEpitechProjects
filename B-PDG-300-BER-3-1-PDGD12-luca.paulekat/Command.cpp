//
// Created by Luca on 1/27/22.
//

#include "Command.hpp"

void Command::registerCommand(const std::string &name, const std::function<void()> &function) {
    if (this->m.count(name) != 0)
        throw Error ("Already registered command");
    this->m[name] = function;
}

void Command::executeCommand(const std::string &name) {
    if (this->m.count(name) == 0)
        throw Error ("Unknow command");
    std::function func = this->m[name];
    func();
}

Command::Error::Error(const std::string &message) {
    this->_message = message;
}
