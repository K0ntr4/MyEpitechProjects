#ifndef SickKoalaList_hpp_
    #define SickKoalaList_hpp_

#include <string>
#include <iostream>
#include <regex>
#include "SickKoala.hpp"

class SickKoalaList{
    SickKoala *koala;
    SickKoalaList *next;
    SickKoalaList *prev;
    public:
        SickKoalaList(SickKoala *ptr);
        ~SickKoalaList();
        bool isEnd();
        void append(SickKoalaList *ptr);
        SickKoala *getFromName(std::string str);
        SickKoalaList *remove(SickKoalaList *ptr);
        SickKoalaList *removeFromName(std::string str);
        SickKoala *getContent();
        SickKoalaList *getNext();
        void dump();
};

#endif