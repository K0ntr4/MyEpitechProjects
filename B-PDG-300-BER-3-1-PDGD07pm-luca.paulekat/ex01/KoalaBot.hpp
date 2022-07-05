#ifndef Federation_hpp_
    #define Federation_hpp_

#include "Parts.hpp"
#include <string>

class KoalaBot
{
    std::string _serial = "Bob-01";
    public:
        KoalaBot(std::string serial = "Bob-01");
        ~KoalaBot();
        class Arms _arms;
        class Legs _legs;
        class Head _head;
        void setParts(const Arms &ptr);
        void setParts(const Legs &ptr);
        void setParts(const Head &ptr);
        Arms& swapParts(const Arms &ptr);
        Legs& swapParts(const Legs &ptr);
        Head& swapParts(const Head &ptr);
        void informations() const;
        bool status() const;
};

#endif