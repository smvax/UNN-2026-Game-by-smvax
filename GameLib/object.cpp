#include "object.h"
#include <stdexcept>

Object::Object(int x, int y, std::string color, char symbol) {
    if (x < 0 || x > MAP_MAX_X || y < 0 || y > MAP_MAX_Y)
        throw std::logic_error("Object position out of map");
    _x = x;
    _y = y;
    _color = color;
    _symbol = symbol;
}

Object::Object(const Object& other) {
    _x = other._x;
    _y = other._y;
    _color = other._color;
    _symbol = other._symbol;
}

bool Object::move_right() noexcept {
    if (_x < MAP_MAX_X) { _x++; return true; } 
    return false;
}

bool Object::move_left() noexcept {
    if (_x > 0) { _x--; return true; }
    return false;
}

bool Object::move_up() noexcept {
    if (_y > 0) { _y--; return true; }
    return false;
}

bool Object::move_down() noexcept {
    if (_y < MAP_MAX_Y) { _y++; return true; }
    return false;
}

bool Object::do_manual_move() noexcept {
    if (GetAsyncKeyState(KEY_W) & IS_KEY_PRESSED) return move_up();
    if (GetAsyncKeyState(KEY_S) & IS_KEY_PRESSED) return move_down();
    if (GetAsyncKeyState(KEY_A) & IS_KEY_PRESSED) return move_left();
    if (GetAsyncKeyState(KEY_D) & IS_KEY_PRESSED) return move_right();
    return false;
}

void Object::do_rand_move() noexcept {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dir(1, 4);

    int attempts = 0;
    while (attempts < 10) {  // ограничиваем попытки
        int d = dir(gen);
        bool moved = false;
        if (d == 1) moved = move_up();
        else if (d == 2) moved = move_left();
        else if (d == 3) moved = move_down();
        else if (d == 4) moved = move_right();

        if (moved) break;
        attempts++;
    }
}