#include "WarpSystem.hpp"

bool WarpSystem::QuantumReactor::isStable () {
    return this->_stability;
}

void WarpSystem::QuantumReactor::setStability(bool stability){
    this->_stability = stability;
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *coreReactor) {
    this->_coreReactor = coreReactor;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor() {
    return this->_coreReactor;
}