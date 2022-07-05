#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *ptr) {
    this->koala = ptr;
    this->next = NULL;
    this->prev = NULL;
}

bool SickKoalaList::isEnd() {
    if (this->next == NULL)
        return true;
    return false;
}

void SickKoalaList::append(SickKoalaList *ptr) {
    SickKoalaList *node = this->next;

    if (next == NULL) {
        next = ptr;
        return;
    }
    while (node->next != NULL)
        node = node->next;
    node->next = ptr;
    node->next->prev = node;
}

SickKoala *SickKoalaList::getFromName(std::string str) {
    SickKoalaList *node = this->next;

    if (node == NULL) {
        return NULL;
    }
    while (node->next != NULL) {
        if (node->koala->getName() == str)
            return node->koala;
        node = node->next;
    }
    return NULL;
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *ptr) {
    SickKoalaList *node = this->next;

    if (node == NULL) {
        return NULL;
    }
    while (node->next != NULL) {
        if (node->next == ptr) {
            node->next = node->next->next;
            node->next->prev = node;
        }
    }
    while (node->prev != NULL)
        node = node->prev;
    return node;
}

SickKoalaList *SickKoalaList::removeFromName(std::string str) {
        SickKoalaList *node = this->next;

    if (node == NULL) {
        return NULL;
    }
    while (node->next != NULL) {
        if (node->next->koala->getName() == str) {
            node->next = node->next->next;
            node->next->prev = node;
        }
    }
    while (node->prev != NULL)
        node = node->prev;
    return node;
}

SickKoala *SickKoalaList::getContent() {
    return this->koala;
}

SickKoalaList *SickKoalaList::getNext() {
    return this->next;
}

void SickKoalaList::dump() {
    SickKoalaList *node = this->next;

    std::cout << "Patients:";
    while (node->next != NULL) {
        if (node->koala == NULL)
            std::cout << " [nullptr]";
        else
            std::cout << " " << node->koala->getName();
        node = node->next;
    }
    std::cout << "." << std::endl;
}