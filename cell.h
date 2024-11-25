#include <memory>
#include "link.h"

using namespace std;


class Cell {
    Link link;
    bool isServerPort;

    public:
        //getters
        Link getLink() const;
        bool getIsServerPort() const;

        void placeLink(Link link);
        void removeLink();

        Cell(Link link, bool isServerPort);
        Cell();
}