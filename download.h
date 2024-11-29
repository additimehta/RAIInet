#ifndef _DOWNLOAD_H_
#define _DOWNLOAD_H_

#include "ability.h"
#include <iostream>

class Download: public Ability {
    public:
        Download(Player* player);
        bool use(Link &targetLink) override;
        bool use(Cell &targetCell) override;
        std::string getName() const override;
        
};

#endif
