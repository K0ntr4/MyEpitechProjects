#include "KoalaNurse.hpp"

void KoalaNurse::timeCheck() {
    if (working == 0) {
        std::cout << "Nurse " << ID << ": Time to get to work!" << std::endl;
        working = 1;
    } else if (working == 1) {
        std::cout << "Nurse " << ID << ": Time to go home to my eucalyptus forest!" << std::endl;
    } else {
        ;
    }
}

void KoalaNurse::giveDrug(std::string str, SickKoala *patient) {
    SickKoala real_patient = *patient;
    real_patient.takeDrug(str);
}

std::string KoalaNurse::readReport(std::string filename) {
    std::ifstream fs;
    std::string drug;
    std::string patient = std::regex_replace (filename, std::regex (".report"),"");

    fs.open(filename);
    if(!fs) {
        std::cerr << filename << ": No such file or directory" << std::endl;
        exit(84);
    }
    std::getline(fs, drug);
    std::cout << "Nurse " << ID << ": Kreog! Mr." << patient << " needs a " << drug << "!" << std::endl;
    return (std::string)drug;
}

int KoalaNurse::getID() {
    return ID;
}