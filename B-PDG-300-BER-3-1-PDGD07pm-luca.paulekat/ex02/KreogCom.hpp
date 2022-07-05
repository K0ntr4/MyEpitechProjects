#ifndef KreogCom_hpp_
    #define KreogCom_hpp_

#include <string>
#include <iostream>

class KreogCom
{
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom ();
        void addCom(int x, int y, int serial);
        void removeCom ();
        KreogCom *getCom ();
        void ping();
        void locateSquad ();
    private:
        const int m_serial;
        int _x;
        int _y;
        KreogCom *next;
};

#endif