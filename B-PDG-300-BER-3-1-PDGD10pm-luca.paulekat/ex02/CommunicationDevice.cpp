#include <iostream>
#include <stdexcept>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(std::istream &input, std::ostream &output) :
    _api(input, output)
{
}

CommunicationDevice::~CommunicationDevice()
{
}

void    CommunicationDevice::startMission(std::string const &missionName, std::string *users, size_t nbUsers)
{
    try {
        for (size_t i = 0; i < nbUsers; ++i)
            _api.addUser(users[i]);
        _api.startMission(missionName);
    } catch (std::logic_error const &err) {
        CommunicationError new_err ("LogicError: " + std::string(err.what()));
        throw new_err;
    } catch (std::exception const &err) {
        CommunicationError new_err ("Error: " + std::string(err.what()));
        throw new_err;
    } catch (std::runtime_error const &err) {
        CommunicationError new_err ("RuntimeError: " + std::string(err.what()));
        throw new_err;
    }
}

void    CommunicationDevice::send(std::string const &user, std::string const &message) const
{
    try {
        _api.sendMessage(user, message);
    } catch (std::exception const &error) {
        std::cerr << error.what() << std::endl;
    }
}

void    CommunicationDevice::receive(std::string const &user, std::string &message) const
{
    try {
        _api.receiveMessage(user, message);
    } catch (std::exception const &error) {
        std::cerr << error.what() << std::endl;
    }
}
