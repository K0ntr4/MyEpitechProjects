//
// Created by Luca on 1/27/22.
//

#ifndef B_PDG_300_BER_3_1_PDGD12_LUCA_PAULEKAT_COMMAND_HPP
#define B_PDG_300_BER_3_1_PDGD12_LUCA_PAULEKAT_COMMAND_HPP

#include <string>
#include <functional>
#include <map>

class Command {
private:
    std::map<std::string, std::function<void()>> m;
public:
    class Error : public std::exception {
    private:
        std::string _message;
    public:
        explicit Error(std::string const &message);
        [[nodiscard]] const char * what() const noexcept { return _message.c_str(); };
    };
    void registerCommand (const std::string &name, const std::function<void()> &function);
    void executeCommand (const std::string &name);
};

#endif //B_PDG_300_BER_3_1_PDGD12_LUCA_PAULEKAT_COMMAND_HPP
