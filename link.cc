#include "link.h"

using namespace std;


Link::Link(string type, int strength, bool isRevealed, Player *owner):
    type{type}, strength{strength}, isRevealed{isRevealed}, owner{owner} {}

bool Link::operator==(const Link& other) const {
    return this->type == other.type &&
           this->owner == other.owner&&
           this->strength == other.strength;
}

void Link::setIsRevealed(bool isRevealed) {
    this->isRevealed = isRevealed;
}

void Link::setStrength(int strength) {
    this->strength = strength;
}

void Link::setType(string type) {
    if (type == "Virus" || type == "Data") {
        this->type = type;
    }
}

int Link::getStrength() const {
    return strength;
}

bool Link::getIsRevealed() const {
    return isRevealed;
}

Player *Link::getOwner() const {
    return owner;
}

string Link::getType() const {
    return type;
}
