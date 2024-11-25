#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <vector>
#include <memory>
#include "link.h"
#include "ability.h"

using namespace std;

class Player {
    int playerID;
    int downloadedData;
    int downloadedViruses;
    vector<unique_ptr<Link>> links;
    vector<unique_ptr<Ability>> abilities;
    public:
        // getters
        int getPlayerID() const;
        int getDownloadedData() const;
        int getDownloadedViruses() const;
        Link &getLink(int LinkID) const;
        Ability &getAbility(int AbilityID) const;
        int getAbilitiesCount() const;

        Player(int playerID, int downloadedData, int downloadedViruses);
        
        void addLink(unique_ptr<Link> link);
        void addAbility(unique_ptr<Ability> ability);
        void useAbility(int abilityID, Link targetLink);
        void useAbility(int abilityID, Cell targetCell);
        
};

#endif
