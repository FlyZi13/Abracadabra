#ifndef ABRACADABRA_PALADIN_H
#define ABRACADABRA_PALADIN_H

#include "Warrior.h"
#include "Wizard.h"

class Paladin : public Warrior, public Wizard {
public:
    Paladin();

    void Create() override;
    void GetInfo() override;

    ~Paladin() override;
};

#endif //ABRACADABRA_PALADIN_H
