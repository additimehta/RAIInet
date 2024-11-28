#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <vector>
#include <memory>
#include "link.h"
#include "cell.h"
#include "ability.h"
#include "polarize.h"
#include "linkboost.cc"
#include "firewall.h"
#include "download.h"
#include "zigzag.h"
#include "scan.h"
#include "amplifier.h"
#include "warpshift.h"

#include "board.h"

using namespace std;


class Player {
    int playerID;
    int downloadedData;
    int downloadedViruses;
    vector<unique_ptr<Link>> links;
    vector<unique_ptr<Ability>> abilities;
    Board *board;

    public:
        // getters
        int getPlayerID() const;
        int getDownloadedData() const;
        int getDownloadedViruses() const;
        Link *getLink(int LinkID) const;
        Ability *getAbility(int AbilityID) const;
        int getAbilitiesCount() const;
        Board *getBoard() const;
        vector<Link*> getAllLinks() const;

        Player(int playerID, int downloadedData, int downloadedViruses, Board *board);
        
        void addLink(unique_ptr<Link> link);
        void addAbility(unique_ptr<Ability> ability);
        void addAbility(const string &abilitiesstr); // takes the string from input
        void useAbility(int abilityID, Link &targetLink);
        void useAbility(int abilityID, Cell &targetCell);

        void setDownloadedData(int i);
        void setDownloadedViruses(int i);

        void displayAbilities() const;



        
};

#endif
