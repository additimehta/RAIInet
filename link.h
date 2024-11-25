#include <string>
#include <vector>
#include <memory>
#include "player.h"

using namespace std;

class Link {
    String type;
    int strength;
    bool isRevealed;
    Player owner;

    public:
        //getters
        int getStrength() const;
        bool getIsRevealed() const;
        Player getOwner() const;
        String getType() const;

        Link(String type, int strength, bool isRevealed, Player owner);
        bool operator==(const Link& other) const;

        void setIsRevealed(bool isRevealed);
        void setStrength(int strength);

        Link battle(Link opponent) const;
}

