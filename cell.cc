#include "cell.h"

using namespace std;

//Cell::Cell(Link *link, bool isServerPort): link{link}, isServerPort{isServerPort} {}
Cell::Cell(): link{nullptr}, isServerPort{false}, owner{' '}, underneathLetter{'.'}, isFirewall{false}, isAmplifier{false} {}

void Cell::placeLink(Link *link) {
    this->link = link;
    this->owner = link->getLetter();
}
void Cell::removeLink() {
    this->link = nullptr;
    this->owner = ' ';
}

void Cell::setIsServerPort(bool c) {
    this->isServerPort = c;
}

Link *Cell::getLink() const {
    return link;
}
bool Cell::getIsServerPort() const {
    return isServerPort;
}

char Cell::getOwner() const {
    return owner;
}
