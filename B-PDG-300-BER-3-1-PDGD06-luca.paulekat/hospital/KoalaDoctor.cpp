#include "KoalaDoctor.hpp"

void KoalaDoctor::timeCheck() {
    if (working == 0) {
        std::cout << "Dr." << name << ": Time to get to work!" << std::endl;
        working = 1;
    } else if (working == 1) {
        std::cout << "Dr." << name << ": Time to go home to my eucalyptus forest!" << std::endl;
    } else {
        ;
    }
}

void KoalaDoctor::diagnose(SickKoala *patient) {
    SickKoala real_patient = *patient;
    std::vector<std::string> drugs = {"Mars", "Kinder", "Crunch", "Maroilles", "Eucalyptus Leaf"};
    std::string drug;
    std::string patient_name = real_patient.getName();
    std::string report_name_str = patient_name.append(".report");
    char report_name[report_name_str.size()];
    std::ifstream fs;

    strcpy(report_name, report_name_str.c_str());
    std::cout << "Dr." << name << ": So what \'s goerking you Mr." << patient_name << "?" << std::endl;
    real_patient.poke();
    drug = drugs[rand()%5 - 1];
    fs.open(report_name);
    if (fs)
        remove(report_name);
    std::ofstream report (report_name);
    report << drug <<std::endl;
    fs.close();
}

std::string KoalaDoctor::getName() {
    return name;
}