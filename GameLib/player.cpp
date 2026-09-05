#include "player.h"

Player::Player(Character* ch) : _character(ch) {}

Player::~Player() {
    delete _character;
}

Player::Player(Player&& other) noexcept : _character(other._character) {
    other._character = nullptr;
}

Player& Player::operator=(Player&& other) noexcept {
    if (this != &other) {
        delete _character;
        _character = other._character;
        other._character = nullptr;
    }
    return *this;
}

bool Player::input_to_move() noexcept {
    return _character->do_manual_move();
}

void Player::do_rand() noexcept {
    _character->do_rand_move();
}