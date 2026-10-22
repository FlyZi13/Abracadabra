#ifndef ABRACADABRA_WARRIOR_H
#define ABRACADABRA_WARRIOR_H

#include "NPC.h"
#include "Weapon.h"
#include <string>
#include <vector>

class Warrior : virtual public NPC {
protected:
    short strenght {21};
    std::vector<Weapon> weapons;

public:
    Warrior();
    Warrior(std::string name, unsigned int lvl = 1);

    void Create() override;
    void GetInfo() override;
    void GetWeapon();
    void Recalculate();

    ~Warrior() override;
};

#endif //ABRACADABRA_WARRIOR_H
