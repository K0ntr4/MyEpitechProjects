#ifndef KoalaNurseList_hpp_
    #define KoalaNurseList_hpp_

#include <string>
#include <iostream>
#include <regex>
#include "KoalaNurse.hpp"

class KoalaNurseList{
    KoalaNurse *koala;
    KoalaNurseList *next;
    KoalaNurseList *prev;
    public:
        KoalaNurseList(KoalaNurse *ptr);
        ~KoalaNurseList();
        bool isEnd();
        void append(KoalaNurseList *ptr);
        KoalaNurse *getFromID(int ID);
        KoalaNurseList *remove(KoalaNurseList *ptr);
        KoalaNurseList *removeFromID(int ID);
        KoalaNurse *getContent();
        KoalaNurseList *getNext();
        void dump();
};

#endif