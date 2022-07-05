#include "KoalaDoctorList.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *ptr) {
    this->doctor = ptr;
    this->next = NULL;
    this->prev = NULL;
}

bool KoalaDoctorList::isEnd() {
    if (this->next == NULL)
        return true;
    return false;
}

void KoalaDoctorList::append(KoalaDoctorList *ptr) {
    KoalaDoctorList *node = this->next;

    if (next == NULL) {
        next = ptr;
        return;
    }
    while (node->next != NULL)
        node = node->next;
    node->next = ptr;
    node->next->prev = node;
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string str) {
    KoalaDoctorList *node = this->next;

    if (node == NULL) {
        return NULL;
    }
    while (node->next != NULL) {
        if (node->doctor->getName() == str)
            return node->doctor;
        node = node->next;
    }
    return NULL;
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *ptr) {
    KoalaDoctorList *node = this->next;

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

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string str) {
        KoalaDoctorList *node = this->next;

    if (node == NULL) {
        return NULL;
    }
    while (node->next != NULL) {
        if (node->next->doctor->getName() == str) {
            node->next = node->next->next;
            node->next->prev = node;
        }
    }
    while (node->prev != NULL)
        node = node->prev;
    return node;
}

KoalaDoctor *KoalaDoctorList::getContent() {
    return this->doctor;
}

KoalaDoctorList *KoalaDoctorList::getNext() {
    return this->next;
}

void KoalaDoctorList::dump() {
    KoalaDoctorList *node = this->next;

    std::cout << "Doctors:";
    while (node->next != NULL) {
        if (node->doctor == NULL)
            std::cout << " [nullptr]";
        else
            std::cout << " " << node->doctor->getName();
        node = node->next;
    }
    std::cout << "." << std::endl;
}