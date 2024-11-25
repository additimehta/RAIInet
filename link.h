#ifndef _LINK_H_
#define _LINK_H_

#include <string>
#include <vector>
#include <memory>
#include "player.h"

using namespace std;

class Link {
    string type;
    int strength;
    bool isRevealed;
    Player owner;

    public:
        //getters
        int getStrength() const;
        bool getIsRevealed() const;
        Player getOwner() const;
        string getType() const;

        Link(string type, int strength, bool isRevealed, Player owner);
        bool operator==(const Link& other) const;

        void setIsRevealed(bool isRevealed);
        void setStrength(int strength);

        Link battle(Link opponent) const;
};

#endif
