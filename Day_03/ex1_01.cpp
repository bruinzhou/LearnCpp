#include <iostream>
#include <cstdlib>
#include <ctime>

class Player {
private:
    std::string name;
    int health;
    int attack;

public:
    Player(const std::string& playerName, int initialHealth, int attackPower)
        : name(playerName), health(initialHealth), attack(attackPower) {}

    bool isAlive() const {
        return health > 0;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) {
            health = 0;
        }
    }

    int getAttackPower() const {
        return attack;
    }

    std::string getName() const {
        return name;
    }

    void displayStatus() const {
        std::cout << name << " - Health: " << health << " Attack: " << attack << "\n";
    }
};

class BattleGame {
private:
    Player player1;
    Player player2;

public:
    BattleGame(const Player& p1, const Player& p2) : player1(p1), player2(p2) {}

    void start() {
        while (player1.isAlive() && player2.isAlive()) {
            displayGameStatus();
            performRound();
        }

        displayGameResult();
    }

private:
    void performRound() {
        int attack1 = player1.getAttackPower();
        int attack2 = player2.getAttackPower();

        player2.takeDamage(attack1);
        player1.takeDamage(attack2);

        std::cout << player1.getName() << " attacks " << player2.getName() << " for " << attack1 << " damage.\n";
        std::cout << player2.getName() << " attacks " << player1.getName() << " for " << attack2 << " damage.\n";
    }

    void displayGameStatus() const {
        std::cout << "\n---- Battle Status ----\n";
        player1.displayStatus();
        player2.displayStatus();
        std::cout << "------------------------\n\n";
    }

    void displayGameResult() const {
        std::cout << "---- Game Over ----\n";
        if (!player1.isAlive()) {
            std::cout << player2.getName() << " wins!\n";
        } else {
            std::cout << player1.getName() << " wins!\n";
        }
    }
};

int main() {
    // 设置随机数种子
    std::srand(std::time(0));

    // 创建两个玩家
    Player player1("Player 1", 100, 15);
    Player player2("Player 2", 100, 12);

    // 创建对战游戏实例
    BattleGame game(player1, player2);

    // 开始游戏
    game.start();

    return 0;
}
