#include "link.h"

using namespace std;


Link::Link(string type, int strength, bool isRevealed, Player *owner):
    type{type}, strength{strength}, isRevealed{isRevealed}, owner{owner} {}

bool Link::operator==(const Link& other) const {
    return this->type == other.type &&
           this->owner == other.owner&&
           this->strength == other.strength;
}

Link Link::battle(const Link &opponent) const {                        // compares strengths || could change this to either ref or return bool true = win false = lose
    if (opponent.getStrength() > this->getStrength()) {
        return opponent;
    }
    return *this;
}


void Link::setIsRevealed(bool isRevealed) {
    this->isRevealed = isRevealed;
}

void Link::setStrength(int strength) {
    this->strength = strength;
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
