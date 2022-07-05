#include "KoalaNurseList.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *ptr) {
    this->koala = ptr;
    this->next = NULL;
    this->prev = NULL;
}

bool KoalaNurseList::isEnd() {
    if (this->next == NULL)
        return true;
    return false;
}

void KoalaNurseList::append(KoalaNurseList *ptr) {
    KoalaNurseList *node = this->next;

    if (next == NULL) {
        next = ptr;
        return;
    }
    while (node->next != NULL)
        node = node->next;
    node->next = ptr;
    node->next->prev = node;
}

KoalaNurse *KoalaNurseList::getFromID(int ID) {
    KoalaNurseList *node = this->next;

    if (node == NULL) {
        return NULL;
    }
    while (node->next != NULL) {
        if (node->koala->getID() == ID)
            return node->koala;
        node = node->next;
    }
    return NULL;
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *ptr) {
    KoalaNurseList *node = this->next;

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

KoalaNurseList *KoalaNurseList::removeFromID(int ID) {
        KoalaNurseList *node = this->next;

    if (node == NULL) {
        return NULL;
    }
    while (node->next != NULL) {
        if (node->next->koala->getID() == ID) {
            node->next = node->next->next;
            node->next->prev = node;
        }
    }
    while (node->prev != NULL)
        node = node->prev;
    return node;
}

KoalaNurse *KoalaNurseList::getContent() {
    return this->koala;
}

KoalaNurseList *KoalaNurseList::getNext() {
    return this->next;
}

void KoalaNurseList::dump() {
    KoalaNurseList *node = this->next;

    std::cout << "Nurses:";
    while (node->next != NULL) {
        if (node->koala == NULL)
            std::cout << " [nullptr]";
        else
            std::cout << " " << node->koala->getID();
        node = node->next;
    }
    std::cout << "." << std::endl;
}