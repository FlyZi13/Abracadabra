#ifndef ABRACADABRA_PLAYER_H
#define ABRACADABRA_PLAYER_H

#include "NPC.h"

#include <memory>

class Player {
private:
    std::unique_ptr<NPC> currentCharacter {nullptr};

public:
    void Create(std::unique_ptr<NPC> character);
    std::unique_ptr<NPC> GetCharacter();
    void GetInfo();
};

#endif //ABRACADABRA_PLAYER_H
