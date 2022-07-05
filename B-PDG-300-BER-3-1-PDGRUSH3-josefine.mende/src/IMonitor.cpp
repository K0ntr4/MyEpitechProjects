/*
** EPITECH PROJECT, 2022
** B-PDG-300-BER-3-1-PDGRUSH3-josefine.mende
** File description:
** IMonitor
*/

#include "../include/IMonitor.hpp"

IMonitor::IMonitor()
{
}

IMonitor::~IMonitor()
{
}

void IMonitor::initialize()
{
    setCPUModule();
    setDateModule();
    setNetworkModule();
    setOSKernelModule();
    setRAMModule();
    setUsernameModule();
}

void IMonitor::updateModules()
{
    _cpuModule.updateData();
    _dateTimeModule.updateData();
    _networkModule.updateData();
    _osKernelModule.updateData();
    _ramModule.updateData();
    _usernameModule.updateData();
}

CPUModule &IMonitor::getCPUModule()
{
    return _cpuModule;
}

void IMonitor::setCPUModule()
{
    _cpuModule = CPUModule();
}

Date &IMonitor::getDateModule()
{
    return _dateTimeModule;
}

void IMonitor::setDateModule()
{
    _dateTimeModule = Date();
}

NetworkModule &IMonitor::getNetworkModule()
{
    return _networkModule;
}

void IMonitor::setNetworkModule()
{
    _networkModule = NetworkModule();
}

OSKernelModule &IMonitor::getOSKernelModule()
{
    return _osKernelModule;
}

void IMonitor::setOSKernelModule()
{
    _osKernelModule = OSKernelModule();
}

RAMModule &IMonitor::getRAMModule()
{
    return _ramModule;
}

void IMonitor::setRAMModule()
{
    _ramModule = RAMModule();
}

UsernameModule &IMonitor::getUsernameModule()
{
    return _usernameModule;
}

void IMonitor::setUsernameModule()
{
    _usernameModule = UsernameModule();
}
