#ifndef _LINK_H_
#define _LINK_H_

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Player;

class Link {
    string type;
    int strength;
    bool isRevealed;
    Player *owner;
    char letter;

    int abilityStatus; // one is default, two is linkboost, three is zigzag

    public:
        //getters
        int getStrength() const;
        bool getIsRevealed() const;
        Player *getOwner() const;
        string getType() const;
        char getLetter() const;
        int getAbilityStatus() const;

        Link(string type, int strength, bool isRevealed, Player *owner, char letter);
        bool operator==(const Link& other) const;

        void setIsRevealed(bool isRevealed);
        void setStrength(int strength);
        void setType(string type);
        void setAbilityStatus(int status);

};

#endif
