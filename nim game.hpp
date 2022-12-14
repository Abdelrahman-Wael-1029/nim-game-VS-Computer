#ifndef UNTITLED_NIM_GAME_HPP
#define UNTITLED_NIM_GAME_HPP

#include <iostream>
#include<string>
#include <bits/stdc++.h>

using namespace std;

class Variant_one {
    int number_coins;
public:
    int &total_number();

    bool is_winner(int number);

    Variant_one();
};

class Variant_two {
    int piles[3]{};
public:
    int total_number();

    bool is_lose();

    int &operator[](int);

    Variant_two();
};

class player_Variant_one {
protected:

    int number_coin{};

    string name;
public:
    player_Variant_one();

    int &get_number();

    explicit player_Variant_one(string str);

    string get_name();

    virtual void getmove(int &num);
};

class player_Variant_two {
protected:
    string name;
public:
    player_Variant_two();

    explicit player_Variant_two(string name);

    string get_name();

    virtual void getmove(int &index, int &num);

};

class computer_player_Variant_one : public player_Variant_one {
    Variant_one &game_computer;
public:
    [[maybe_unused]] explicit computer_player_Variant_one(Variant_one &game);

    void getmove(int &num) override;

    int minimax(Variant_one game, bool mx, int number);
};

class computer_player_Variant_two : public player_Variant_two {
    Variant_two &game_computer;
    int dp[10][10][10][2];


public:
    explicit computer_player_Variant_two(Variant_two &game);

    void getmove(int &index, int &num) override;

    int minimax(Variant_two game, bool mx);
};

#endif //UNTITLED_NIM_GAME_HPP
