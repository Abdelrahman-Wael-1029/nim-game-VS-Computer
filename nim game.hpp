#ifndef UNTITLED_NIM_GAME_HPP
#define UNTITLED_NIM_GAME_HPP
#include <iostream>
#include<string>
using namespace std;
class player{
protected:
    int number_coin{};
    string name;
public:
    player();
    int &get_number();
    explicit player(string str);
    string get_name();
    virtual void getmove(int &num);
};
class Variant_one{
    int number_coins;
public:
    int &get_nubmer();
    bool is_winner(int number);
    Variant_one();
};
class computer_player:public player{
    Variant_one &game_computer;
public:
    explicit computer_player(Variant_one &game);
    void getmove(int &num) override;
    int minimax(Variant_one game,bool mx,int number);
};




#endif //UNTITLED_NIM_GAME_HPP
