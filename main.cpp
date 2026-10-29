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
    cout << "Присядь, путник, у костра и расскажи, кто ты:\n\n";
    cout << "\t1 - Воин   — мастер ближнего боя, сильный и выносливый.\n";
    cout << "\t2 - Маг    — повелитель заклинаний с высоким интеллектом.\n";
    cout << "\t3 - Паладин — защитник, сочетающий силу и магию.\n\n";
    cout << "Твой выбор: ";

    int characterChoice = 0;
    cin >> characterChoice;


    CharacterType characterType;
    characterType = static_cast<CharacterType>(characterChoice);
    switch (characterType) {
        case CharacterType::Warrior:
            cout << "\nТы выбрал Воина — сталь и отвага станут твоей опорой.\n";
            player.Create(make_unique<Warrior>());
            break;
        case CharacterType::Wizard:
            cout << "\nТы выбрал Мага — знания и заклинания будут твоим оружием.\n";
            player.Create(make_unique<Wizard>());
            break;
        case CharacterType::Paladin:
            cout << "\nТы выбрал Паладина — твой путь объединяет меч и магию.\n";
            player.Create(make_unique<Paladin>());
            break;
        default:
            cout << "Такого героя нет. Возвращайся позже!\n";
            return 0;
    }

    cout << "\nВыбери качество оружия:\n\n"
         << "\t1 - Обычное\n\t2 - Необычное\n\t3 - Редкое\n"
         << "\t4 - Эпическое\n\t5 - Легендарное\n\n"
         << "Твой выбор: ";
    int weaponChoice = 0;
    cin >> weaponChoice;

    if (weaponChoice < static_cast<int>(WeaponQuality::Common) ||
        weaponChoice > static_cast<int>(WeaponQuality::Legendary)) {
        cout << "Такого качества оружия не существует.\n";
        return 0;
    }

    WeaponQuality weaponQuality = static_cast<WeaponQuality>(weaponChoice);

    cout << "\nСвойства выбранного оружия:\n";

    switch (weaponQuality) {
        case WeaponQuality::Common:
            cout << "Обычное — надёжное оружие без дополнительных улучшений.\n";
            break;
        case WeaponQuality::Uncommon:
            cout << "Необычное — +2 к урону и +1 к защите.\n";
            break;
        case WeaponQuality::Rare:
            cout << "Редкое — +5 к урону, +3 к защите и +5% к шансу критического удара.\n";
            break;
        case WeaponQuality::Epic:
            cout << "Эпическое — +10 к урону, +6 к защите и +10% к шансу критического удара.\n";
            break;
        case WeaponQuality::Legendary:
            cout << "Легендарное — +20 к урону, +10 к защите и +15% к шансу критического удара.\n";
            break;
    }

    // Для enum class числовой индекс получают явным преобразованием static_cast.
    cout << "Индекс персонажа: " << static_cast<int>(characterType) << "\n";
    cout << "Индекс качества оружия: " << static_cast<int>(weaponQuality) << "\n";

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
