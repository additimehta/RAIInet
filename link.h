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

    public:
        //getters
        int getStrength() const;
        bool getIsRevealed() const;
        Player *getOwner() const;
        string getType() const;
        char getLetter() const;

        Link(string type, int strength, bool isRevealed, Player *owner, char letter);
        bool operator==(const Link& other) const;

        void setIsRevealed(bool isRevealed);
        void setStrength(int strength);
        void setType(string type);

};

#endif
