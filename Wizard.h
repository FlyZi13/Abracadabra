#ifndef ABRACADABRA_WIZARD_H
#define ABRACADABRA_WIZARD_H

#include "NPC.h"
#include "Spell.h"
#include <string>
#include <vector>


class Wizard : virtual public NPC {
protected:
    short intellect {29};
    std::vector<Spell> spells;

public:
    Wizard();
    Wizard(std::string name, unsigned int lvl = 1);

    void Create() override;
    void GetInfo() override;
    void LearnSpell();
    void Recalculate();

    ~Wizard() override;
};

#endif //ABRACADABRA_WIZARD_H
