//
// Created by FlyZi on 16.10.2026.
//

#ifndef ABRACADABRA_EVIL_H
#define ABRACADABRA_EVIL_H

#include "NPC.h"

#include <string>

class Evil : public NPC {
public:
    Evil();
    explicit Evil(std::string name);
    Evil(std::string name, unsigned int damage);
    Evil(std::string name, unsigned int damage, unsigned int health);
    Evil(std::string name, unsigned int damage, unsigned int health, unsigned int armor);

    ~Evil() override;
};

#endif //ABRACADABRA_EVIL_H
