#include "game.h"
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <chrono>

Game::Game() : is_running(true) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    std::cout << "Choose your class:\n";
    std::cout << "1. Warrior (high HP, armour)\n";
    std::cout << "2. Archer (high fire rate)\n";
    std::cout << "3. Wizard (magic degree)\n";
    int choice;
    std::cin >> choice;
    while (choice < 1 || choice > 3) {
        std::cout << "Invalid choice, try again: ";
        std::cin >> choice;
    }

    Character* userChar = nullptr;
    Character* compChar = nullptr;

    if (choice == 1) {
        userChar = new Warrior(0, 0, COLOR_GREEN, '@', 120, 15, 10);
        compChar = new Warrior(MAP_MAX_X, MAP_MAX_Y, COLOR_RED, '#', 120, 15, 10);
    }
    else if (choice == 2) {
        userChar = new Archer(0, 0, COLOR_YELLOW, '@', 90, 12, 3);
        compChar = new Archer(MAP_MAX_X, MAP_MAX_Y, COLOR_RED, '#', 90, 12, 3);
    }
    else {
        userChar = new Wizard(0, 0, COLOR_WHITE, '@', 80, 18, 2);
        compChar = new Wizard(MAP_MAX_X, MAP_MAX_Y, COLOR_RED, '#', 80, 18, 2);
    }

    _user = std::move(Player(userChar));
    _computer = std::move(Player(compChar));
}

Game::~Game() {}

bool Game::positions_equal() const noexcept {
    return (_user.x() == _computer.x() && _user.y() == _computer.y());
}

void Game::user_move() {
    auto last_move_time = std::chrono::high_resolution_clock::now();
    while (is_running) {
        auto now = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_move_time).count();
        if (elapsed > MOVE_USER_DELAY_MS) {
            if (_user.input_to_move()) last_move_time = now;
        }
        if (positions_equal()) {
            is_running = false;
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_MS));
    }
}

void Game::computer_move() {
    while (is_running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(MOVE_COMPUTER_DELAY_MS));
        _computer.do_rand();
        if (positions_equal()) {
            is_running = false;
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(MOVE_COMPUTER_DELAY_MS));
    }
}

void Game::user_fight() {
    while (is_running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(ATTACKS_DELAY));
        _user.character()->attack(*_computer.character());
        if (!_computer.character()->getAlive() || !_user.character()->getAlive()) {
            is_running = false;
            break;
        }
    }
}

void Game::computer_fight() {
    while (is_running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(ATTACKS_DELAY));
        _computer.character()->attack(*_user.character());
        if (!_user.character()->getAlive() || !_computer.character()->getAlive()) {
            is_running = false;
            break;
        }
    }
}

void Game::print_field() const {
    for (int y = 0; y <= MAP_MAX_Y; ++y) {
        for (int x = 0; x <= MAP_MAX_X; ++x) {
            if (x == _user.x() && y == _user.y()) {
                std::cout << _user.character()->color() << '@' << COLOR_RESET << " ";
            }
            else if (x == _computer.x() && y == _computer.y()) {
                std::cout << _computer.character()->color() << '#' << COLOR_RESET << " ";
            }
            else {
                std::cout << ". ";
            }
        }
        std::cout << '\n';
    }
    std::cout << "\nMove with W/A/S/D. Reach the enemy to start combat!\n";
    std::cout << "User: (" << _user.x() << ", " << _user.y() << ") ";
    std::cout << "Computer: (" << _computer.x() << ", " << _computer.y() << ")\n";
}

void Game::print_fight() const {
    std::cout << "=== COMBAT ===\n";
    std::cout << "You:  HP = " << _user.character()->getHealth()
        << "  Power = " << _user.character()->getPower() << "\n";
    std::cout << "Enemy: HP = " << _computer.character()->getHealth()
        << "  Power = " << _computer.character()->getPower() << "\n";
    std::cout << "Fighting until one dies...\n";
}

void Game::start() {
    std::cout << "Move your character to meet the enemy (red '#')\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    is_running = true;
    std::thread userMoveThread(&Game::user_move, this);
    std::thread compMoveThread(&Game::computer_move, this);

    while (is_running) {
        system("cls");
        print_field();
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
    userMoveThread.join();
    compMoveThread.join();

    system("cls");
    std::cout << "You met the enemy! Fight begins!\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    is_running = true;
    std::thread userFightThread(&Game::user_fight, this);
    std::thread compFightThread(&Game::computer_fight, this);

    while (is_running) {
        system("cls");
        print_fight();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    userFightThread.join();
    compFightThread.join();

    system("cls");
    if (_user.character()->getAlive() && !_computer.character()->getAlive())
        std::cout << "You won!\n";
    else if (!_user.character()->getAlive() && _computer.character()->getAlive())
        std::cout << "You lost...\n";
    else
        std::cout << "Both died!\n";

    std::cout << "Game over.\n";
}