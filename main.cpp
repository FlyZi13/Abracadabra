#include "Evil.h"
#include "NPC.h"
#include "Paladin.h"
#include "Player.h"
#include "Warrior.h"
#include "Wizard.h"
#include <iostream>
#include <memory>

// enum class хранит ограниченный набор типизированных значений.
// В отличие от обычного enum значения не преобразуются в int автоматически.

enum class CharacterType {
    Warrior = 1,
    Wizard,
    Paladin
};

enum class WeaponQuality {
    Common = 1,
    Uncommon,
    Rare,
    Epic,
    Legendary
};

// Ключевые понятия принципы ООП:
// 1) Наследование
// 2) Полиморфизм
// 3) Абстракция
// 4) Инкапсуляция (геттер и сеттер)

// Модификаторы доступа:
// public - публичный (Доступен внутри класса, внутри наследника и в основном потоке программы)
// protected - защищенный (Можно изменять в исходном классе и в наследнике)
// private - приватный (Доступен только в исходном классе) (Не наследуется)

using namespace std;

int main() {
    // Warrior *warrior1 = new Warrior("Друг война", 5); // как только создался экземпляр класса, сразу вызвался
    // конструктор по умолчанию warrior1->GetInfo();     // строка работает с указателями
    // // delete warrior1;                               // удаляем экземпляр класса, вызывается деструктор
    // // warrior1 = nullptr;
    // cout << endl;
    // Wizard wizard1();
    Player player;
    cout << "Присядь путник у костра и расскажи кто ты\n";
    cout << "\t1 - воин\n\t2 - маг \n\t3 - паладин\n";

    int characterChoice = 0;
    cin >> characterChoice;


    if (characterChoice < static_cast<int>(CharacterType::Warrior) ||
        characterChoice > static_cast<int>(CharacterType::Paladin)) {
        cout << "Таких героев еще не было в наших краях. Возвращайся позже!\n";
        return 0;
    }

    const auto characterType = static_cast<CharacterType>(characterChoice);
    switch (characterType) {
        case CharacterType::Warrior:
            player.Create(make_unique<Warrior>());
            break;
        case CharacterType::Wizard:
            player.Create(make_unique<Wizard>());
            break;
        case CharacterType::Paladin:
            player.Create(make_unique<Paladin>());
            break;
    }

    cout << "Выбери качество оружия:\n"
         << "\t1 - обычное\n\t2 - необычное\n\t3 - редкое\n"
         << "\t4 - эпическое\n\t5 - легендарное\n"
         << "Твой выбор: ";
    int weaponChoice = 0;
    cin >> weaponChoice;

    if (weaponChoice < static_cast<int>(WeaponQuality::Common) ||
        weaponChoice > static_cast<int>(WeaponQuality::Legendary)) {
        cout << "Такого качества оружия не существует.\n";
        return 0;
    }

    const auto weaponQuality = static_cast<WeaponQuality>(weaponChoice);
    cout << "Числовое значение качества оружия: "
         << static_cast<int>(weaponQuality) << "\n";

    takeDamage(player.GetCharacter(), 5);

    // vector<unique_ptr<Evil>> evils;
    //
    // evils.push_back(make_unique<Evil>());
    // evils.push_back(make_unique<Evil>());
    // evils.push_back(make_unique<Evil>("Кабанчик"));
    // evils.push_back(make_unique<Evil>("Гнолл", 12));
    // evils.push_back(make_unique<Evil>("Гнолл дробитель", 15, 20));
    // evils.push_back(make_unique<Evil>("Дракон", 50, 100, 200));
    //
    // for (const auto &evil : evils)
    // {
    //     evil->GetInfo();
    //     cout << endl;
    // }

    return 0;
}
