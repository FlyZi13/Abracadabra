cmake_minimum_required(VERSION 4.1)
project(Abracadabra)

set(CMAKE_CXX_STANDARD 20)

add_executable(Abracadabra main.cpp
        Evil.cpp
        Evil.h
        Paladin.cpp
        Paladin.h
        Player.cpp
        Player.h
        Spell.cpp
        Spell.h
        Warrior.cpp
        Warrior.h
        Weapon.cpp
        Weapon.h
        Wizard.cpp
        Wizard.h
        NPC.cpp
        NPC.h
)
