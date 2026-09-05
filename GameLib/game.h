#pragma once
#include <thread>
#include <atomic>
#include "player.h"

class Game {
private:
    Player _user;
    Player _computer;
    std::atomic<bool> is_running;

    bool positions_equal() const noexcept;
    void user_move();
    void computer_move();
    void user_fight();
    void computer_fight();
    void print_field() const;
    void print_fight() const;

public:
    Game();
    ~Game();
    void start();
};