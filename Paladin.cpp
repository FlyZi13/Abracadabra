#include "Paladin.h"

#include <iostream>

using namespace std;

Paladin::Paladin() {
    intellect = 25;
    strenght = 19;
    health = 25;
    damage = 25;
}

void Paladin::Create() {
    cout << "Вы создали Паладина\nЗадайте имя игрока\n";
    cin >> name;

    GetInfo();
    LearnSpell();
    GetWeapon();
}

void Paladin::GetInfo() {
    NPC::GetInfo();
    cout << "Сила: " << strenght << endl;
    cout << "Интеллект: " << intellect << endl;
}

Paladin::~Paladin() {
    cout << name << " отправляется к праотцам\n";
}
