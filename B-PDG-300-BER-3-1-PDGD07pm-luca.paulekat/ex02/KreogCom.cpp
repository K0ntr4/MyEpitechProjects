#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial) : m_serial(serial) {
    this->_x = x;
    this->_y = y;

    std::cout << "KreogCom " << this->m_serial << " initialized" <<std::endl;
}

KreogCom::~KreogCom () {
    std::cout << "KreogCom " << this->m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial) {
    KreogCom *kreog = new KreogCom (x, y, serial);

    if (this->next == NULL) {
        this->next = kreog;
    } else {
        kreog->next = this->next;
        this->next = kreog;
    }
}

KreogCom *KreogCom::getCom () {
    return this->next;
}

void KreogCom::removeCom () {
    KreogCom *cpy = NULL;

    if (this->next == NULL)
        return;
    if (this->next->next != NULL)
        cpy = this->next->next;
    this->next->~KreogCom();
    this->next = cpy;
}

void KreogCom::ping() {
    std::cout << "KreogCom " << this->m_serial << " currently at " << this->_x << " " << this->_y << std::endl;
}

void KreogCom::locateSquad () {
    KreogCom *n = this->next;

    while (n != NULL) {
        n->ping();
        n = n->next;
    }
    this->ping();
}