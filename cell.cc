#include "cell.h"

using namespace std;

Cell::Cell(Link *link, bool isServerPort): link{link}, isServerPort{isServerPort} {}
Cell::Cell(): link{nullptr}, isServerPort{false} {}

void Cell::placeLink(Link *link) {
    this->link = link;
}
void Cell::removeLink() {
    this->link = nullptr;
}

Link *Cell::getLink() const {
    return link;
}
bool Cell::getIsServerPort() const {
    return isServerPort;
}
