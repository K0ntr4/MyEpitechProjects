/*
** EPITECH PROJECT, 2022
** B-PDG-300-BER-3-1-PDGRUSH3-josefine.mende
** File description:
** Monitor
*/

#ifndef IMONITOR_HPP_
#define IMONITOR_HPP_

#include "CPUModule.hpp"
#include "Date.hpp"
#include "NetworkModule.hpp"
#include "OSKernelModule.hpp"
#include "RAMModule.hpp"
#include "UsernameModule.hpp"

class IMonitor {
    public:
        IMonitor();
        ~IMonitor();

        void initialize();

        void updateModules();

        virtual int display(int windowY) { return 0; };

        CPUModule &getCPUModule();
        void setCPUModule();

        Date &getDateModule();
        void setDateModule();

        NetworkModule &getNetworkModule();
        void setNetworkModule();

        OSKernelModule &getOSKernelModule();
        void setOSKernelModule();

        RAMModule &getRAMModule();
        void setRAMModule();

        UsernameModule &getUsernameModule();
        void setUsernameModule();

    protected:
        CPUModule _cpuModule;
        Date _dateTimeModule;
        NetworkModule _networkModule;
        OSKernelModule _osKernelModule;
        RAMModule _ramModule;
        UsernameModule _usernameModule;
};

#endif /* !IMONITOR_HPP_ */
