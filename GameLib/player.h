#pragma once
#include "characters.h"

class Player {
private:
    Character* _character;

public:
    Player(Character* ch = nullptr);
    ~Player();

    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    Player(Player&& other) noexcept;
    Player& operator=(Player&& other) noexcept;

    Character* character() const noexcept { return _character; }
    int x() const noexcept {
        return _character->x();
    }
    int y() const noexcept {
        return _character->y();
    }

    bool input_to_move() noexcept;
    void do_rand() noexcept;
};