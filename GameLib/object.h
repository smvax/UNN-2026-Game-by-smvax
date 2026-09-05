#pragma once
#include <string>
#include <random>
#include <windows.h>
#include "constants.h"

class Object {
protected:
    int _x, _y;
    std::string _color;
    char _symbol;

public:
    Object(int x = 0, int y = 0, std::string color = COLOR_WHITE, char symbol = 'z');
    Object(const Object& other);

    int x() const noexcept {
        return _x;
    }
    int y() const noexcept {
        return _y;
    }
    char symbol() const noexcept {
        return _symbol;
    }
    std::string color() const noexcept {
        return _color;
    }

    bool move_right() noexcept;
    bool move_left() noexcept;
    bool move_up() noexcept;
    bool move_down() noexcept;

    bool do_manual_move() noexcept;
    void do_rand_move() noexcept;
};