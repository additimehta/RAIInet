#ifndef _CELL_H_
#define _CELL_H_

#include <memory>
#include "link.h"

using namespace std;

class Cell {
    Link *link;
    bool isServerPort;
    char owner;

    public:
        char underneathLetter;
        bool isFirewall;
        bool isAmplifier;
        //getters
        Link *getLink() const;
        bool getIsServerPort() const;
        char getOwner() const;

        void placeLink(Link *link);
        void removeLink();

        void setIsServerPort(bool c);

       // Cell(Link *link, bool isServerPort, char owner);
        Cell();
};

#endif