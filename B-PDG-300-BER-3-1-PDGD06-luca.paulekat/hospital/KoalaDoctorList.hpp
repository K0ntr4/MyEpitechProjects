#ifndef KoalaDoctorList_hpp_
    #define KoalaDoctorList_hpp_

#include <string>
#include <iostream>
#include <regex>
#include "KoalaDoctor.hpp"

class KoalaDoctorList{
    KoalaDoctor *doctor;
    KoalaDoctorList *next;
    KoalaDoctorList *prev;
    public:
        KoalaDoctorList(KoalaDoctor *ptr);
        ~KoalaDoctorList();
        bool isEnd();
        void append(KoalaDoctorList *ptr);
        KoalaDoctor *getFromName(std::string);
        KoalaDoctorList *remove(KoalaDoctorList *ptr);
        KoalaDoctorList *removeFromName(std::string str);
        KoalaDoctor *getContent();
        KoalaDoctorList *getNext();
        void dump();
};

#endif