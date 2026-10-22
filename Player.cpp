#include "Player.h"
using namespace std;

void Player::Create(unique_ptr<NPC> character) {
    currentCharacter = std::move(character);
    currentCharacter->Create();
}

unique_ptr<NPC> Player::GetCharacter() {
    return std::move(currentCharacter);
}

void Player::GetInfo() {
    currentCharacter->GetInfo();
}
