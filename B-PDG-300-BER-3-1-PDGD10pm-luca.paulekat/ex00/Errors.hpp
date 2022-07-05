#pragma once

#include <string>

class NasaError : public std::exception
{
    private:
        std::string _message;
        std::string _component;

    public:
    NasaError(std::string const &message, std::string const &component = "Unknown");
    std::string const &getComponent() const;
    const char * what() const noexcept override {return _message.c_str(); };
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message, std::string const &component = "Unknown") : NasaError (message,
                                                                                                    component) {} ;
};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message, std::string const &component = "Unknown") : NasaError (message,
                                                                                                             component)
        {} ;
};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message, std::string const &component = "Unknown") : NasaError (message, component ) {} ;
};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message) : NasaError (message, "CommunicationDevice") {};
};
